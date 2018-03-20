//////////////////////////////////////////////
//
//文件名：construction.cpp
//程序功能：Function类的构造函数
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
//构造函数
//函数功能：
//1.从student.dat文件读入Student类的对象数据
//2.从dormitory.dat文件读入Dormitory类的对象数据
//3.从visitor.dat文件读入Visitor类的对象数据
//4.从morning_evening_record.dat文件读入Morning_evening_record类的对象数据
//5.从administrator.dat文件读入Administrator类的对象数据
//函数参数：无
//参数返回值：无
//
Function::Function()
{

    //学生管理
    Student s;
    stuNum=-1;
    //以读入方式打开文件
    fstream file1("student.dat",ios::in|ios::binary);
    if(!file1)
    {
        cerr<<"student.dat无法正常打开!"<<endl;
        exit(1);
    }
    //读入学生的数据
    while(1)
    {
        file1.read((char*)&s,sizeof(s));
        if(!file1)break;     //如果读入完毕，终止循环
        stuNum++;
        student[stuNum]=s;
    }
    file1.close();





    //宿舍管理
    Dormitory d;
    dorNum=-1;
    //以读入方式打开文件
    fstream file2("dormitory.dat",ios::in|ios::binary);
    if(!file2)
    {
        cout<<"dormitory.dat无法正常打开！"<<endl;
        exit(1);
    }
    //读入宿舍的数据
    while(1)
    {
        file2.read((char*)&d,sizeof(d));
        if(!file2)break;     //如果读入完毕，终止循环
        dorNum++;
        dormitory[dorNum]=d;
    }
    file2.close();





    //出入管理


    //来访者
    Visitor v;
    visNum=-1;
    //以读入方式打开文件
    fstream file3("visitor.dat",ios::in|ios::binary);
    if(!file3)
    {
        cout<<"visitor.dat无法正常打开！"<<endl;
        exit(1);
    }
    //读入来访者的数据
    while(1)
    {
        file3.read((char*)&v,sizeof(v));
        if(!file3)break;     //如果读入完毕，终止循环
        visNum++;
        visitor[visNum]=v;
    }
    file3.close();



    //学生早出晚归
    Morning_Evening_record st;
    studNum=-1;
    //以读入方式打开文件
    fstream file4("morning_evening_record.dat",ios::in|ios::binary);
    if(!file4)
    {
        cout<<"morning_evening_record.dat无法正常打开！"<<endl;
        exit(1);
    }
    //读入早出晚归的数据
    while(1)
    {
        file4.read((char*)&st,sizeof(st));
        if(!file4)break;     //如果读入完毕，终止循环
        studNum++;
        stud[studNum]=st;
    }
    file4.close();





    //登录管理
    Administrator a;
    adNum=-1;
    //以读入方式打开文件
    fstream file5("administrator.dat",ios::in|ios::binary);
    if(!file5)
    {
        cout<<"administrator.dat无法正常打开！"<<endl;
        exit(1);
    }
    //读入管理员的数据
    while(1)
    {
        file5.read((char*)&a,sizeof(a));
        if(!file5)break;     //如果读入完毕，终止循环
        adNum++;
        administrator[adNum]=a;
    }
    file5.close();
}
