#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//ѧ����Ŀ
#define N 100001

int parent[N];

//ʵ��ѧ����
int n;
//ʵ�ʲ�����
int m;
//����
char op;


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


int main()
{
    int s1,s2;
    int times=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(times)printf("\n");
        times++;
        //���鼯�ÿ�
        memset(parent,-1,sizeof(parent));

        printf("Case %d:\n",times);
        for(int i=0;i<m;i++)
        {
            getchar();
            scanf("%c",&op);
            if(op=='M')
            {
                scanf("%d%d",&s1,&s2);
                s1=SetFind(s1);
                s2=SetFind(s2);
                if(s1!=s2)
                    SetUnion(s1,s2);
            }
            else
            {
                scanf("%d",&s1);
                s1=SetFind(s1);
                printf("%d\n",(0-parent[s1]));
            }
        }//end for
    }
    return 0;
}
