//////////////////////////////////////////////
//
//文件名：dormitory_IM.cpp
//程序功能：Function类的成员函数,宿舍基本信息管理
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
//信息管理函数
//函数功能：宿舍基本信息管理菜单选项
//          1.添加宿舍
//          2.查询宿舍信息
//          3.修改宿舍信息
//          4.删除宿舍
//          0.退出
//函数参数：无
//参数返回值：无
//
void Function::dormitorydatabase()
{
    int choice=1;
    int roomNumber;
    char sex;

    while(choice!=0)
    {
        cout<<"    宿舍基本信息管理："<<endl;
        cout<<"========================"<<endl;
        cout<<"|    1.添加宿舍        |"<<endl;
        cout<<"|    2.查询宿舍信息    |"<<endl;
        cout<<"|    3.修改宿舍信息    |"<<endl;
        cout<<"|    4.删除宿舍        |"<<endl;
        cout<<"|    0.退出            |"<<endl;
        cout<<"========================"<<endl;
        cout<<"请输入选择：";
        cin>>choice;
        system("cls");

        if(choice<=4&&choice>=0)
        {
            switch(choice)
            {
            case 1://添加宿舍
                   cout<<"请输入要添加的宿舍号(3位数)：";
                   cin>>roomNumber;
                   if(roomNumber<=0||roomNumber>=1000)
                   {
                       cout<<"\n宿舍号错误！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   cout<<"请输入宿舍的使用性别(男生：m 女生：f)：";
                   cin>>sex;
                   //判断性别输入是否正确
                   if(sex=='f'||sex=='m')
                   {
                       addDormitory(roomNumber,sex);
                       Sleep(1000);
                       system("cls");
                   }
                   else
                   {
                       cout<<"\n性别输入错误！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }

                   break;

            case 2://查询宿舍信息
                   cout<<"请输入要查询的宿舍的宿舍号(3位数)：";
                   cin>>roomNumber;
                   if(roomNumber<=0||roomNumber>=1000)
                   {
                       cout<<"\n宿舍号错误！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   pd=queryroom(roomNumber);
                   if(pd==NULL)
                   {
                       cout<<"\n未找到此宿舍！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //展示宿舍信息
                   cout<<"\n宿舍号："<<pd->getdormitoryNumber()<<endl;
                   cout<<"宿舍使用性别：";
                   if(pd->getdormitorySex()=='f')cout<<"女";
                   else cout<<"男";
                   pd->showbed();
                   Sleep(4000);
                   system("cls");

                   break;

            case 3://修改宿舍信息
                   cout<<"请输入要修改的宿舍的宿舍号(3位数)：";
                   cin>>roomNumber;
                   if(roomNumber<=0||roomNumber>=1000)
                   {
                       cout<<"\n宿舍号错误！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   pd=queryroom(roomNumber);
                   if(pd==NULL)
                   {
                       cout<<"\n无法修改！该宿舍不存在！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   modifyDormitory(pd);

                   break;

            case 4://删除宿舍
                   cout<<"请输入要删除的宿舍号：";
                   cin>>roomNumber;
                   if(roomNumber<0)
                   {
                       cout<<"\n宿舍号错误！"<<endl;
                       break;
                   }
                   deleteDormitory(roomNumber);
                   system("cls");

                   break;
            }
        }
        else
        {
            cout<<"请输入正确的选择！"<<endl;
            Sleep(500);
            system("cls");
        }
    }
}
