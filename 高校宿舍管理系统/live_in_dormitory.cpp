//////////////////////////////////////////////
//
//文件名：live_in_dormitory.cpp
//程序功能：Function类的成员函数,学生登记入宿
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
//入宿登记函数
//函数功能：入宿登记
//函数参数：无
//参数返回值：无
//
void Function::liveDormitory()
{
    int studentNumber;

    cout<<"请输入学生的学号：";
    cin>>studentNumber;

    ps=queryNum(studentNumber);
    if(ps==NULL)cout<<"\n未找到此学生！"<<endl;
    else if(ps->getmark()==1) cout<<"\n该学生已经入宿，无法重复登记入宿！"<<endl;
    else if(ps->getroomNumber()==0) cout<<"\n请先为学生分配宿舍！"<<endl;
    else
    {
        //记上入宿标记
        ps->live();
        if(ps->getmark()==1)cout<<"\n学生成功登记入宿！"<<endl;
        else cout<<"\n错误！学生登记入宿失败！"<<endl;
    }
    Sleep(1000);
    system("cls");
}
