//////////////////////////////////////////////
//
//文件名：student_IM_function.cpp
//程序功能：Function类的成员函数,学生基本信息增删查改
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include "student.h"
#include "dormitory.h"
#include "function.h"
#include "record.h"

using namespace std;



//学生信息管理的模块


/////////////////////////////////////////////
//查找函数
//函数功能：按学号查找学生
//函数参数：整型，num为学生学号
//参数返回值：Student型指针，返回查找到的学生对象的地址
//
Student *Function::queryNum(int num)
{
    for(int i=0;i<=stuNum;i++)
    {
        if(num==student[i].getnumber()&&student[i].getnote()==1)//宿舍号相同且未被删除(0：删除 1：未删除)
            return &student[i];
    }
    return NULL;
}


/////////////////////////////////////////////
//添加函数
//函数功能：增加学生
//函数参数：1.字符型指针，*na指向学生姓名
//          2.字符型，s为学生性别
//          3.整型，num为学生学号
//          4.字符型指针，*ph指向学生电话
//参数返回值：无
//
void Function::addstudent(char *na,char s,int num,char *ph)
{
    ps=queryNum(num);
    if(ps==NULL)
    {
        stuNum++;
        student[stuNum].addstudent(na,s,num,ph);
        cout<<"\n学生信息添加成功！"<<endl;
    }
    else cout<<"\n该学号已存在，学生信息添加失败！"<<endl;
}


/////////////////////////////////////////////
//删除函数
//函数功能：按学号删除学生
//函数参数：整型，num为学生学号
//参数返回值：布尔型，0--删除失败 1--删除成功
//
bool Function::deletestudent(int num)
{
    Dormitory *p;

    ps=queryNum(num);
    if(ps==NULL)
    {
        cout<<"\n此学生不存在！"<<endl;
        return 0;
    }
    else if(ps->getmark()==1)
    {
        cout<<"\n学生已经入宿！"<<endl;
        return 0;
    }
    else
    {
        if(ps->getroomNumber()!=0)
        {
            p=queryroom(ps->getroomNumber());
            if(p==NULL)
            {
                cout<<"出错，无法找到学生居住的宿舍！"<<endl;
                return 0;
            }
            //空出床位
            else p->not_use_bed(ps->getbedNumber());
        }
        ps->delstudent();
        return 1;
    }
}


/////////////////////////////////////////////
//修改函数
//函数功能：通过指向学生对象的指针修改学生信息
//函数参数：Student型指针
//参数返回值：无
//
void Function::modify(Student *p)
{
    char name[15];
    char phone[15];
    char sex;
    int select=1;

    while(select)
    {
        cout<<"     信息修改："<<endl;
        cout<<"===================="<<endl;
        cout<<"|    1.修改姓名    |"<<endl;
        cout<<"|    2.修改电话    |"<<endl;
        cout<<"|    3.修改性别    |"<<endl;
        cout<<"|    0.退出        |"<<endl;
        cout<<"===================="<<endl;
        cout<<"请输入选择：";
        cin>>select;
        cout<<endl;

        if(select>=0&&select<=3)
        {
            switch(select)
            {
            case 1://修改姓名
                   cout<<"请输入姓名：";
                   cin>>name;
                   p->setname(name);
                   cout<<"\n设置成功！"<<endl;
                   Sleep(1000);

                   break;

            case 2://修改电话
                   cout<<"请输入电话号码：";
                   cin>>phone;
                   p->setphone(phone);
                   cout<<"\n设置成功！"<<endl;
                   Sleep(1000);

                   break;

            case 3://修改性别
                   if(p->getmark()==1)
                   {
                       cout<<"该学生已经入宿！无法修改性别！"<<endl;
                       Sleep(1000);
                       break;
                   }
                   cout<<"请输入性别(男：m 女：f)：";
                   cin>>sex;
                   if(sex=='f'||sex=='m')
                   {
                       p->setsex(sex);
                       cout<<"\n设置成功！"<<endl;
                       Sleep(1000);
                   }
                   else
                   {
                       cout<<"\n性别输入错误！"<<endl;
                       Sleep(1000);
                       break;
                   }

                   break;
            }
            system("cls");
        }//end if
        else
        {
            cout<<"请输入正确的选择！"<<endl;
            Sleep(500);
            system("cls");
        }
    }
}
