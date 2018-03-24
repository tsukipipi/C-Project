#ifndef BRANCHANDBOUND_H_INCLUDED
#define BRANCHANDBOUND_H_INCLUDED

#define INF 65536
#define Max 30

#include <iostream>
#include <fstream>
#include <queue>
#include <stdlib.h>

using namespace std;


struct Node{
    //下界
    int Bount;
    //序号
    int number;
}node;

bool operator<(const Node &a,const Node &b)
{
    if(a.Bount>b.Bount)return true;
    else return false;
}

//优先队列
priority_queue<Node> PQ;


class CostMatrix
{
private:
    //耗费矩阵
    int cost[Max][Max];
    //图中结点数目
    int n;
    //下界
    int bound;
    //每个耗费矩阵相应的编号
    int num;

    //获得左边的耗费矩阵,选择路径row->column,未归约
    void getleftCostMatrix(int row,int column,int road);
    //获得右边的耗费矩阵,不选择路径row->column,未归约
    void getrightCostMatrix(int row,int column);
    //获得归约耗费矩阵
    void reduction(int row,int column,int road);

public:
    //构造函数
    CostMatrix();
    //获得耗费矩阵的初值
    void input();
    //将当前耗费矩阵写入文件中
    void WriteMatrix(fstream &file);
    //从文件中读出指定耗费矩阵
    void ReadMatrix(fstream &file,int Num);
    //分支限界法求解旅行商问题
    void BranchAndBound();
    //输出当前矩阵的值
    void output();

};


#endif // BRANCHANDBOUND_H_INCLUDED

//private function

//获得归约耗费矩阵
void CostMatrix::reduction(int row,int column,int road)
{
    //找出各行各列的最小值
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(cost[i][j]<cost[i][n])cost[i][n]=cost[i][j];
            if(cost[i][j]<cost[n][j])cost[n][j]=cost[i][j];
        }


    //用负数表示此行已经找到路径
    cost[row][n]=-road;
    //用负数表示此列已经找到路径
    cost[n][column]=-road;

    //对行进行归约
    for(int i=0;i<n;i++)
    {
        //确保每行均有0
        if(cost[i][n]>0)
        {
            //下界值增大
            bound=bound+cost[i][n];
            //对相应的列判断最小值是否发生改变
            for(int j=0;j<=n;j++)
            {
                //这一行中的元素相应减去最小值
                cost[i][j]=cost[i][j]-cost[i][n];
                if(cost[i][j]<cost[n][j])cost[n][j]=cost[i][j];
            }
        }
    }


    //对列进行归约
    for(int j=0;j<n;j++)
    {
        //确保每列均有0
        if(cost[n][j]>0)
        {
            //下界值增大
            bound=bound+cost[n][j];
            for(int i=0;i<=n;i++)
            {
                cost[i][j]=cost[i][j]-cost[n][j];
            }
        }
    }
}


//获得左边的耗费矩阵,选择路径row->column,未归约
void CostMatrix::getleftCostMatrix(int row,int column,int road)
{
    //将row行置为无穷大
    for(int j=0;j<n;j++)
        cost[row][j]=INF;
    //将column列置为无穷大
    for(int i=0;i<n;i++)
        cost[i][column]=INF;

    //阻塞路径column->row
    cost[column][row]=INF;

    //重新置各行、列的最小值为无穷大
    for(int i=0;i<n;i++)
    {
        if(cost[i][n]>=0)cost[i][n]=INF;
        if(cost[n][i]>=0)cost[n][i]=INF;
    }

    //找出新的耗费矩阵
    reduction(row,column,road);
}


//获得右边的耗费矩阵,不选择路径row->column,未归约
void CostMatrix::getrightCostMatrix(int row,int column)
{
    //阻塞路径row->column
    cost[row][column]=INF;
    //重新置row行的最小值为无穷大
    cost[row][n]=INF;
    //重新置column列的最小值为无穷大
    cost[n][column]=INF;
    //找出row行新的最小值
    for(int j=0;j<n;j++)
        if(cost[row][j]<cost[row][n])cost[row][n]=cost[row][j];
    //找出column列新的最小值
    for(int i=0;i<n;i++)
        if(cost[i][column]<cost[n][column])cost[n][column]=cost[i][column];
    //找出新的耗费矩阵
    reduction(n,n,0);
}


//public function

//构造函数
CostMatrix::CostMatrix()
{
    bound=0;
    num=0;
}


//获得耗费矩阵的初值
void CostMatrix::input()
{
    cout<<"请输入旅行商问题的规模：";
    cin>>n;
    //第n行第n列用于保存每行每列的最小值，也即是用于确认是否每行每列均有0
    //初始化第n行第n列为无穷大
    cout<<"依次输入耗费矩阵的值(对角线为0，不可达也输入0)："<<endl;
    for(int i=0;i<n;i++)
    {
        cost[i][n]=INF;
        cost[n][i]=INF;
    }
    //输入耗费矩阵的初值
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
            //如果两个顶点之间没有边可以到达则输入0，设置为INF
            //包括对角线，自身到自身的值输入0，设置为INF
            if (cost[i][j]==0)
                cost[i][j]=INF;
        }
    }
}


//将当前耗费矩阵写入文件中
void CostMatrix::WriteMatrix(fstream &file)
{
    file.seekp(ios::end);
    file<<num<<' '<<bound<<'\r'<<'\n';
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            file<<cost[i][j]<<' ';
        file<<'\r'<<'\n';
    }
}


//从文件中读出指定耗费矩阵
void CostMatrix::ReadMatrix(fstream &file,int Num)
{
    int temp=-1;
    //定位到文件起始位置
    file.seekg(ios::beg);

    //找到相应的耗费矩阵
    while(temp!=Num)
    {
        file>>temp;
        num=temp;
        file>>bound;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                file>>cost[i][j];
    }

    //output();
}


//分支限界法求解旅行商问题
void CostMatrix::BranchAndBound()
{
    fstream outfile("CostMatrix.dat",ios::out|ios::app|ios::binary);
    fstream infile("CostMatrix.dat",ios::in|ios::binary);
    //判断文件是否可以正常打开
    if(!outfile||!infile)
    {
        cout<<"文件无法正常打开！"<<endl;
        exit(1);
    }


    //找出初始耗费矩阵
    reduction(n,n,0);
    //将初始的矩阵保存到文件中
    WriteMatrix(outfile);
    //将第一个归约耗费矩阵的下界和编号放入最小堆
    node.Bount=bound;
    node.number=num;
    PQ.push(node);
    outfile.close();
    outfile.open("CostMatrix.dat",ios::out|ios::app|ios::binary);

    //找出出发点
    int startlow,startcolumn;
    bool flag;
    int road=0;

    while(!PQ.empty())
    {
        flag=false;
        node=PQ.top();
        PQ.pop();
        road++;

        ReadMatrix(infile,node.number);
        //output();

        //找出每行的出发点
        for(int i=0;i<n;i++)
        {
            startlow=i;
            for(int j=0;j<n;j++)
                if(cost[i][j]==0)
                {
                    startcolumn=j;
                    flag=true;
                    break;
                }
            if(flag==true)break;
        }
        //找不到为0的点表示结束
        if(flag==false)break;

        //分别计算左右两个规约耗费矩阵并写入文件中
        num=2*num+1;
        getleftCostMatrix(startlow,startcolumn,road);
        //output();
        WriteMatrix(outfile);
        //放入最小堆中
        node.Bount=bound;
        node.number=num;
        PQ.push(node);

        ReadMatrix(infile,(num-1)/2);

        num=2*num+2;
        getrightCostMatrix(startlow,startcolumn);
        //output();
        WriteMatrix(outfile);
        //放入最小堆中
        node.Bount=bound;
        node.number=num;
        PQ.push(node);
    }

    outfile.close();
    infile.close();

    //输出旅行商的路径,从第0行出发
    int row=0;
    cout<<endl<<"bound:"<<bound<<endl<<"route:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(cost[n][j]==cost[row][n])
            {
                cout<<row+1;
                row=j;
                break;
            }
        //最后一个顶点不输出-->
        if(i==n-1)break;
        cout<<"-->";
    }
    cout<<endl;
}



//输出当前矩阵的值
void CostMatrix::output()
{
    cout<<num<<' '<<bound<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<cost[i][j]<<' ';
        cout<<endl;
    }
}

