//////////////////////////////////////////////
//
//文件名：record.cpp
//程序功能：Morning_Evening_record类的成员函数
//          Visitor类的成员函数
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <string.h>

#include "record.h"

using namespace std;


//学生早出晚归登记


/////////////////////////////////////////////
//构造函数
//函数功能：初始化早出晚归此数为0
//函数参数：无
//参数返回值：无
//
Morning_Evening_record::Morning_Evening_record()
{
    morningTimes=0;
    eveningTimes=0;
}


/////////////////////////////////////////////
//get函数
//函数功能：获取学号
//函数参数：无
//参数返回值：整型，返回学生学号
//
int Morning_Evening_record::getNum()
{return studentNumber;}


/////////////////////////////////////////////
//早出登记函数
//函数功能：学生早出次数增加
//函数参数：无
//参数返回值：无
//
void Morning_Evening_record::morningRecord()
{morningTimes++;}


/////////////////////////////////////////////
//晚归登记函数
//函数功能：学生晚归次数增加
//函数参数：无
//参数返回值：无
//
void Morning_Evening_record::eveningRecord()
{eveningTimes++;}


/////////////////////////////////////////////
//添加函数
//函数功能：添加早出晚归的学生
//函数参数：字符型指针：指向姓名，整型：学号
//参数返回值：无
//
void Morning_Evening_record::addStud(char *na,int nu)
{
    strcpy(studentName,na);
    studentNumber=nu;
}


/////////////////////////////////////////////
//show函数
//函数功能：展示学生早出晚归信息
//函数参数：无
//参数返回值：无
//
void Morning_Evening_record::showStudentInformation()
{
    cout<<"\n姓名："<<studentName<<endl;
    cout<<"学号："<<studentNumber<<endl;
    cout<<"早出次数："<<morningTimes<<endl;
    cout<<"晚归此数："<<eveningTimes<<endl;
}




//来访者登记

/////////////////////////////////////////////
//set函数
//函数功能：设置来访者信息
//函数参数：字符型指针，字符型，指向来访者的各种信息
//参数返回值：无
//
void Visitor::setVisitInformation(char *na,char se,char *v_t,char *l_t,char *re,int dorNum)
{
    strcpy(visitorName,na);
    visitorSex=se;
    strcpy(visitTime,v_t);
    strcpy(leaveTime,l_t);
    strcpy(reason,re);
    visitDorNum=dorNum;
}


/////////////////////////////////////////////
//show函数
//函数功能：展示来访信息
//函数参数：无
//参数返回值：无
//
void Visitor::showVisitorInformation()
{
    cout<<"\n来访者姓名："<<visitorName<<endl;
    cout<<"来访者性别："<<visitorSex<<endl;
    cout<<"访问时间："<<visitTime<<endl;
    cout<<"离开时间："<<leaveTime<<endl;
    cout<<"来访原因："<<reason<<endl;
    cout<<"访问宿舍号："<<visitDorNum<<endl;
}
