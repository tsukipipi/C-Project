//////////////////////////////////////////////
//
//文件名：destructor.cpp
//程序功能：Function类的析构函数
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "student.h"
#include "dormitory.h"
#include "function.h"
#include "record.h"

using namespace std;


/////////////////////////////////////////////
//析构函数
//函数功能：
//1.将Student类的对象数据写入student.dat文件
//2.将Dormitory类的对象数据写入dormitory.dat文件
//3.将Visitor类的对象数据写入visitor.dat文件
//4.将Morning_evening_record类的对象数据写入morning_evening_record.dat文件
//5.将Administrator类的对象数据写入administrator.dat文件
//函数参数：无
//参数返回值：无
//
Function::~Function()
{
    //学生管理
    fstream file1("student.dat",ios::out|ios::binary);
    if(!file1)
    {
        cout<<"student.dat文件无法正常打开！"<<endl;
        exit(1);
    }

    for(int i=0;i<=stuNum;i++)
        if(student[i].getnote()==1)
            file1.write((char*)&student[i],sizeof(student[i]));
    file1.close();





    //宿舍管理
    fstream file2("dormitory.dat",ios::out|ios::binary);
    if(!file2)
    {
        cout<<"dormitory.dat文件无法正常打开！"<<endl;
        exit(1);
    }

    for(int i=0;i<=dorNum;i++)
        if(dormitory[i].getdelNote()==1)
            file2.write((char*)&dormitory[i],sizeof(dormitory[i]));
    file2.close();





    //出入管理

    //来访者
    fstream file3("visitor.dat",ios::out|ios::binary);
    if(!file3)
    {
        cout<<"visitor.dat文件无法正常打开！"<<endl;
        exit(1);
    }

    for(int i=0;i<=visNum;i++)
        file3.write((char*)&visitor[i],sizeof(visitor[i]));
    file3.close();



    //学生早出晚归
    fstream file4("morning_evening_record.dat",ios::out|ios::binary);
    if(!file4)
    {
        cout<<"morning_evening_record.dat文件无法正常打开！"<<endl;
        exit(1);
    }

    for(int i=0;i<=studNum;i++)
        file4.write((char*)&stud[i],sizeof(stud[i]));
    file4.close();





    //登录管理
    fstream file5("administrator.dat",ios::out|ios::binary);
    if(!file5)
    {
        cout<<"administrator.dat文件无法正常打开！"<<endl;
        exit(1);
    }

    for(int i=0;i<=adNum;i++)
        file5.write((char*)&administrator[i],sizeof(administrator[i]));
    file5.close();
}


