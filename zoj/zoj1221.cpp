#include <iostream>
#include <stdio.h>
using namespace std;

#define Num 20
#define INF 65536


//������������֮������·��
int D[Num][Num];
//��ѯ����Ŀ
int N;
//һ�������ڽӵĹ�����Ŀ(��Ŵ��ڸù���)
int X;
//�ڽӵĹ��ұ��
int num;
//Ҫ��ѯ����ʼ���Һ��յ����
int A,B;

int Min(int x,int y)
{
    if(x<y)return x;
    else return y;
}

//���е�����·��
void Floyd()
{
    //k���ƿ��Ծ�������󶥵��ţ�i��ʾ�У�j��ʾ��
    for(int k=1;k<Num;k++)
        for(int i=0;i<Num;i++)
            for(int j=0;j<Num;j++)
                D[i][j]=Min(D[i][j],D[i][k]+D[k][j]);
}

int main()
{
    //���Լ�����Ŀ
    int times=1;
    bool flag=true;
    while(flag)
    {
        //��ʼ���������Ϊ�����
        for(int i=0;i<Num;i++)
            for(int j=0;j<Num;j++)
                D[i][j]=INF;
        //���Խ��߳�ʼ��Ϊ0
        for(int i=0;i<Num;i++)
            D[i][i]=0;
        //ÿ����19�����ҵ��ڽӹ�����Ҫ����
        for(int i=0;i<Num-1;i++)
        {
            //�ж��Ƿ�������Ҫ����
            if(scanf("%d",&X)==EOF)
            {
                flag=false;
                break;
            }
            //��д�ڽ�/�������
            for(int j=0;j<X;j++)
            {
                scanf("%d",&num);
                D[i][num-1]=1;
                D[num-1][i]=1;
            }
        }
        if(flag)
        {
            //���ø��������㷨
            Floyd();
            //�����ѯ����Ŀ
            scanf("%d",&N);
            printf("Test Set #%d\n",times++);
            //���β�ѯ
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
