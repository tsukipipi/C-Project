#include<fstream>
#include<iostream>
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include"bdatabase.h"

using namespace std;

BDatabase::BDatabase()            //构造函数初始化，读文件
{
    Book s;		//中间图书对象
    top=-1;
    fstream file;
    file.open("book.dat",ios::in|ios::binary);
    //判断文件是否正常打开
    if(!file)
    {
        cerr<<"book.dat 无法正确打开!\n"<<endl;
        exit(1);
    }
    while(1)
    {
        //将信息从f流读到io流
        file.read((char*)&s,sizeof(s));
        //判断文件是否读入完毕
        if(!file)break;
        top++;
        book[top]=s;
    }
    file.close();
}

void BDatabase::clear()           //删除所有图书信息
{top=-1;}

Book *BDatabase::query(int bookid,int &i)    //查找图书
{
    for(i=0;i<=top;i++)
    {
        if(book[i].getnumber()==bookid&&book[i].getnote()==0)
            return &book[i];
    }
    return NULL;
}

int BDatabase::addbook(int n,char *na)//添加图书
{
    Book *p=query(n,j);
    if(p==NULL)
    {
        top++;
        book[top].addbook(n,na);
        cout<<"\n图书添加成功！\n"<<endl;
        return 1;
    }
    cout<<"\n图书添加失败！\n"<<endl;
    return 0;
}

int BDatabase::delbook(int bookid)    //删除图书
{
    Book *b;
    b=query(bookid,j);
    if(b==NULL)
    {
        cout<<"\n删除失败，该图书不存在！"<<endl;
        Sleep(2000);
        system("cls");
        return 0;
    }
    b->delbook();
    book[j]=book[top];
    top--;
    cout<<"\n删除完毕！"<<endl;
    Sleep(2000);
    system("cls");
    return 1;
}

void BDatabase::list()                //输出图书信息
{
    cout<<"图书编号   书名     馆存数目"<<endl;
    for(int i=0;i<=top;i++)
        book[i].list();
}

BDatabase::~BDatabase()               //析构函数：写文件
{
    fstream file;
    file.open("book.dat",ios::out|ios::binary);
    //判断文件是否正常打开
    if(!file)
    {
        cerr<<"book.dat 无法正确打开!\n"<<endl;
        exit(1);
    }
    for(int i=0;i<=top;i++)
    {
        if(book[i].getnote()==0)
            file.write((char*)&book[i],sizeof(book[i]));
    }
    file.close();
}

void BDatabase::bookdata()            //图书库维护
{
    int choice=1;
    char bookname[20];
    int bookid;
    Book *b;

    while(choice!=0)
    {
        cout<<"  进入图书维护"<<endl;
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
                   cout<<"输入图书编号：";
                   cin>>bookid;
                   cout<<"\n输入图书名：";
                   cin>>bookname;
                   addbook(bookid,bookname);
                   Sleep(1000);
                   system("cls");
                   break;

            case 2: //更改
                   cout<<"输入图书编号：";
                   cin>>bookid;
                   b=query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n该图书不存在！"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"\n输入新的图书名：";
                   cin>>bookname;
                   b->setname(bookname);
                   system("cls");
                   break;

            case 3: //删除
                   cout<<"输入图书编号：";
                   cin>>bookid;
                   delbook(bookid);
                   break;

            case 4: //查找
                   cout<<"输入图书编号：";
                   cin>>bookid;
                   b=query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n该图书不存在！"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"图书编号   书名     馆存数目"<<endl;
                   b->list();
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
