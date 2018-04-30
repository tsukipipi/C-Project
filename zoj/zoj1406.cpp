#include <iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

//村庄最大数目
#define N 26
//最大道路数
#define rode 75


//邻接表，*adj[N]抓住每个村庄邻接链表的头
struct Linknode{
    //邻接的村庄编号
    int villageNum;
    //维护费用
    int cost;
    //指向下一个连接的村庄
    Linknode* next;
    //构造函数
    Linknode()
    {next=0;}
}*adj[N];


//边结点，cost[N]表示维护所需费用
struct Edge{
    //起始顶点和终止顶点
    int start;
    int end;
    //边的权重
    double cost;
    //构造函数
    Edge()
    {cost=0;}
}edge,RodeCost[N];


//实际村庄数
int n;
//代表具体的村庄
char village;
//村庄连接的城市数
int k;
//道路维护费用
int Rcost;
//标志是否已经加入
bool tag[N];


//头插入建链
void HeadInsert(int v1,int v2,int c)
{
    //v1->v2
    Linknode *p;
    p=new Linknode;
    p->villageNum=v2;
    p->cost=c;
    p->next=adj[v1];
    adj[v1]=p;
    //v2->v1
    p=new Linknode;
    p->villageNum=v1;
    p->cost=c;
    p->next=adj[v2];
    adj[v2]=p;
}


//清空邻接表
void makeEmpty()
{
    Linknode *p,*q;
    for(int i=0;i<N;i++)
    {
        p=adj[i];
        while(p!=0)
        {
            q=p->next;
            delete p;
            p=q;
        }
        adj[i]=0;
    }
}


bool operator<(const Edge &a,const Edge &b)
{
    //缺省为最大堆
    if(a.cost>b.cost)return true;
    else return false;
}

//存放边的最小优先队列
priority_queue<Edge> PQ;


void Prim()
{

    //从顶点0出发
    Linknode *p=adj[0];
    int StartNode=0;
    tag[0]=1;

    //将第一个顶点所连接的边放入队列中
    while(1)
    {
        if(p==0)break;
        edge.start=StartNode;
        edge.end=p->villageNum;
        edge.cost=p->cost;
        PQ.push(edge);
        p=p->next;
    }

    int Size=0;
    int CurNode;

    while(!PQ.empty())
    {
        edge=PQ.top();
        PQ.pop();
        CurNode=edge.end;
        //未标记过
        if(tag[CurNode]==0)
        {
            tag[CurNode]=1;
            //加入新的边
            RodeCost[Size].cost=edge.cost;
            RodeCost[Size].start=edge.start;
            RodeCost[Size].end=edge.end;
            Size++;
            //将其连接的边放入优先队列中
            p=adj[CurNode];
            while(1)
            {
                if(p==0)break;
                edge.start=CurNode;
                edge.end=p->villageNum;
                edge.cost=p->cost;
                PQ.push(edge);
                p=p->next;
            }
        }
        //边数足够
        if(Size==n-1)break;
    }
}


int main()
{
    int Vnum;
    int total;
    while(cin>>n,n)
    {
        total=0;
        //将队列清空
        while(!PQ.empty())
            PQ.pop();
        //将标志全部置为未标志过
        memset(tag,0,sizeof(tag));
        //清空邻接表
        makeEmpty();

        for(int i=1;i<n;i++)
        {
            cin>>village>>k;
            Vnum=village-'A';
            for(int j=0;j<k;j++)
            {
                cin>>village>>Rcost;
                //头插入建立邻接表
                HeadInsert(Vnum,village-'A',Rcost);
            }
        }
        Prim();
        for(int i=0;i<n-1;i++)
            total=total+RodeCost[i].cost;
        cout<<total<<endl;
    }
    return 0;
}
