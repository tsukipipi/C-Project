//////////////////////////////////////////////
//
//文件名：dormitory_manage.cpp
//程序功能：Function类的成员函数，住宿管理菜单
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;



/////////////////////////////////////////////
//住宿管理函数
//函数功能：住宿管理
//          1.宿舍基本信息管理
//          2.宿舍分配管理
//          3.入宿登记
//          4.退宿处理
//          5.调宿处理
//函数参数：无
//参数返回值：无
//
void Function::dormitoryManage()
{
    int choice=1;

    while(choice!=0)
    {
        cout<<"       住宿管理："<<endl;
        cout<<"========================"<<endl;
        cout<<"| 1.宿舍基本信息管理   |"<<endl;
        cout<<"| 2.宿舍分配管理       |"<<endl;
        cout<<"| 3.入宿登记           |"<<endl;
        cout<<"| 4.退宿处理           |"<<endl;
        cout<<"| 5.调宿处理           |"<<endl;
        cout<<"| 0.退出               |"<<endl;
        cout<<"========================"<<endl;
        cout<<"请输入选择：";
        cin>>choice;
        system("cls");

        if(choice<=5&&choice>=0)
        {
            switch(choice)
            {
            case 1://宿舍基本信息管理
                   dormitorydatabase();

                   break;

            case 2://宿舍分配管理
                   allotDormitory();

                   break;

            case 3://入宿登记
                   liveDormitory();

                   break;

            case 4://退宿处理
                   leaveDormitory();

                   break;

            case 5://调宿处理
                   adjustDormitory();

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
