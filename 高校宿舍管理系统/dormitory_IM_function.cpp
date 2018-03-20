//////////////////////////////////////////////
//
//文件名：dormitory_IM_function.cpp
//程序功能：Function类关于dormitory_IM的成员函数
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


//宿舍信息管理模块


/////////////////////////////////////////////
//查询函数
//函数功能：查询宿舍信息
//函数参数：整型，num为要查询的宿舍号
//参数返回值：Dormitory型指针，指向查找到的宿舍对象
//
Dormitory *Function::queryroom(int num)
{
    for(int i=0;i<=dorNum;i++)
    {
        if(num==dormitory[i].getdormitoryNumber()&&dormitory[i].getdelNote()==1)
            return &dormitory[i];
    }
    return NULL;
}


/////////////////////////////////////////////
//添加函数
//函数功能：增加宿舍
//函数参数：1.整型，num为新增宿舍的宿舍号
//          2.字符型，sex为新增宿舍的使用性别
//参数返回值：无
//
void Function::addDormitory(int num,char sex)
{
    pd=queryroom(num);
    if(pd==NULL)
    {
        dorNum++;
        dormitory[dorNum].addDormitory(num,sex);
        cout<<"\n添加成功！"<<endl;
    }
    else cout<<"\n添加失败！此宿舍已存在！"<<endl;
}


/////////////////////////////////////////////
//修改函数
//函数功能：修改宿舍信息
//      1.修改宿舍号
//      2.修改宿舍使用性别
//函数参数：Dormitory型指针，指向要修改信息的宿舍对象
//参数返回值：无
//
void Function::modifyDormitory(Dormitory *p)
{
    int select=1;
    int number;
    char sex;

    //宿舍为空才能修改信息
    if(p->use_dormitory()==0)
    {
        cout<<"\n这是一间空宿舍！可以进行信息修改！\n"<<endl;
        Sleep(1000);
        system("cls");
        while(select)
        {
            cout<<"      信息修改："<<endl;
            cout<<"======================="<<endl;
            cout<<"| 1.修改宿舍号        |"<<endl;
            cout<<"| 2.修改宿舍使用性别  |"<<endl;
            cout<<"| 0.退出              |"<<endl;
            cout<<"======================="<<endl;
            cout<<"请输入选择：";
            cin>>select;
            cout<<endl;
            system("cls");

            if(select<=2||select>=0)
            {
                switch(select)
                {
                case 1://修改宿舍号
                       cout<<"请输入新的宿舍号(3位数)：";
                       cin>>number;
                       if(number<=0||number>=1000)
                       {
                           cout<<"\n宿舍号错误！"<<endl;
                           Sleep(1000);
                           system("cls");
                           break;
                       }
                       pd=queryroom(number);
                       //判断宿舍号是否已经存在
                       if(pd==NULL)
                       {
                           p->setdormitoryNumber(number);
                           cout<<"\n设置成功！"<<endl;
                       }
                       else cout<<"\n此宿舍号已存在，无法修改！"<<endl;
                       Sleep(1000);
                       system("cls");

                       break;

                case 2://修改宿舍使用性别
                       cout<<"请输入新的宿舍使用性别(女宿舍：f 男宿舍：m)：";
                       cin>>sex;
                       if(sex=='f'||sex=='m')
                       {
                           p->setdormitorySex(sex);
                           cout<<"\n设置成功！"<<endl;
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
                }//end switch
            }//end if
            else
            {
                cout<<"请输入正确的选择！"<<endl;
                Sleep(500);
                system("cls");
            }
        }//end while
    }//end if
    else
    {
        cout<<"\n这间宿舍尚有学生居住！无法修改信息！"<<endl;
        cout<<"宿舍信息如下："<<endl;
        cout<<"\n宿舍号："<<pd->getdormitoryNumber()<<endl;
        cout<<"宿舍使用性别：";
        if(pd->getdormitorySex()=='f')cout<<"女";
        else cout<<"男";
        pd->showbed();
        Sleep(4000);
        system("cls");
    }
}


/////////////////////////////////////////////
//删除函数
//函数功能：删除宿舍
//函数参数：整型，room为要删除的宿舍号
//参数返回值：无
//
void Function::deleteDormitory(int room)
{
    pd=queryroom(room);
    if(pd==NULL)
    {
        cout<<"\n无法删除！该宿舍不存在！"<<endl;
        Sleep(1000);
    }
    else
    {
        if(pd->use_dormitory()==0)
        {
            pd->deletedormitory();
            cout<<"\n这是一间空宿舍！删除完毕！"<<endl;
            Sleep(1000);
        }
        else
        {
            cout<<"\n这间宿舍尚有学生居住！无法删除！"<<endl;
            cout<<"若要删除！请先调整这些学生的住所！"<<endl;
            cout<<"宿舍信息如下："<<endl;
            cout<<"\n宿舍号："<<pd->getdormitoryNumber()<<endl;
            cout<<"宿舍使用性别：";
            if(pd->getdormitorySex()=='f')cout<<"女";
            else cout<<"男";
            pd->showbed();
            Sleep(4000);
        }
    }
}
