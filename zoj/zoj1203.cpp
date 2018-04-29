#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<math.h>

using namespace std;

//��󶥵�����������
#define N 100

//�ڽӾ���
double G[N][N];
//ʵ�ʳ�����
int n;
//���鼯
int parent[N];


//���������
struct Vertex{
    double X;
    double Y;
}city[N];


struct Edge{
    //��ʼ�������ֹ����
    int start;
    int end;
    //�ߵ�Ȩ��
    double cost;
}edge,Dis[N];


void fill_matrix()
{
    //������֮��ľ���
    double dis;
    //��ʼ���Խ���Ϊ0
    for(int i=0;i<n;i++)
        G[i][i]=0;
    //����ÿ���ߵ�Ȩ��
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //���������ľ���
            dis=sqrt((city[i].X-city[j].X)*(city[i].X-city[j].X)
                     +(city[i].Y-city[j].Y)*(city[i].Y-city[j].Y));
            G[i][j]=dis;
        }
    }
}


bool operator<(const Edge &a,const Edge &b)
{
    //ȱʡΪ����
    if(a.cost>b.cost)return true;
    else return false;
}

//��űߵ���С���ȶ���
priority_queue<Edge> PQ;


//���߷�����С����
void InsertQueue()
{
    //���������
    while(!PQ.empty())
        PQ.pop();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            edge.start=i;
            edge.end=j;
            edge.cost=G[i][j];
            //�������ȶ���
            PQ.push(edge);
        }
}


//���鼯�ϲ�
void SetUnion(int i,int j)
{
    //�����֮��
    int temp=parent[i]+parent[j];
    //��i���Ƚ϶�
    if(parent[i]<parent[j])
    {
        parent[j]=i;
        parent[i]=temp;
    }
    //���������һ���������j���Ƚ϶�
    else
    {
        parent[i]=j;
        parent[j]=temp;
    }
}

//�ҵ���Ԫ��i�����ĸ�������̮���������̴�i���������н�㵽���ľ���
int SetFind(int i)
{
    int root=i;
    //�ҵ����ڵ�
    while(parent[root]>=0)
        root=parent[root];
    //·��̮��
    int p;
    while(i!=root)
    {
        p=parent[i];
        parent[i]=root;
        i=p;
    }
    return root;
}

//Kruskal�㷨������С������
void Kruskal()
{
    int v1,v2;
    int edgenum=0;

    //���鼯�ÿ�
    memset(parent,-1,sizeof(parent));

    //������С������
    while(edgenum<n-1)
    {
        edge=PQ.top();
        PQ.pop();
        //�ҵ��˱�����������������
        v1=SetFind(edge.start);
        v2=SetFind(edge.end);
        //�ж����������Ƿ���ͨ
        //����ͨ��������µı�
        if(v1!=v2)
        {
            //�ϲ���������
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
        //�����������
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&city[i].X,&city[i].Y);

        //��ʼ��
        fill_matrix();
        //��ʼ����С��
        InsertQueue();
        //������С������
        Kruskal();

        //ͳ�ƾ���
        double result=0;
        for(int i=0;i<n-1;i++)
            result=Dis[i].cost+result;

        //������
        printf("Case #%d:\n",times);
        printf("The minimal distance is��%.2lf\n",result);
    }
    return 0;
}
