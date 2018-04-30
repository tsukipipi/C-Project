#include <iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

//��ׯ�����Ŀ
#define N 26
//����·��
#define rode 75


//�ڽӱ�*adj[N]ץסÿ����ׯ�ڽ������ͷ
struct Linknode{
    //�ڽӵĴ�ׯ���
    int villageNum;
    //ά������
    int cost;
    //ָ����һ�����ӵĴ�ׯ
    Linknode* next;
    //���캯��
    Linknode()
    {next=0;}
}*adj[N];


//�߽�㣬cost[N]��ʾά���������
struct Edge{
    //��ʼ�������ֹ����
    int start;
    int end;
    //�ߵ�Ȩ��
    double cost;
    //���캯��
    Edge()
    {cost=0;}
}edge,RodeCost[N];


//ʵ�ʴ�ׯ��
int n;
//�������Ĵ�ׯ
char village;
//��ׯ���ӵĳ�����
int k;
//��·ά������
int Rcost;
//��־�Ƿ��Ѿ�����
bool tag[N];


//ͷ���뽨��
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


//����ڽӱ�
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
    //ȱʡΪ����
    if(a.cost>b.cost)return true;
    else return false;
}

//��űߵ���С���ȶ���
priority_queue<Edge> PQ;


void Prim()
{

    //�Ӷ���0����
    Linknode *p=adj[0];
    int StartNode=0;
    tag[0]=1;

    //����һ�����������ӵı߷��������
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
        //δ��ǹ�
        if(tag[CurNode]==0)
        {
            tag[CurNode]=1;
            //�����µı�
            RodeCost[Size].cost=edge.cost;
            RodeCost[Size].start=edge.start;
            RodeCost[Size].end=edge.end;
            Size++;
            //�������ӵı߷������ȶ�����
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
        //�����㹻
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
        //���������
        while(!PQ.empty())
            PQ.pop();
        //����־ȫ����Ϊδ��־��
        memset(tag,0,sizeof(tag));
        //����ڽӱ�
        makeEmpty();

        for(int i=1;i<n;i++)
        {
            cin>>village>>k;
            Vnum=village-'A';
            for(int j=0;j<k;j++)
            {
                cin>>village>>Rcost;
                //ͷ���뽨���ڽӱ�
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
