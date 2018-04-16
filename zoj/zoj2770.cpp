#include<iostream>
#include<stdio.h>

#define N 1010
#define  INF  9999999
using namespace std;

//阵营的数量
int n;
//距离值表
int dist[N];
//存放从1累积到i的士兵最大数量
int d[N];
//代表m组输入从i到j阵营之间的士兵的数量
int m;
//兵营的容量
int C[N];
//其实兵营编号，终点兵营编号，之间的士兵数目
int A,B,num;
//记录边的总数
int edgesum;

//边集数组
struct node
{
	int start;
	int end;
	int val;
}edge[23000];




void init()
{
    edgesum=0;
    int i;
    for(i=0;i<=n;i++)
        dist[i]=INF;
    d[0]=0;
    //通过设置n号结点距离值为0来使n号结点作为出发点
    dist[n]=0;
}


//按边集数组的出边顶点进行处理每一条边
bool BellmanFord ()
{
//在带权有向图中有的边具有负的权值。
//从顶点0找到所有其它顶点的最短路径。
    int flag;
    for(int k=0;k<=n;k++)  //走n-1条边,第n次判断是否存在负数环
    {
        flag=1;
        for(int u=0;u<edgesum;u++)  //按顺序对边集数组中的每条条边进行处理
            //通过设置n号结点距离值为0来使n号结点作为出发点,必须等n号结点出发后其他结点才能开始改变距离值表
            if(dist[edge[u].start]+edge[u].val<dist[edge[u].end]&&dist[edge[u].start]!=INF)
            {
                dist[edge[u].end]=dist[edge[u].start]+edge[u].val;
                flag=0;
            }
    }
    //存在负数环
    if(flag==0)return false;
    return true;

}


int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&C[i]);
            edge[edgesum].start=i-1;
            edge[edgesum].end=i;
            edge[edgesum].val=C[i];
            edgesum++;
            edge[edgesum].start=i;
            edge[edgesum].end=i-1;
            edge[edgesum].val=0;
            edgesum++;
            //计算从第0个兵营累积到第i个兵营的士兵数量
            d[i]=C[i]+d[i-1];
        }

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&A,&B,&num);
            edge[edgesum].start=A-1;
            edge[edgesum].end=B;
            edge[edgesum].val=d[B]-d[A-1];
            edgesum++;
            edge[edgesum].start=B;
            edge[edgesum].end=A-1;
            edge[edgesum].val=-num;
            edgesum++;
        }

        if(!BellmanFord())printf("Bad Estimations\n");
        else printf("%d\n",-dist[0]);
    }

    return 0;
}
