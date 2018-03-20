//////////////////////////////////////////////
//
//文件名：query_information.cpp
//程序功能：Function类的成员函数,实现各种信息查询
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
#include "record.h"

using namespace std;


/////////////////////////////////////////////
//求最大公约数函数
//函数功能：辗转相除法求最大公约数
//函数参数：整型m，n
//参数返回值：整型，返回最大公约数
//
int greatest_common_divisor(int m,int n)
{
    int a,b;
    if(n>m) {a=m;m=n;n=a;}//确保大数除小数
    while(m%n!=0)
    {b=m%n;m=n;n=b;}
    return n;
}



/////////////////////////////////////////////
//信息查询函数
//函数功能：信息查询
//      1.查询学生信息含住宿信息
//      2.查询宿舍信息含住宿信息
//      3.查询早出晚归信息
//      4.查询来访者信息
//      5.查询入宿人数
//      6.查询宿舍空床情况
//      7.查询住宿男女比例
//函数参数：无
//参数返回值：无
//
void Function::query_information()
{
    int choice=1;
    int studentNum;
    int roomNum;
    int countStu;//在宿人数
    int count,boyNum,girlNum;
    int n;  //最大公约数

    while(choice!=0)
    {
        cout<<"            信息查询："<<endl;
        cout<<"================================="<<endl;
        cout<<"|   1.查询学生信息含住宿信息    |"<<endl;
        cout<<"|   2.查询宿舍信息含住宿信息    |"<<endl;
        cout<<"|   3.查询早出晚归信息          |"<<endl;
        cout<<"|   4.查询来访者信息            |"<<endl;
        cout<<"|   5.查询入宿人数              |"<<endl;
        cout<<"|   6.查询宿舍空床情况          |"<<endl;
        cout<<"|   7.查询住宿男女比例          |"<<endl;
        cout<<"|   0.退出                      |"<<endl;
        cout<<"================================="<<endl;
        cout<<"请输入选择：";
        cin>>choice;
        system("cls");

        if(choice<=7&&choice>=0)
        {
            switch(choice)
            {
            case 1://查询学生信息
                   cout<<"请输入想要查询的学生的学号(4位数字)：";
                   cin>>studentNum;
                   ps=queryNum(studentNum);
                   if(ps==NULL)
                   {
                       cout<<"\n无法找到此学生！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   ps->show();
                   Sleep(5000);
                   system("cls");

                   break;

            case 2://查询宿舍信息
                   cout<<"请输入要查询的宿舍的宿舍号：";
                   cin>>roomNum;
                   if(roomNum<=0)
                   {
                       cout<<"\n宿舍号错误！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   pd=queryroom(roomNum);
                   if(pd==NULL)
                   {
                       cout<<"\n未找到此宿舍！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   cout<<"\n宿舍信息如下："<<endl;
                   cout<<"\n宿舍号："<<pd->getdormitoryNumber()<<endl;
                   cout<<"\n宿舍使用性别：";
                   if(pd->getdormitorySex()=='f')cout<<"女"<<endl;
                   else cout<<"男"<<endl;
                   pd->showbed();
                   Sleep(5000);
                   system("cls");

                   break;

            case 3://查询早出晚归信息
                   cout<<"早出晚归学生名单：\n"<<endl;
                   for(int i=0;i<=studNum;i++)
                       stud[i].showStudentInformation();

                   Sleep(8000);
                   system("cls");

                   break;

            case 4://查询来访者信息
                   cout<<"来访者信息如下：\n"<<endl;
                   for(int i=0;i<=visNum;i++)
                       visitor[i].showVisitorInformation();

                   Sleep(10000);
                   system("cls");

                   break;

            case 5://查询入宿人数
                   count=0;
                   for(int i=0;i<=stuNum;i++)
                      if(student[i].getnote()==1)count++;
                   cout<<"学生人数："<<count<<endl;
                   //将统计入宿人数的计数机初始化为0
                   countStu=0;
                   for(int i=0;i<=stuNum;i++)
                       if(student[i].getnote()==1&&student[i].getmark()==1)//未删除并且处于入宿状态
                           countStu++;
                   cout<<"\n在宿人数："<<countStu<<endl;

                   Sleep(1000);
                   system("cls");

                   break;

            case 6://查询宿舍空床情况
                   cout<<"以下宿舍尚有空床位："<<endl;
                   cout<<"宿舍号  使用性别"<<endl;
                   for(int i=0;i<=dorNum;i++)
                       if(dormitory[i].use_dormitory()<4)
                       {
                           cout<<' '<<dormitory[i].getdormitoryNumber()<<"       ";
                           if(dormitory[i].getdormitorySex()=='f')cout<<"女"<<endl;
                           else cout<<"男"<<endl;
                       }

                   Sleep(10000);
                   system("cls");

                   break;

            case 7://查询住宿男女比例
                   count=0;boyNum=0;girlNum=0;
                   for(int i=0;i<=stuNum;i++)
                      if(student[i].getnote()==1)count++;
                   cout<<"学生人数："<<count<<endl;
                   for(int i=0;i<=stuNum;i++)
                   {
                       if(student[i].getsex()=='f'&&student[i].getnote()==1)girlNum++;
                       else if(student[i].getsex()=='m'&&student[i].getnote()==1)boyNum++;
                   }
                   n=greatest_common_divisor(boyNum,girlNum);
                   cout<<"\n住宿男女比例："<<boyNum/n<<':'<<girlNum/n<<endl;

                   Sleep(1000);
                   system("cls");

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
}
