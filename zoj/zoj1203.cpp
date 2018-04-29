#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<math.h>

using namespace std;

//最大顶点数、城市数
#define N 100

//邻接矩阵
double G[N][N];
//实际城市数
int n;
//并查集
int parent[N];


//顶点的坐标
struct Vertex{
    double X;
    double Y;
}city[N];


struct Edge{
    //起始顶点和终止顶点
    int start;
    int end;
    //边的权重
    double cost;
}edge,Dis[N];


void fill_matrix()
{
    //两顶点之间的距离
    double dis;
    //初始化对角线为0
    for(int i=0;i<n;i++)
        G[i][i]=0;
    //填入每条边的权重
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //计算两点间的距离
            dis=sqrt((city[i].X-city[j].X)*(city[i].X-city[j].X)
                     +(city[i].Y-city[j].Y)*(city[i].Y-city[j].Y));
            G[i][j]=dis;
        }
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


//将边放入最小堆中
void InsertQueue()
{
    //将队列清空
    while(!PQ.empty())
        PQ.pop();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            edge.start=i;
            edge.end=j;
            edge.cost=G[i][j];
            //进入优先队列
            PQ.push(edge);
        }
}


//并查集合并
void SetUnion(int i,int j)
{
    //结点数之和
    int temp=parent[i]+parent[j];
    //树i结点比较多
    if(parent[i]<parent[j])
    {
        parent[j]=i;
        parent[i]=temp;
    }
    //两棵树结点一样多或者树j结点比较多
    else
    {
        parent[i]=j;
        parent[j]=temp;
    }
}

//找到含元素i的树的根，采用坍塌规则缩短从i到根的所有结点到根的距离
int SetFind(int i)
{
    int root=i;
    //找到根节点
    while(parent[root]>=0)
        root=parent[root];
    //路径坍塌
    int p;
    while(i!=root)
    {
        p=parent[i];
        parent[i]=root;
        i=p;
    }
    return root;
}

//Kruskal算法生成最小生成树
void Kruskal()
{
    int v1,v2;
    int edgenum=0;

    //并查集置空
    memset(parent,-1,sizeof(parent));

    //生成最小生成树
    while(edgenum<n-1)
    {
        edge=PQ.top();
        PQ.pop();
        //找到此边两个顶点所属集合
        v1=SetFind(edge.start);
        v2=SetFind(edge.end);
        //判断两个顶点是否连通
        //不连通，则添加新的边
        if(v1!=v2)
        {
            //合并两个集合
            SetUnion(v1,v2);
            Dis[edgenum].cost=edge.cost;
            Dis[edgenum].start=edge.start;
            Dis[edgenum].end=edge.end;
            edgenum++;
        }
    }//end while
}

int main()
{
    int times=0;
    while(scanf("%d",&n))
    {
        times++;
        if(n==0)break;
        if(times!=1)printf("\n");
        //输入各个顶点
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&city[i].X,&city[i].Y);

        //初始化
        fill_matrix();
        //初始化最小堆
        InsertQueue();
        //生成最小生成树
        Kruskal();

        //统计距离
        double result=0;
        for(int i=0;i<n-1;i++)
            result=Dis[i].cost+result;

        //输出结果
        printf("Case #%d:\n",times);
        printf("The minimal distance is：%.2lf\n",result);
    }
    return 0;
}
