//////////////////////////////////////////////
//
//文件名：leave_dormitory.cpp
//程序功能：Function类的成员函数,处理退宿相关功能
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//退宿处理函数
//函数功能：退宿处理
//      1.人工退宿
//      2.批量退宿
//函数参数：无
//参数返回值：无
//
void Function::leaveDormitory()
{
    int select=1;
    int studentNumber;

    while(select)
    {
        cout<<"   退宿处理："<<endl;
        cout<<"================="<<endl;
        cout<<"|  1.人工退宿   |"<<endl;
        cout<<"|  2.批量退宿   |"<<endl;
        cout<<"|  0.退出       |"<<endl;
        cout<<"================="<<endl;
        cout<<"请输入选择：";
        cin>>select;
        system("cls");

        if(select>=0&&select<=2)
        {
            switch(select)
            {
            case 1://人工退宿
                   cout<<"请输入要退宿的学生的学号：";
                   cin>>studentNumber;
                   ps=queryNum(studentNumber);
                   //先判断是否可以找到该学生
                   if(ps==NULL)
                   {
                       cout<<"\n该学生不存在！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //再判断该学生是否已经有入宿登记
                   else if(ps->getmark()==0)
                   {
                       cout<<"\n无法退宿，该学生未登记入宿！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //退宿并删除学生
                   ps->leave();
                   if(ps->getmark()==0)
                   {
                       //找到宿舍，空出床位
                       pd=queryroom(ps->getroomNumber());
                       if(pd==NULL)
                       {
                           cout<<"\n错误！无法找到该学生所在宿舍！"<<endl;
                           Sleep(1000);
                           system("cls");
                           break;
                       }
                       pd->not_use_bed(ps->getbedNumber());
                       ps->delstudent();
                       cout<<"\n退宿成功！"<<endl;
                       Sleep(1000);
                   }
                   else
                   {
                       cout<<"\n退宿失败！"<<endl;
                       Sleep(1000);
                   }
                   system("cls");

                   break;

            case 2://批量退宿
                   cout<<"批量退宿中..."<<endl;
                   Sleep(1000);

                   //学生标上退宿标记并删除
                   for(int i=0;i<stuNum;i++)
                   {
                       //判断学生是否已经入宿
                       if(student[i].getmark()==1)
                       {
                           student[i].leave();
                           if(student[i].getmark()==0)
                           {
                               //将学生的信息从宿舍中删除
                               pd=queryroom(student[i].getroomNumber());
                               if(pd==NULL)
                               {
                                   cout<<"\n错误！无法找到该学生所在宿舍！"<<endl;
                                   Sleep(1000);
                                   system("cls");
                                   break;
                               }
                               pd->not_use_bed(ps->getbedNumber());
                           }
                           student[i].delstudent();
                       }
                   }
                   system("cls");

                   break;
            }//end switch
        }//end if
        else
        {
            cout<<"请输入正确的选择！"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while
}
