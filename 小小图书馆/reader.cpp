#include<iostream>
#include<string.h>
#include<iomanip>
#include"reader.h"

using namespace std;

char *Reader::getname()               //�������
{return name;}

int Reader::getnote()                  //���ɾ�����
{return note;}

int Reader::getnumber()                //��ö��߱��
{return number;}

void Reader::setname(char na[])        //��������
{strcpy(name,na);}

void Reader::addreader(int n,char *na)//��Ӷ���
{
    note=0;
    number=n;
    strcpy(name,na);
    for(int i=0;i<Maxbor;i++)
        borbook[i]=0;
}

void Reader::delreader()               //ɾ������
{note=1;}

void Reader::borrowbook(int bookid)    //�������
{
    for(int i=0;i<Maxbor;i++)
        if(borbook[i]==0)
        {
            borbook[i]=bookid;
            return;
        }
}

int Reader::retbook(int bookid)        //�������
{
    for(int i=0;i<Maxbor;i++)
        if(borbook[i]==bookid)
        {
            borbook[i]=0;
            return 1;
        }
    return 0;
}

void Reader::list()                    //���������Ϣ
{
    cout<<setw(5)<<number<<setw(10)<<name<<"   [";
    for(int i=0;i<Maxbor;i++)
        if(borbook[i]==0)cout<<borbook[i]<<" ";
    cout<<"]"<<endl;
}
