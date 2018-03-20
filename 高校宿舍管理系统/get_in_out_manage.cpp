//////////////////////////////////////////////
//
//文件名：get_in_out_manage.cpp
//程序功能：Function类的成员函数,出入管理
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


/////////////////////////////////////////////
//查找函数
//函数功能：查找早出晚归学生
//函数参数：整型，num是要查找的学生学号
//参数返回值：Morning_Evening_record型指针
//
Morning_Evening_record *Function::query(int num)
{
    for(int i=0;i<=studNum;i++)
    {
        if(num==stud[i].getNum())
            return &stud[i];
    }
    return NULL;
}


/////////////////////////////////////////////
//早出登记函数
//函数功能：登记早出学生信息
//函数参数：无
//参数返回值：无
//
void Function::morning_go_out()
{
    int num;
    cout<<"请输入登记早出的学生的学号(4位数)：";
    while(1)
    {
        cin>>num;

        ps=queryNum(num);
        if(ps==NULL)
        {
            cout<<"\n不存在此学生！"<<endl;
            Sleep(1000);
            system("cls");
        }
        else if(ps->getmark()==0)
        {
            cout<<"\n该学生尚未入宿！信息错误！"<<endl;
            Sleep(1000);
            system("cls");
            break;
        }
        else
        {
            pr=query(num);
            //判断学生是否已经存在，若不存在先添加学生
            cout<<"\n学生信息如下："<<endl;
            if(pr==NULL)
            {
                studNum++;
                stud[studNum].addStud(ps->getname(),num);
                stud[studNum].morningRecord();
                stud[studNum].showStudentInformation();
            }
            else
            {
                pr->morningRecord();
                pr->showStudentInformation();
            }


            cout<<"\n早出信息登记成功！"<<endl;
            Sleep(4000);
            system("cls");
            break;
        }
        cout<<"请重新输入学号(4位数)：";
    }
}


/////////////////////////////////////////////
//晚归登记函数
//函数功能：登记晚归学生信息
//函数参数：无
//参数返回值：无
//
void Function::evening_go_back()
{
    int num;

    cout<<"请输入登记晚归的学生的学号(4位数)：";
    while(1)
    {
        cin>>num;

        ps=queryNum(num);
        if(ps==NULL)
        {
            cout<<"\n不存在此学生！"<<endl;
            Sleep(1000);
            system("cls");
        }
        else if(ps->getmark()==0)
        {
            cout<<"\n该学生尚未入宿！信息错误！"<<endl;
            Sleep(1000);
            system("cls");
            break;
        }
        else
        {
            pr=query(num);
            //判断学生是否已经存在，若不存在先添加学生
            cout<<"\n学生信息如下："<<endl;
            if(pr==NULL)
            {
                studNum++;
                stud[studNum].addStud(ps->getname(),num);
                stud[studNum].eveningRecord();
                stud[studNum].showStudentInformation();
            }
            else
            {
                pr->eveningRecord();
                pr->showStudentInformation();
            }

            cout<<"\n晚归信息登记成功！"<<endl;
            Sleep(4000);
            system("cls");
            break;
        }
        cout<<"请重新输入学号(4位数)：";
    }
}


/////////////////////////////////////////////
//来访者登记函数
//函数功能：登记来访者信息
//函数参数：无
//参数返回值：无
//
void Function::visit_record()
{
    char name[10];
    char sex;
    char visitTime[8];
    char leaveTime[8];
    char reason[50];
    int visitDorNum;

    cout<<"请输入来访者姓名：";
    cin>>name;
    cout<<"请输入来访者性别(男：m 女：f)：";
    cin>>sex;
    cout<<"请输入访问时间(24小时制,格式：xx:xx)：";
    cin>>visitTime;
    cout<<"请输入结束时间(24小时制,格式：xx:xx)：";
    cin>>leaveTime;
    cout<<"请简述来访理由：";
    cin>>reason;
    cout<<"请输入访问宿舍号：";
    while(1)
    {
        cin>>visitDorNum;
        pd=queryroom(visitDorNum);
        if(pd==NULL) cout<<"\n宿舍号错误！\n\n请重新输入：";
        else if(pd->use_dormitory()==0) cout<<"\n这是一间空宿舍！\n\n请重新选择：";
        else break;
    }

    visNum++;
    visitor[visNum].setVisitInformation(name,sex,visitTime,leaveTime,reason,visitDorNum);
    cout<<"\n来访者信息登记成功！"<<endl;
    Sleep(1000);
    system("cls");
}


/////////////////////////////////////////////
//出入管理函数
//函数功能：出入管理
//      1.早出登记
//      2.晚归登记
//      3.来访者登记
//函数参数：无
//参数返回值：无
//
void Function::get_in_out_manage()
{
    int choice=1;

    while(choice!=0)
    {
        cout<<"    出入管理："<<endl;
        cout<<"=================="<<endl;
        cout<<"|  1.早出登记    |"<<endl;
        cout<<"|  2.晚归登记    |"<<endl;
        cout<<"|  3.来访者登记  |"<<endl;
        cout<<"|  0.退出        |"<<endl;
        cout<<"=================="<<endl;
        cout<<"请输入选择：";
        cin>>choice;
        system("cls");

        if(choice<=3&&choice>=0)
        {
            switch(choice)
            {
            case 1://早出登记
                   morning_go_out();

                   break;

            case 2://晚归登记
                   evening_go_back();

                   break;

            case 3://来访者登记
                   visit_record();

                   break;
            }
        }
    }
}
