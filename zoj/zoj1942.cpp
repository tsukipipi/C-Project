#include <iostream>
#include <stdio.h>
#include <math.h>
#define N 200

using namespace std;

//石头的坐标
struct Node{
    double x;
    double y;
}stone[N];
//实际石头的数目
int n;
//保存最大跳跃距离的最小值
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

//找出每条路径最大跳跃的最小值
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
        //判断是否输入结束
        scanf("%d",&n);
        if(n==0)break;

        //获得每块石头的坐标
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&stone[i].x,&stone[i].y);
        //填入每两块石头之间的距离
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
