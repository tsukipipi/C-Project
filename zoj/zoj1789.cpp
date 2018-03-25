#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


//并查集
int parent[30001];

//实际学生数
int n;
//实际组数
int m;
//每组学生数
int k;
//每组学生
int student[30001];


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
    int result;

    while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
    {
        //并查集置空
        memset(parent,-1,sizeof(parent));
        //输入每组学生数和具体学生
        for(int i=0;i<m;i++)
        {
            scanf("%d",&k);
            for(int j=0;j<k;j++)
                scanf("%d",&student[j]);
            //合并有关系的并查集
            for(int j=0;j<k-1;j++)
            {
                s1=SetFind(student[j]);
                s2=SetFind(student[j+1]);
                if(s1!=s2)//合并两个集合
                    SetUnion(s1,s2);
            }
        }
        s1=SetFind(0);
        result=0-parent[s1];
        printf("%d\n",result);
    }

    return 0;
}
