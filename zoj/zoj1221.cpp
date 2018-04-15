#include <iostream>
#include <stdio.h>
using namespace std;

#define Num 20
#define INF 65536


//保存任意两点之间的最短路径
int D[Num][Num];
//查询的数目
int N;
//一个国家邻接的国家数目(编号大于该国家)
int X;
//邻接的国家编号
int num;
//要查询的起始国家和终点国家
int A,B;

int Min(int x,int y)
{
    if(x<y)return x;
    else return y;
}

//所有点对最短路径
void Floyd()
{
    //k控制可以经过的最大顶点编号，i表示行，j表示列
    for(int k=1;k<Num;k++)
        for(int i=0;i<Num;i++)
            for(int j=0;j<Num;j++)
                D[i][j]=Min(D[i][j],D[i][k]+D[k][j]);
}

int main()
{
    //测试集的数目
    int times=1;
    bool flag=true;
    while(flag)
    {
        //初始化距离矩阵为无穷大
        for(int i=0;i<Num;i++)
            for(int j=0;j<Num;j++)
                D[i][j]=INF;
        //将对角线初始化为0
        for(int i=0;i<Num;i++)
            D[i][i]=0;
        //每次有19个国家的邻接国数据要输入
        for(int i=0;i<Num-1;i++)
        {
            //判断是否还有数据要输入
            if(scanf("%d",&X)==EOF)
            {
                flag=false;
                break;
            }
            //填写邻接/距离矩阵
            for(int j=0;j<X;j++)
            {
                scanf("%d",&num);
                D[i][num-1]=1;
                D[num-1][i]=1;
            }
        }
        if(flag)
        {
            //调用弗洛伊德算法
            Floyd();
            //输入查询的数目
            scanf("%d",&N);
            printf("Test Set #%d\n",times++);
            //依次查询
            for(int i=0;i<N;i++)
            {
                scanf("%d%d",&A,&B);
                printf("%d to %d: %d\n",A,B,D[A-1][B-1]);
            }
            printf("\n");
        }
    }

    return 0;
}
