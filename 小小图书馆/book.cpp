#include<iostream>
#include<string.h>
#include<iomanip>
#include"book.h"

using namespace std;

char *Book::getname()               //�������
{return name;}

int Book::getnote()                 //���ɾ�����
{return note;}

int Book::getnumber()               //���ͼ����
{return number;}

void Book::setname(char na[])        //��������
{strcpy(name,na);}

void Book::addbook(int n,char *na)  //���ͼ��
{
    note=0;
    number=n;
    strcpy(name,na);
    onshelf=1;
}

void Book::delbook()                //ɾ��ͼ��
{note=1;}

int Book::borrowbook()             //�������
{return onshelf;}

void Book::retbook()                //�������
{onshelf=1;}

void Book::list()                   //���ͼ��
{cout<<setw(5)<<number<<setw(10)<<name<<setw(10)<<onshelf<<endl;}


