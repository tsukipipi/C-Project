//////////////////////////////////////////////
//
//文件名：adjust_dormitory.cpp
//程序功能：Function类的成员函数,调整学生宿舍
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
//调宿处理函数
//函数功能：调整学生宿舍
//函数参数：无
//参数返回值：无
//
void Function::adjustDormitory()
{
    Student *p1,*p2;
    int select=1;
    int stuNum1,stuNum2;
    int temp_roomNum,temp_bed;
    int roomNum,bed;

    while(select!=0)
    {
        cout<<"        调宿管理："<<endl;
        cout<<"=========================="<<endl;
        cout<<"|  1.两学生交换宿舍      |"<<endl;
        cout<<"|  2.调整一名学生的宿舍  |"<<endl;
        cout<<"|  0.回退                |"<<endl;
        cout<<"=========================="<<endl;
        cout<<"请输入选择：";
        cin>>select;
        system("cls");

        if(select<=2&&select>=0)
        {
            switch(select)
            {
            case 1://两学生互换宿舍
                   while(1)
                   {
                       cout<<"请输入想要调整宿舍的两学生的学号：";
                       cout<<"\n学生1：";
                       cin>>stuNum1;
                       cout<<"学生2：";
                       cin>>stuNum2;
                       if(stuNum2!=stuNum1)break;
                       cout<<"\n两学生学号相同！出错！\n"<<endl;
                       Sleep(1000);
                       system("cls");
                   }

                   p1=queryNum(stuNum1);
                   p2=queryNum(stuNum2);
                   if(p1!=NULL&&p2!=NULL)
                   {
                       //先确认两学生性别相同
                       if(p1->getsex()==p2->getsex())
                       {
                           //展示目前的情况
                           cout<<"\n两学生信息如下："<<endl;
                           p1->show();
                           p2->show();
                           Sleep(6000);
                           system("cls");

                           //交换两个人的宿舍
                           temp_roomNum=p1->getroomNumber();
                           temp_bed=p1->getbedNumber();
                           p1->setroom_bed(p2->getroomNumber(),p2->getbedNumber());
                           p2->setroom_bed(temp_roomNum,temp_bed);

                           //修改两间宿舍的信息

                           //学生1
                           pd=queryroom(p1->getroomNumber());
                           if(pd==NULL)
                           {
                               cout<<"\n无法找到学生所属宿舍！"<<endl;
                               Sleep(1000);
                               system("cls");
                               break;
                           }
                           pd->use_bed(p1->getbedNumber(),p1->getnumber());
                           //学生2
                           pd=queryroom(p2->getroomNumber());
                           if(pd==NULL)
                           {
                               cout<<"\n无法找到学生所属宿舍！"<<endl;
                               Sleep(1000);
                               system("cls");
                               break;
                           }
                           pd->use_bed(p2->getbedNumber(),p2->getnumber());

                           //展示新的情况
                           cout<<"\n交换宿舍之后信息如下："<<endl;
                           p1->show();
                           p2->show();
                           Sleep(6000);
                           system("cls");
                       }//end if 判断两学生性别是否相同
                       else
                       {
                           cout<<"\n两学生的性别不同，无法交换宿舍！"<<endl;
                           Sleep(1000);
                           system("cls");
                       }
                   }//end if 判断是否可以找到学生
                   else
                   {
                       cout<<"\n学号错误！无法找到学生！"<<endl;
                       Sleep(1000);
                       system("cls");
                   }

                   break;

            case 2://调整一学生宿舍
                   cout<<"请输入想要调整宿舍的学生的学号：";
                   cin>>stuNum1;

                   ps=queryNum(stuNum1);
                   if(ps==NULL)
                   {
                       cout<<"\n未找到此学生！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }


                   //调整前

                   //找到所有有空床位的宿舍
                   cout<<"\n以下宿舍尚有空床位：\n"<<endl;
                   cout<<"宿舍号  使用性别"<<endl;
                   for(int i=0;i<=dorNum;i++)
                   {
                       if(dormitory[i].use_dormitory()<4)
                       {
                            cout<<' '<<dormitory[i].getdormitoryNumber()<<"       ";
                            if(dormitory[i].getdormitorySex()=='f')cout<<"女"<<endl;
                            else cout<<"男"<<endl;
                       }
                   }
                   //打印学生信息
                   cout<<"\n学生信息如下："<<endl;
                   ps->show();

                   Sleep(5000);
                   system("cls");

                   cout<<"请输入要调整的宿舍号：";
                   cin>>roomNum;

                   pd=queryroom(roomNum);
                   if(pd==NULL)
                   {
                       cout<<"\n该宿舍不存在！"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //判断宿舍使用性别与学生性别是否一致
                   if(pd->getdormitorySex()==ps->getsex())
                   {
                       cout<<"\n宿舍信息如下："<<endl;
                       cout<<"宿舍号："<<pd->getdormitoryNumber()<<endl;
                       cout<<"使用性别：";
                       if(pd->getdormitorySex()=='f')cout<<"女"<<endl;
                       else cout<<"男"<<endl;
                       pd->showbed();

                       cout<<"\n请输入床位号，选择一个空床：";
                       cin>>bed;
                       if(bed>4||bed<1)
                       {
                           cout<<"\n床位号出错！"<<endl;
                           Sleep(1000);
                           system("cls");
                           break;
                       }

                       if(pd->bed_use_case(bed)==0)
                       {
                           //调整宿舍
                           temp_bed=ps->getbedNumber();
                           temp_roomNum=ps->getroomNumber();
                           ps->setroom_bed(roomNum,bed);

                           //将学生信息填入新的宿舍中
                           pd->use_bed(bed,ps->getnumber());

                           //将原来宿舍的信息删去
                           pd=queryroom(temp_roomNum);
                           pd->not_use_bed(temp_bed);
                           system("cls");

                           //调整后
                           cout<<"\n换宿舍之后信息如下："<<endl;
                           ps->show();
                           Sleep(3000);
                           system("cls");
                       }//end if 判断该床位是否已被使用
                       else
                       {
                           cout<<"\n该床位已被使用！"<<endl;
                           Sleep(1000);
                           system("cls");
                       }
                   }//end if 判断宿舍使用性别与学生性别是否一致
                   else
                   {
                       cout<<"\n宿舍使用性别与学生性别不一致，无法换宿舍！"<<endl;
                       Sleep(1000);
                       system("cls");
                   }

                   break;
            }//end switch
        }//end if
        else
        {
            cout<<"请输入正确选择！"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while
}
