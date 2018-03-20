////////////////////////////////////////////////////////
//
//文件名：main.cpp
//程序功能：
//    主函数，含初始界面登录入口和高校宿舍管理系统总菜单
//作者：Pipi
//日期：2016.10.15
//
////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //Sleep函数头文件

#include "administrator.h"
#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;

int main()
{
    system("color F3");             //修改界面颜色

    int choice=1;
    Function function_select;       //定义一个学生数据库类的对象


    //初始界面
    cout<<"\n\n\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<" D D        OO     R R     M       M   I I I   T T T     OO     R R     Y     Y"<<endl;
    cout<<" D   D     O  O    R   R   M M   M M     I       T      O  O    R   R    Y   Y "<<endl;
    cout<<" D    D   O    O   R R     M  M M  M     I       T     O    O   R R        Y   "<<endl;
    cout<<" D   D     O  O    R  R    M   M   M     I       T      O  O    R  R       Y   "<<endl;
    cout<<" D D        OO     R   R   M       M   I I I     T       OO     R   R      Y   "<<endl;
    cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
    cout<<"\n**************************正在进入“高校宿舍管理系统”**************************\n"<<endl;
    cout<<"\n--------------------------------------------------------------------------------"<<endl;
    Sleep(2000);        //停留时间单位是毫秒
    system("cls");      //页面清除


    //管理员登录、注册模块
    if(function_select.login()==0)
    {
        cout<<"\n正在退出系统..."<<endl;
        function_select.~Function();
        exit(1);
    }


    //功能选择模块
    while(choice!=0)
    {
        cout<<"   高校宿舍管理系统："<<endl;
        cout<<"------------------------"<<endl;
        cout<<"|  1.学生基本信息管理  |"<<endl;
        cout<<"|  2.住宿管理          |"<<endl;
        cout<<"|  3.出入管理          |"<<endl;
        cout<<"|  4.信息查询          |"<<endl;
        cout<<"|  0.退出系统          |"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"请输入选择：";
        cin>>choice;
        system("cls");

        if(choice<=4&&choice>=0)
        {
            switch(choice)
            {
            case 1://学生基本信息管理
                   function_select.studentdatabase();

                   break;

            case 2://住宿管理
                   function_select.dormitoryManage();

                   break;

            case 3://出入管理
                   function_select.get_in_out_manage();

                   break;

            case 4://信息查询
                   function_select.query_information();

                   break;

            case 0://退出系统
                   cout<<"正在退出系统..."<<endl;
                   function_select.~Function();
                   Sleep(1000);
                   exit(1);

                   break;
            }
        }
        else
        {
            cout<<"请输入正确的选择！"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while

    return 0;
}
