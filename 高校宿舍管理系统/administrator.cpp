//////////////////////////////////////////////
//
//文件名：administrator.cpp
//程序功能：管理员类的成员函数
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

using namespace std;


/////////////////////////////////////////////
//获取用户名函数
//函数功能：获取用户名
//函数参数：无
//参数返回值：字符串指针，指向用户名
//
char *Administrator::getUserName()
{return userName;}


/////////////////////////////////////////////
//获取密码函数
//函数功能：获取密码
//函数参数：无
//参数返回值：字符串指针，指向密码
//
char *Administrator::getPassword()
{return password;}


/////////////////////////////////////////////
//增加管理员函数
//函数功能：增加管理员
//函数参数：字符指针，以用户名和密码作为参数来新增管理员
//参数返回值：无
//
void Administrator::addAdministrator(char *na,char *pass)
{
    strcpy(userName,na);
    strcpy(password,pass);
}
