#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


//���鼯
int parent[30001];

//ʵ��ѧ����
int n;
//ʵ������
int m;
//ÿ��ѧ����
int k;
//ÿ��ѧ��
int student[30001];


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
    int result;

    while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
    {
        //���鼯�ÿ�
        memset(parent,-1,sizeof(parent));
        //����ÿ��ѧ�����;���ѧ��
        for(int i=0;i<m;i++)
        {
            scanf("%d",&k);
            for(int j=0;j<k;j++)
                scanf("%d",&student[j]);
            //�ϲ��й�ϵ�Ĳ��鼯
            for(int j=0;j<k-1;j++)
            {
                s1=SetFind(student[j]);
                s2=SetFind(student[j+1]);
                if(s1!=s2)//�ϲ���������
                    SetUnion(s1,s2);
            }
        }
        s1=SetFind(0);
        result=0-parent[s1];
        printf("%d\n",result);
    }

    return 0;
}
