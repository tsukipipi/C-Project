//////////////////////////////////////////////
//
//文件名：student_IM.cpp
//程序功能：Function类的成员函数,学生基本信息管理
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <algorithm>     //sort函数
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//学生基本信息管理函数
//函数功能：学生基本信息管理
//      1.添加学生
//      2.查询学生信息
//      3.修改学生信息
//      4.删除学生
//函数参数：无
//参数返回值：无
//
void Function::studentdatabase()
{
    int choice=1;
    int number;
    char name[15];
    char sex;
    char phone[15];

    while(choice!=0)
    {
        cout<<"    学生基本信息管理："<<endl;
        cout<<"========================"<<endl;
        cout<<"|    1.添加学生        |"<<endl;
        cout<<"|    2.查询学生信息    |"<<endl;
        cout<<"|    3.修改学生信息    |"<<endl;
        cout<<"|    4.删除学生        |"<<endl;
        cout<<"|    0.退出            |"<<endl;
        cout<<"========================"<<endl;
        cout<<"请输入选择：";
        cin>>choice;
        system("cls");

        if(choice<=4&&choice>=0)
        {
            switch(choice)
            {
            case 1://添加学生
                   cout<<"请输入学生的姓名：";
                   cin>>name;
                   cout<<"请输入学生的学号(4位数字)：";
                   cin>>number;
                   cout<<"请输入学生的性别(男生：m 女生：f)：";
                   cin>>sex;
                   cout<<"请输入学生的电话号码：";
                   cin>>phone;
                   //添加学生信息
                   addstudent(name,sex,number,phone);
                   Sleep(1000);
                   system("cls");

                   break;

            case 2://查询学生信息
                   cout<<"请输入想要查询的学生的学号(4位数字)：";
                   cin>>number;
                   ps=queryNum(number);
                   if(ps==NULL)
                   {
                       cout<<"\n无法找到此学生！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   ps->show();
                   Sleep(3000);
                   system("cls");

                   break;

            case 3://修改学生信息
                   cout<<"请输入想要修改信息的学生的学号(4位数字)：";
                   cin>>number;
                   ps=queryNum(number);
                   if(ps==NULL)
                   {
                       cout<<"\n无法找到此学生！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   system("cls");
                   //修改学生信息
                   modify(ps);

                   break;

            case 4://删除学生
                   cout<<"请输入想要删除信息的学生的学号(4位数字)：";
                   cin>>number;
                   //删除学生信息
                   if(deletestudent(number)==1)
                       cout<<"\n删除成功！"<<endl;
                   else cout<<"\n删除失败！"<<endl;
                   Sleep(1000);
                   system("cls");

                   break;
            }
        }
        else
        {
            cout<<"请输入正确的选择！"<<endl;
        }
    }
}
