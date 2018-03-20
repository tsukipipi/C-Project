//////////////////////////////////////////////
//
//文件名：login.cpp
//程序功能：Function类的成员函数,登录管理模块
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>	     //getch函数头文件
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include "administrator.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//查询函数
//函数功能：查询用户名
//函数参数：字符型指针，指向要查找的用户名
//参数返回值：整型，1：查找成功 0：查找失败
//
int Function::queryUserName(char *na)
{
    for(int i=0;i<=adNum;i++)
    {
        //找到该用户名
        if(strcmp(administrator[i].getUserName(),na)==0)
            return 1;
    }
    return 0;
}


/////////////////////////////////////////////
//查询函数
//函数功能：查询用户
//函数参数：1.字符型指针*na，指向要查找的用户名
//          2.字符型指针*pass,指向要查找的用户密码
//参数返回值：整型，1：查找成功 0：查找失败
//
int Function::queryUser(char *na,char *pass)
{
    for(int i=0;i<=adNum;i++)
    {
        //找到该用户名和密码
        if(strcmp(administrator[i].getUserName(),na)==0&&strcmp(administrator[i].getPassword(),pass)==0)
            return 1;
        //用户名正确,密码错误
        if(strcmp(administrator[i].getUserName(),na)==0&&strcmp(administrator[i].getPassword(),pass)!=0)
            return 2;
    }
    return 0;
}


/////////////////////////////////////////////
//注册函数
//函数功能：管理员注册账号
//函数参数：无
//参数返回值：无
//
void Function::Register()
{
    int temp;
    char Name[20];
    char Password[20];

    while(1)
    {
        cout<<"用户名(20个字符以内)：";
        cin>>Name;
        temp=queryUserName(Name);
        if(temp==1)
        {
            cout<<"\n此用户名已存在！"<<endl;
            Sleep(1000);
            system("cls");
        }
        else break;
    }
    cout<<"密  码(20个字符以内)：";
    cin>>Password;

    //注册账号
    adNum++;
    administrator[adNum].addAdministrator(Name,Password);

    //验证是否注册成功
    temp=queryUser(Name,Password);
    if(temp==1)
    {
        cout<<"\n注册成功！"<<endl;
        Sleep(1000);
        system("cls");
    }
    else
    {
        cout<<"\n注册失败！"<<endl;
        Sleep(1000);
        system("cls");
    }
}


/////////////////////////////////////////////
//登录函数
//函数功能：管理员登录
//函数参数：无
//参数返回值：整型，1.登录成功，0：登录失败
//
int Function::sign_in()
{
    int index=0;        //用于将密码显示为*号
    int temp;
    char Name[20];
    char Password[20];

    cout<<"用户名(20个字符以内)：";
    cin>>Name;
    cout<<"密  码(20个字符以内)：";
    //以下代码块将输入的密码显示为*号
    while(1)
    {
        char ch;
        ch=getch();
        if(ch==8)//退格键'\b'
        {
            if(index!=0)
            {
                cout<<char(8)<<" "<<char(8);
                index--;
            }
        }
        else if(ch==13) //回车键'\r'
        {
            Password[index]='\0';
            cout<<endl;
            break;
        }
        else
        {
            cout<<"*";
            Password[index++]=ch;
        }
    }//密码星号end


    //登录操作
    temp=queryUser(Name,Password);

    //验证是否登录成功
    if(temp==1)
    {
        cout<<"\n登陆成功！"<<endl;
        Sleep(1000);
        system("cls");
        return 1;
    }
    if(temp==2)
    {
        cout<<"\n密码错误！"<<endl;
        Sleep(1000);
        system("cls");
    }
    if(temp==0)
    {
        cout<<"\n用户名不存在！"<<endl;
        Sleep(1000);
        system("cls");
    }
    return 0;
}


/////////////////////////////////////////////
//登录管理函数
//函数功能：登录管理
//      1.登录
//      2.注册
//      0.退出系统
//函数参数：无
//参数返回值：整型，1.登录成功，0：退出系统
//
int Function::login()
{
    int choice=1;

    while(1)
    {
        cout<<"欢迎使用“高校宿舍管理系统”："<<endl;
        cout<<"==========================="<<endl;
        cout<<"|       1.登录            |"<<endl;
        cout<<"|       2.注册            |"<<endl;
        cout<<"|       0.退出系统        |"<<endl;
        cout<<"==========================="<<endl;
        cout<<"请选择：";
        cin>>choice;
        system("cls");

        if(choice<=2&&choice>=0)
        {
            switch (choice)
            {
            case 1://登录
                   if(sign_in()==1)return 1;

                   break;

            case 2://注册
                   Register();

                   break;

            case 0://退出系统
                   return 0;

                   break;
            }//end switch
        }//end if
        else
        {
            cout<<"\n错误！没有此选项！"<<endl;
            Sleep(500);
        }
        system("cls");
    }//end while
}
