#include<iostream>
#include<string.h>
#include<iomanip>
#include"reader.h"

using namespace std;

char *Reader::getname()               //获得姓名
{return name;}

int Reader::getnote()                  //获得删除标记
{return note;}

int Reader::getnumber()                //获得读者编号
{return number;}

void Reader::setname(char na[])        //设置姓名
{strcpy(name,na);}

void Reader::addreader(int n,char *na)//添加读者
{
    note=0;
    number=n;
    strcpy(name,na);
    for(int i=0;i<Maxbor;i++)
        borbook[i]=0;
}

void Reader::delreader()               //删除读者
{note=1;}

void Reader::borrowbook(int bookid)    //借书操作
{
    for(int i=0;i<Maxbor;i++)
        if(borbook[i]==0)
        {
            borbook[i]=bookid;
            return;
        }
}

int Reader::retbook(int bookid)        //还书操作
{
    for(int i=0;i<Maxbor;i++)
        if(borbook[i]==bookid)
        {
            borbook[i]=0;
            return 1;
        }
    return 0;
}

void Reader::list()                    //输出读者信息
{
    cout<<setw(5)<<number<<setw(10)<<name<<"   [";
    for(int i=0;i<Maxbor;i++)
        if(borbook[i]==0)cout<<borbook[i]<<" ";
    cout<<"]"<<endl;
}
