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
    //�½�
    int Bount;
    //���
    int number;
}node;

bool operator<(const Node &a,const Node &b)
{
    if(a.Bount>b.Bount)return true;
    else return false;
}

//���ȶ���
priority_queue<Node> PQ;


class CostMatrix
{
private:
    //�ķѾ���
    int cost[Max][Max];
    //ͼ�н����Ŀ
    int n;
    //�½�
    int bound;
    //ÿ���ķѾ�����Ӧ�ı��
    int num;

    //�����ߵĺķѾ���,ѡ��·��row->column,δ��Լ
    void getleftCostMatrix(int row,int column,int road);
    //����ұߵĺķѾ���,��ѡ��·��row->column,δ��Լ
    void getrightCostMatrix(int row,int column);
    //��ù�Լ�ķѾ���
    void reduction(int row,int column,int road);

public:
    //���캯��
    CostMatrix();
    //��úķѾ���ĳ�ֵ
    void input();
    //����ǰ�ķѾ���д���ļ���
    void WriteMatrix(fstream &file);
    //���ļ��ж���ָ���ķѾ���
    void ReadMatrix(fstream &file,int Num);
    //��֧�޽編�������������
    void BranchAndBound();
    //�����ǰ�����ֵ
    void output();

};


#endif // BRANCHANDBOUND_H_INCLUDED

//private function

//��ù�Լ�ķѾ���
void CostMatrix::reduction(int row,int column,int road)
{
    //�ҳ����и��е���Сֵ
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(cost[i][j]<cost[i][n])cost[i][n]=cost[i][j];
            if(cost[i][j]<cost[n][j])cost[n][j]=cost[i][j];
        }


    //�ø�����ʾ�����Ѿ��ҵ�·��
    cost[row][n]=-road;
    //�ø�����ʾ�����Ѿ��ҵ�·��
    cost[n][column]=-road;

    //���н��й�Լ
    for(int i=0;i<n;i++)
    {
        //ȷ��ÿ�о���0
        if(cost[i][n]>0)
        {
            //�½�ֵ����
            bound=bound+cost[i][n];
            //����Ӧ�����ж���Сֵ�Ƿ����ı�
            for(int j=0;j<=n;j++)
            {
                //��һ���е�Ԫ����Ӧ��ȥ��Сֵ
                cost[i][j]=cost[i][j]-cost[i][n];
                if(cost[i][j]<cost[n][j])cost[n][j]=cost[i][j];
            }
        }
    }


    //���н��й�Լ
    for(int j=0;j<n;j++)
    {
        //ȷ��ÿ�о���0
        if(cost[n][j]>0)
        {
            //�½�ֵ����
            bound=bound+cost[n][j];
            for(int i=0;i<=n;i++)
            {
                cost[i][j]=cost[i][j]-cost[n][j];
            }
        }
    }
}


//�����ߵĺķѾ���,ѡ��·��row->column,δ��Լ
void CostMatrix::getleftCostMatrix(int row,int column,int road)
{
    //��row����Ϊ�����
    for(int j=0;j<n;j++)
        cost[row][j]=INF;
    //��column����Ϊ�����
    for(int i=0;i<n;i++)
        cost[i][column]=INF;

    //����·��column->row
    cost[column][row]=INF;

    //�����ø��С��е���СֵΪ�����
    for(int i=0;i<n;i++)
    {
        if(cost[i][n]>=0)cost[i][n]=INF;
        if(cost[n][i]>=0)cost[n][i]=INF;
    }

    //�ҳ��µĺķѾ���
    reduction(row,column,road);
}


//����ұߵĺķѾ���,��ѡ��·��row->column,δ��Լ
void CostMatrix::getrightCostMatrix(int row,int column)
{
    //����·��row->column
    cost[row][column]=INF;
    //������row�е���СֵΪ�����
    cost[row][n]=INF;
    //������column�е���СֵΪ�����
    cost[n][column]=INF;
    //�ҳ�row���µ���Сֵ
    for(int j=0;j<n;j++)
        if(cost[row][j]<cost[row][n])cost[row][n]=cost[row][j];
    //�ҳ�column���µ���Сֵ
    for(int i=0;i<n;i++)
        if(cost[i][column]<cost[n][column])cost[n][column]=cost[i][column];
    //�ҳ��µĺķѾ���
    reduction(n,n,0);
}


//public function

//���캯��
CostMatrix::CostMatrix()
{
    bound=0;
    num=0;
}


//��úķѾ���ĳ�ֵ
void CostMatrix::input()
{
    cout<<"����������������Ĺ�ģ��";
    cin>>n;
    //��n�е�n�����ڱ���ÿ��ÿ�е���Сֵ��Ҳ��������ȷ���Ƿ�ÿ��ÿ�о���0
    //��ʼ����n�е�n��Ϊ�����
    cout<<"��������ķѾ����ֵ(�Խ���Ϊ0�����ɴ�Ҳ����0)��"<<endl;
    for(int i=0;i<n;i++)
    {
        cost[i][n]=INF;
        cost[n][i]=INF;
    }
    //����ķѾ���ĳ�ֵ
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
            //�����������֮��û�б߿��Ե���������0������ΪINF
            //�����Խ��ߣ����������ֵ����0������ΪINF
            if (cost[i][j]==0)
                cost[i][j]=INF;
        }
    }
}


//����ǰ�ķѾ���д���ļ���
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


//���ļ��ж���ָ���ķѾ���
void CostMatrix::ReadMatrix(fstream &file,int Num)
{
    int temp=-1;
    //��λ���ļ���ʼλ��
    file.seekg(ios::beg);

    //�ҵ���Ӧ�ĺķѾ���
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


//��֧�޽編�������������
void CostMatrix::BranchAndBound()
{
    fstream outfile("CostMatrix.dat",ios::out|ios::app|ios::binary);
    fstream infile("CostMatrix.dat",ios::in|ios::binary);
    //�ж��ļ��Ƿ����������
    if(!outfile||!infile)
    {
        cout<<"�ļ��޷������򿪣�"<<endl;
        exit(1);
    }


    //�ҳ���ʼ�ķѾ���
    reduction(n,n,0);
    //����ʼ�ľ��󱣴浽�ļ���
    WriteMatrix(outfile);
    //����һ����Լ�ķѾ�����½�ͱ�ŷ�����С��
    node.Bount=bound;
    node.number=num;
    PQ.push(node);
    outfile.close();
    outfile.open("CostMatrix.dat",ios::out|ios::app|ios::binary);

    //�ҳ�������
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

        //�ҳ�ÿ�еĳ�����
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
        //�Ҳ���Ϊ0�ĵ��ʾ����
        if(flag==false)break;

        //�ֱ��������������Լ�ķѾ���д���ļ���
        num=2*num+1;
        getleftCostMatrix(startlow,startcolumn,road);
        //output();
        WriteMatrix(outfile);
        //������С����
        node.Bount=bound;
        node.number=num;
        PQ.push(node);

        ReadMatrix(infile,(num-1)/2);

        num=2*num+2;
        getrightCostMatrix(startlow,startcolumn);
        //output();
        WriteMatrix(outfile);
        //������С����
        node.Bount=bound;
        node.number=num;
        PQ.push(node);
    }

    outfile.close();
    infile.close();

    //��������̵�·��,�ӵ�0�г���
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
        //���һ�����㲻���-->
        if(i==n-1)break;
        cout<<"-->";
    }
    cout<<endl;
}



//�����ǰ�����ֵ
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

