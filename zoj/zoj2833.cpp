#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//学生数目
#define N 100001

int parent[N];

//实际学生数
int n;
//实际操作数
int m;
//操作
char op;


//并查集合并
void SetUnion(int i,int j)
{
    //结点数之和
    int temp=parent[i]+parent[j];
    //树i结点比较多
    if(parent[i]<parent[j])
    {
        parent[j]=i;
        parent[i]=temp;
    }
    //两棵树结点一样多或者树j结点比较多
    else
    {
        parent[i]=j;
        parent[j]=temp;
    }
}

//找到含元素i的树的根，采用坍塌规则缩短从i到根的所有结点到根的距离
int SetFind(int i)
{
    int root=i;
    //找到根节点
    while(parent[root]>=0)
        root=parent[root];
    //路径坍塌
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
        //并查集置空
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
