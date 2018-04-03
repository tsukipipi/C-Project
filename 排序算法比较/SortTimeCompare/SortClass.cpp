#include <iostream>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "SortClass.h"

using namespace std;


//˽�к���

//�����㷨
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
            //i==j˵��ǰ������data��Ԫ�ؾ�С��x�������轻��
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
    //i��һ����ȷλ��
    w=i;
}


//�ݹ��������
void SortTimeCompare::quicksort(int low,int high)
{
    //һ����ȷλ��
    int w;
    if(low<high)
    {
        split(low,high,w);
        quicksort(low,w-1);
        quicksort(w+1,high);
    }//end if
}



//�ϲ��㷨
void SortTimeCompare::Merge(int low,int mid,int high)
{
    //��������
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


//�鲢����
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


//ѡ������
void SortTimeCompare::selectsort(int i)
{
    int k=i;
    int temp;
    if(i<N)
    {
        //��i��N��ѡ����СԪ�ص��±걣����k��
        for(int j=i+1;j<N;j++)
            if(data[j]<data[k])k=j;
        //���i������Сֵ����������Сֵ����
        if(k!=i)
        {
            temp=data[i];
            data[i]=data[k];
            data[k]=temp;
        }
        selectsort(i+1);
    }
}


//������д����Ӧ���ļ�
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


//���к���

//��������
void SortTimeCompare::quicksort()
{
    quicksort(0,(sizeof(data)/4-1));
}


//�鲢����
void SortTimeCompare::mergesort()
{
    mergesort(0,(sizeof(data)/4-1));
}

//ѡ������
void SortTimeCompare::selectsort()
{
    selectsort(0);
}


//����������ݵĺ���
void SortTimeCompare::RandomCreateData()
{
    int i, m, n;
    srand((int)time(NULL));
    m = 0;
    n = 1000000;
    for(i=0;i<N;i++)
        data[i]=Random(m,n);
    //������д���ļ���
    writefile("data.dat");

}


//��������ɺ���
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


//�Ƚ����������㷨��ƽ������ʱ��
void SortTimeCompare::Compare()
{
    //����ļ��е�����
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

    cout<<"����ʱ��Ƚ�(��λ:����):"<<endl;

    for(int k=0;k<20;k++)
    {
        cout<<"��"<<k+1<<"��:"<<endl;

        RandomCreateData();

        for(i=0;i<N;i++)
            assist[i]=data[i];

        start = clock();
        quicksort();
        stop = clock();
        //��������д���ļ���
        writefile("quicksort.dat");
        cout<<"quicksort:"<<stop-start<<endl;


        for(i=0;i<N;i++)
            data[i]=assist[i];


        start = clock();
        mergesort();
        stop = clock();
        //��������д���ļ���
        writefile("mergesort.dat");
        cout<<"mergesort:"<<stop-start<<endl;


        for(i=0;i<N;i++)
            data[i]=assist[i];

        start = clock();
        selectsort();
        stop = clock();
        //��������д���ļ���
        writefile("selectsort.dat");
        cout<<"selectsort:"<<stop-start<<endl;

        cout<<endl;

    }//end for(20������)
}
