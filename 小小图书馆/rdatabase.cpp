#include<iostream>
#include<fstream>
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include"rdatabase.h"

using namespace std;

RDatabase::RDatabase()          //构造函数初始化：读文件
{
    Reader s;
    top=-1;
    ifstream file;
    file.open("reader.dat",ios::in|ios::binary);
    //判断文件是否正常打开
    if(!file)
    {
        cerr<<"reader.dat 无法正确打开!\n"<<endl;
        exit(1);
    }
    while(1)
    {
        file.read((char*)&s,sizeof(s));
        //判断文件是否读入完毕
        if(!file)break;
        top++;
        read[top]=s;
    }
    file.close();
}

void RDatabase::clear()         //删除所有读者信息
{top=-1;}

Reader *RDatabase::query(int readerid,int &i)    //按编号查找读者
{
    for(i=0;i<=top;i++)
    {
        if(read[i].getnumber()==readerid&&read[i].getnote()==0)
            return &read[i];
    }
    return NULL;
}

int RDatabase::addreader(int n,char *na)  //添加读者记录时，先确定该读者是否已经存在
{
    Reader *p=query(n,j);
    if(p==NULL)
    {
        top++;
        read[top].addreader(n,na);
        cout<<"\n读者添加成功！\n"<<endl;
        return 1;
    }
    cout<<"\n读者添加失败！\n"<<endl;
    return 0;
}

int RDatabase::delreader(int readerid)    //删除读者
{
    Reader *r;
    r=query(readerid,j);
    if(r==NULL)
    {
        cout<<"\n删除失败，该读者不存在！"<<endl;
        Sleep(2000);
        system("cls");
        return 0;
    }
    r->delreader();
    read[j]=read[top];
    top--;
    cout<<"\n删除完毕！"<<endl;
    Sleep(2000);
    system("cls");
    return 1;
}

void RDatabase::list()                    //输出所有读者信息
{
    cout<<"读者编号   姓名     借书编号"<<endl;
    for(int i=0;i<=top;i++)
        read[i].list();
}

RDatabase::~RDatabase()                   //析构函数：写文件
{
    fstream file;
    file.open("reader.dat",ios::out|ios::binary);
    //判断文件是否正常打开
    if(!file)
    {
        cerr<<"reader.dat 无法正确打开!\n"<<endl;
        exit(1);
    }
    for(int i=0;i<=top;i++)
    {
        if(read[i].getnote()==0)
            file.write((char*)&read[i],sizeof(read[i]));
    }
    file.close();
}

void RDatabase::readerdata()              //读者库维护
{
    int choice=1;
    char readername[20];
    int readerid;
    Reader *r;

    while(choice!=0)
    {
        cout<<"  进入读者维护"<<endl;
        cout<<"----------------"<<endl;
        cout<<"|  1.新增      |"<<endl;
        cout<<"|  2.更改      |"<<endl;
        cout<<"|  3.删除      |"<<endl;
        cout<<"|  4.查找      |"<<endl;
        cout<<"|  5.显示      |"<<endl;
        cout<<"|  6.全删      |"<<endl;
        cout<<"|  0.退出      |"<<endl;
        cout<<"----------------"<<endl;
        cout<<"请选择：";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1: //新增
                   cout<<"输入读者编号：";
                   cin>>readerid;
                   cout<<"\n输入读者姓名：";
                   cin>>readername;
                   addreader(readerid,readername);
                   Sleep(1000);
                   system("cls");
                   break;

            case 2: //更改
                   cout<<"输入读者编号：";
                   cin>>readerid;
                   r=query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"\n该读者不存在！"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"输入新的姓名：";
                   cin>>readername;
                   r->setname(readername);
                   system("cls");
                   break;

            case 3: //删除
                   cout<<"输入读者编号：";
                   cin>>readerid;
                   delreader(readerid);
                   break;

            case 4: //查找
                   cout<<"输入读者编号：";
                   cin>>readerid;
                   r=query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"该读者不存在！"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"读者编号   姓名     借书编号"<<endl;
                   r->list();
                   Sleep(2000);
                   system("cls");
                   break;

            case 5: //显示
                   list();
                   Sleep(5000);
                   system("cls");
                   break;

            case 6: //全删
                   clear();
                   system("cls");
                   break;
        }//end switch
    }//end while
}
