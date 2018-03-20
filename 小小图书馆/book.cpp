#include<iostream>
#include<string.h>
#include<iomanip>
#include"book.h"

using namespace std;

char *Book::getname()               //获得书名
{return name;}

int Book::getnote()                 //获得删除标记
{return note;}

int Book::getnumber()               //获得图书编号
{return number;}

void Book::setname(char na[])        //设置书名
{strcpy(name,na);}

void Book::addbook(int n,char *na)  //添加图书
{
    note=0;
    number=n;
    strcpy(name,na);
    onshelf=1;
}

void Book::delbook()                //删除图书
{note=1;}

int Book::borrowbook()             //借书操作
{return onshelf;}

void Book::retbook()                //还书操作
{onshelf=1;}

void Book::list()                   //输出图书
{cout<<setw(5)<<number<<setw(10)<<name<<setw(10)<<onshelf<<endl;}


