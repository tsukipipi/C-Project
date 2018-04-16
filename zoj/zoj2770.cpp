#include<iostream>
#include<stdio.h>

#define N 1010
#define  INF  9999999
using namespace std;

//��Ӫ������
int n;
//����ֵ��
int dist[N];
//��Ŵ�1�ۻ���i��ʿ���������
int d[N];
//����m�������i��j��Ӫ֮���ʿ��������
int m;
//��Ӫ������
int C[N];
//��ʵ��Ӫ��ţ��յ��Ӫ��ţ�֮���ʿ����Ŀ
int A,B,num;
//��¼�ߵ�����
int edgesum;

//�߼�����
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
    //ͨ������n�Ž�����ֵΪ0��ʹn�Ž����Ϊ������
    dist[n]=0;
}


//���߼�����ĳ��߶�����д���ÿһ����
bool BellmanFord ()
{
//�ڴ�Ȩ����ͼ���еı߾��и���Ȩֵ��
//�Ӷ���0�ҵ�����������������·����
    int flag;
    for(int k=0;k<=n;k++)  //��n-1����,��n���ж��Ƿ���ڸ�����
    {
        flag=1;
        for(int u=0;u<edgesum;u++)  //��˳��Ա߼������е�ÿ�����߽��д���
            //ͨ������n�Ž�����ֵΪ0��ʹn�Ž����Ϊ������,�����n�Ž����������������ܿ�ʼ�ı����ֵ��
            if(dist[edge[u].start]+edge[u].val<dist[edge[u].end]&&dist[edge[u].start]!=INF)
            {
                dist[edge[u].end]=dist[edge[u].start]+edge[u].val;
                flag=0;
            }
    }
    //���ڸ�����
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
            //����ӵ�0����Ӫ�ۻ�����i����Ӫ��ʿ������
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
