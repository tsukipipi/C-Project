#include <iostream>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "SortClass.h"

using namespace std;


//私有函数

//划分算法
void SortTimeCompare::split(int low,int high,int &w)
{
    int x=data[low];
    int i=low;
    int temp;
    for(int j=low+1;j<=high;j++)
    {
        if(data[j]<x)
        {
            i=i+1;
            //i==j说明前面数组data的元素均小于x，则无需交换
            if(i!=j)
            {
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }//end if
    }//end for
    temp=data[low];
    data[low]=data[i];
    data[i]=temp;
    //i是一个正确位置
    w=i;
}


//递归快速排序
void SortTimeCompare::quicksort(int low,int high)
{
    //一个正确位置
    int w;
    if(low<high)
    {
        split(low,high,w);
        quicksort(low,w-1);
        quicksort(w+1,high);
    }//end if
}



//合并算法
void SortTimeCompare::Merge(int low,int mid,int high)
{
    //辅助数组
    int assist[N];
    int h1,h2,k;
    h1=low;
    h2=mid+1;
    k=low;

    while(h1<=mid&&h2<=high)
    {
        if(data[h1]<=data[h2])
        {
            assist[k]=data[h1];
            h1++;
        }
        else
        {
            assist[k]=data[h2];
            h2++;
        }
        k++;
    }

    if(h1==mid+1)
        while(k<=high)
        {
            assist[k]=data[h2];
            h2++;
            k++;
        }
    else
        while(k<=high)
        {
            assist[k]=data[h1];
            h1++;
            k++;
        }

    for(int i=low;i<=high;i++)
        data[i]=assist[i];
}


//归并排序
void SortTimeCompare::mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        Merge(low,mid,high);
    }
}


//选择排序
void SortTimeCompare::selectsort(int i)
{
    int k=i;
    int temp;
    if(i<N)
    {
        //从i到N中选出最小元素的下标保存在k中
        for(int j=i+1;j<N;j++)
            if(data[j]<data[k])k=j;
        //如果i不是最小值，将其与最小值互换
        if(k!=i)
        {
            temp=data[i];
            data[i]=data[k];
            data[k]=temp;
        }
        selectsort(i+1);
    }
}


//将数据写入相应的文件
void SortTimeCompare::writefile(char *filename)
{
    int i=0;
    fstream file;
    file.open(filename,ios::out|ios::app|ios::binary);
    while(i<N)
    {
        file<<data[i]<<" ";
        i++;
    }
    file<<'\r'<<'\n'<<'\r'<<'\n'<<'\r'<<'\n';
    file.close();
}


//公有函数

//快速排序
void SortTimeCompare::quicksort()
{
    quicksort(0,(sizeof(data)/4-1));
}


//归并排序
void SortTimeCompare::mergesort()
{
    mergesort(0,(sizeof(data)/4-1));
}

//选择排序
void SortTimeCompare::selectsort()
{
    selectsort(0);
}


//随机生成数据的函数
void SortTimeCompare::RandomCreateData()
{
    int i, m, n;
    srand((int)time(NULL));
    m = 0;
    n = 1000000;
    for(i=0;i<N;i++)
        data[i]=Random(m,n);
    //将数据写入文件中
    writefile("data.dat");

}


//随机数生成函数
int SortTimeCompare::Random(int m, int n)
{
    int pos, dis;
    if(m == n)
    {
        return m;
    }
    else if(m > n)
    {
        pos = n;
        dis = m - n + 1;
        return rand() % dis + pos;
    }
    else
    {
        pos = m;
        dis = n - m + 1;
        return rand() % dis + pos;
    }
}


//比较三种排序算法的平均排序时间
void SortTimeCompare::Compare()
{
    //清空文件中的数据
    fstream file;
    file.open("data.dat",ios::out|ios::binary);
    file.close();
    file.open("quicksort.dat",ios::out|ios::binary);
    file.close();
    file.open("merge.dat",ios::out|ios::binary);
    file.close();
    file.open("selectsort.dat",ios::out|ios::binary);
    file.close();

    int i;
    int assist[N];
    clock_t start,stop;

    cout<<"排序时间比较(单位:毫秒):"<<endl;

    for(int k=0;k<20;k++)
    {
        cout<<"第"<<k+1<<"组:"<<endl;

        RandomCreateData();

        for(i=0;i<N;i++)
            assist[i]=data[i];

        start = clock();
        quicksort();
        stop = clock();
        //将排序结果写入文件中
        writefile("quicksort.dat");
        cout<<"quicksort:"<<stop-start<<endl;


        for(i=0;i<N;i++)
            data[i]=assist[i];


        start = clock();
        mergesort();
        stop = clock();
        //将排序结果写入文件中
        writefile("mergesort.dat");
        cout<<"mergesort:"<<stop-start<<endl;


        for(i=0;i<N;i++)
            data[i]=assist[i];

        start = clock();
        selectsort();
        stop = clock();
        //将排序结果写入文件中
        writefile("selectsort.dat");
        cout<<"selectsort:"<<stop-start<<endl;

        cout<<endl;

    }//end for(20组数据)
}
