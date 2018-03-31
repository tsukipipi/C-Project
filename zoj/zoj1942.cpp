#include <iostream>
#include <stdio.h>
#include <math.h>
#define N 200

using namespace std;

//ʯͷ������
struct Node{
    double x;
    double y;
}stone[N];
//ʵ��ʯͷ����Ŀ
int n;
//���������Ծ�������Сֵ
double dist[N][N];

double Max(double a,double b)
{
    if(a>b)return a;
    else return b;
}

double Min(double a,double b)
{
    if(a<b)return a;
    else return b;
}

//�ҳ�ÿ��·�������Ծ����Сֵ
void floyd()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=Min(dist[i][j],Max(dist[i][k],dist[k][j]));
}

int main()
{
    int times=1;
    while(1)
    {
        //�ж��Ƿ��������
        scanf("%d",&n);
        if(n==0)break;

        //���ÿ��ʯͷ������
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&stone[i].x,&stone[i].y);
        //����ÿ����ʯͷ֮��ľ���
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=sqrt((stone[i].x-stone[j].x)*(stone[i].x-stone[j].x)
                                +(stone[i].y-stone[j].y)*(stone[i].y-stone[j].y));
        floyd();
        printf("Scenario #%d\n",times++);
        printf("Frog Distance = %.3lf\n\n",dist[0][1]);
    }
    return 0;
}
