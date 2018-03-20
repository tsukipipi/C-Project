//////////////////////////////////////////////
//
//文件名：dormitory.cpp
//程序功能：Dormitory类的成员函数
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>

#include "dormitory.h"

using namespace std;


/////////////////////////////////////////////
//构造函数
//函数功能：初始化床位信息为空
//函数参数：无
//参数返回值：无
//
Dormitory::Dormitory()
{
    for(int i=0;i<4;i++)
    {
        bed[i]=0;
        beduser[i]=0;
        bedNum[i]=i+1;
    }
}


/////////////////////////////////////////////
//get函数
//函数功能：获得宿舍号
//函数参数：无
//参数返回值：整型，宿舍号是整型变量
//
int Dormitory::getdormitoryNumber()
{return dormitoryNumber;}



/////////////////////////////////////////////
//get函数
//函数功能：获得宿舍的使用性别
//函数参数：无
//参数返回值：字符型，宿舍的使用性别是字符型变量
//
char Dormitory::getdormitorySex()
{return dormitorySex;}


/////////////////////////////////////////////
//get函数
//函数功能：获得删除标记
//函数参数：无
//参数返回值：布尔型，0：删除 1：未删
//
bool Dormitory::getdelNote()
{return delNote;}


/////////////////////////////////////////////
//get函数
//函数功能：获得宿舍的使用情况
//函数参数：无
//参数返回值：整型，返回一间宿舍床位已使用数量
//
int Dormitory::use_dormitory()
{
    int use_count=0;
    for(int i=0;i<4;i++)
        if(bed[i]==1)use_count++;
    return use_count;
}


/////////////////////////////////////////////
//get函数
//函数功能：获得具体某个床位的使用情况
//函数参数：整型，要获取信息的床位号
//参数返回值：布尔型，0：床位为空 1：床位不为空
//
bool Dormitory::bed_use_case(int bedNum)
{return bed[bedNum-1];}


/////////////////////////////////////////////
//展示函数
//函数功能：展示全部床位的使用情况
//函数参数：无
//参数返回值：无
//
void Dormitory::showbed()
{
    cout<<"\n床位使用情况:"<<endl;
    for(int i=0;i<4;i++)
    {
        if(bed[i])cout<<bedNum[i]<<"号床位:已使用  使用者学号："<<beduser[i]<<endl;
        else cout<<bedNum[i]<<"号床位:空床"<<endl;
    }
}


/////////////////////////////////////////////
//set函数
//函数功能：设置宿舍号
//函数参数：整型，宿舍号为整型变量
//参数返回值：无
//
void Dormitory::setdormitoryNumber(int dorNum)
{dormitoryNumber=dorNum;}


/////////////////////////////////////////////
//set函数
//函数功能：设置宿舍使用性别
//函数参数：字符型，宿舍使用性别为字符型变量
//参数返回值：无
//
void Dormitory::setdormitorySex(char sex)
{dormitorySex=sex;}


/////////////////////////////////////////////
//删除函数
//函数功能：删除宿舍
//函数参数：无
//参数返回值：无
//delNote为0：删除宿舍 1：未删除
//
void Dormitory::deletedormitory()
{delNote=0;}


/////////////////////////////////////////////
//空出床位函数
//函数功能：空出某个床位
//函数参数：整型，要空出床位的床位号
//  将床位使用情况和使用者均设置为0，即为空
//参数返回值：无
//
void Dormitory::not_use_bed(int bedNum)
{
    bed[bedNum-1]=0;
    beduser[bedNum-1]=0;
}


/////////////////////////////////////////////
//使用床位函数
//函数功能：使用某个床位
//函数参数：1.整型，bedNum为要空出床位的床位号
//          2.整型，num为使用者学号
//  将床位使用情况设置为1，表示不空，并填入使用者学号
//参数返回值：无
//
void Dormitory::use_bed(int bedNum,int num)
{
    bed[bedNum-1]=1;
    beduser[bedNum-1]=num;
}


/////////////////////////////////////////////
//增加宿舍函数
//函数功能：增加宿舍
//函数参数：1.整型，num为宿舍号
//          2.字符型，sex为宿舍使用性别
//参数返回值：无
//
void Dormitory::addDormitory(int num,char sex)
{
    dormitoryNumber=num;
    dormitorySex=sex;
    delNote=1;          //删除标记（0：删除 1：未删）
}
