#include <iostream>
#include <stdio.h>
#include <set>

#define M 30

using namespace std;

int n;
int m;
set<int> num;
set<int>::iterator it1,it2,itfind; //定义前向迭代器

int main()
{
    int temp;
    int sum,x1,x2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        //清空集合中的元素
        num.clear();
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&temp);
            num.insert(temp);
        }
        for(it1=num.begin();it1!=num.end();)
        {
            x1=*it1;
            for(it2=++it1;it2!=num.end();it2++)
            {
                x2=*it2;
                sum=x1+x2;
                itfind=num.find(sum);
                if(itfind!=num.end())
                {
                    printf("%d+%d=%d\n",x1,x2,sum);
                }
            }
        }
    }
    return 0;
}
