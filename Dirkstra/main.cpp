#include <iostream>
#include <queue>

#define Max 100

using namespace std;

//邻接矩阵
int cost[Max][Max];
//顶点数目
int n;
//距离值
struct Edge{
    int start;
    int end;
    int value;
}distant[Max],temp;


bool operator<(const Edge &a ,const Edge &b )
{
    if(a.value>b.value) return true ;
    else return false;
}

priority_queue <Edge> PQ;


void Input()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
}

void Dijkstra(int start)
{
    //先用出发点相邻的边的权重修改距离值表的值，并放入优先队列中
    for(int i=0;i<n;i++)
    {
        distant[i].start=start;
        distant[i].end=i;
        distant[i].value=cost[start][i];
        PQ.push(distant[i]);
    }
    //将出发点标记为已访问过，用1表示访问过
    cost[start][start]=1;

    //用于判断是否找到下一个顶点的最短路径
    bool flag;
    //n个顶点需要找到n-1个顶点的最短路径
    for(int i=0;i<n-1;i++)
    {
        flag=false;
        //找出下一个最短路径
        while(!flag&&!PQ.empty())
        {
            temp=PQ.top();
            PQ.pop();
            //如果顶点未访问表示找到该顶点的最短路径
            if(cost[temp.end][temp.end]==0)
                flag=true;
        }
        //将顶点标志位已访问
        cost[temp.end][temp.end]=1;
        //将其相邻的未访问过的并且距离值小于原先距离的边插入最小优先队列
        for(int j=0;j<n;j++)
        {
            //如果结点未访问过且当前路径大于从结点temp.end中转的路径
            if((distant[j].value>distant[temp.end].value+cost[temp.end][j])&&cost[j][j]==0)
            {
                distant[j].start=temp.end;
                //修改距离值表
                distant[j].value=distant[temp.end].value+cost[temp.end][j];
                PQ.push(distant[j]);
            }
        }
    }

}


void Output(int start)
{
    for(int i=0;i<n;i++)
        cout<<start<<"--->"<<i<<":"<<distant[i].value<<endl;
}

int main()
{
    Input();
    Dijkstra(0);
    Output(0);
    return 0;
}
