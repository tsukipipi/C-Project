//////////////////////////////////////////////
//
//文件名：allot_dormitory.cpp
//程序功能：Function类的成员函数,分配学生宿舍
//作者：Pipi
//日期：2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <algorithm>     //sort函数
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//分配宿舍函数
//函数功能：分配宿舍
//函数参数：无
//参数返回值：无
//
void Function::allotDormitory()
{
    int tempBoyNum[Maxs],tempGirlNum[Maxs],girlNum,boyNum;//用于批量分配时分性别学号排序
    int roomNum,count;
    int studentNumber;
    int select=1,opt=1;
    int room,bed;

    while(select)
    {
        cout<<"            宿舍分配管理："<<endl;
        cout<<"======================================="<<endl;
        cout<<"| 1.人工安排宿舍&床位                 |"<<endl;
        cout<<"| 2.系统批量安排宿舍&床位(按学号分配) |"<<endl;
        cout<<"| 0.退出                              |"<<endl;
        cout<<"======================================="<<endl;
        cout<<"请输入选择：";
        cin>>select;
        cout<<endl;
        system("cls");

        if(select<=2&&select>=0)
        {
            switch(select)
            {
            case 1://人工安排床位
                   cout<<"请输入学生的学号：";
                   cin>>studentNumber;
                   //查找并判断学生是否存在
                   ps=queryNum(studentNumber);
                   if(ps==NULL)
                   {
                       cout<<"\n无法找到该学生！"<<endl;
                       Sleep(1000);
                       break;
                   }


                   //若学生尚未分配到床位
                   if(ps->getroomNumber()==0||ps->getbedNumber()==0)
                   {

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

                       //打印出学生信息
                       cout<<"\n学生信息如下："<<endl;
                       ps->show();

                       Sleep(5000);
                       system("cls");

                       while(1)
                       {
                           cout<<"请为该学生分配宿舍及床位：\n"<<endl;
                           cout<<"请输入宿舍号：";
                           cin>>room;

                           //查找这间宿舍
                           pd=queryroom(room);
                           if(pd==NULL)
                           {
                               cout<<"\n不存在此宿舍！"<<endl;
                               Sleep(1000);
                               system("cls");
                               break;
                           }
                           else
                           {
                               //学生性别与宿舍使用性别一致才能分配床位
                               if(ps->getsex()==pd->getdormitorySex())
                               {
                                   system("cls");
                                   //展示床位使用情况，再做出选择
                                   pd->showbed();

                                   cout<<"\n\n================"<<endl;
                                   cout<<"|  1.选择床位  |"<<endl;
                                   cout<<"|  0.回退      |"<<endl;
                                   cout<<"================"<<endl;
                                   cout<<"请选择：";
                                   cin>>opt;

                                   if(opt==1)
                                   {
                                       //选择床位
                                       cout<<"\n请输入床位号(1~4)：";
                                       cin>>bed;
                                       //判断床位是否已被使用
                                       if(pd->bed_use_case(bed)==1)
                                       {
                                           cout<<"\n这张床已被使用！"<<endl;
                                           Sleep(1000);
                                           system("cls");
                                       }
                                       else
                                       {
                                           system("cls");
                                           //使用床位
                                           ps->setroom_bed(room,bed);
                                           pd->use_bed(bed,ps->getnumber());
                                           //显示学生信息
                                           cout<<"分配成功！新的学生信息如下：\n"<<endl;
                                           ps->show();
                                           Sleep(4000);
                                           system("cls");
                                           break;
                                       }
                                   }
                                   if(opt!=0&&opt!=1)
                                   {
                                       cout<<"\n请输入正确的选择！"<<endl;
                                       Sleep(500);
                                   }
                                   system("cls");
                               }//end if 判断性别是否相符
                               else
                               {
                                   cout<<"\n宿舍使用性别不符合！"<<endl;
                                   Sleep(1000);
                                   system("cls");
                               }
                            }//end else 判断宿舍是否存在
                       }//end while
                   }//end if 判断学生是否已经分配了床位
                   else
                   {
                       //打印出学生信息
                       ps->show();

                       cout<<"\n该学生已经分配了床位！"<<endl;
                       Sleep(2000);
                       system("cls");
                   }

                   break;

            case 2://系统批量安排床位，按学号进行分配
                   //初始化学生数组的学生数量
                   boyNum=-1;
                   girlNum=-1;

                   cout<<"正在分配中. . ."<<endl;
                   Sleep(1000);

                   //先将学生们的学号按照性别存储在数组中，以便排序
                   for(int i=0;i<=stuNum;i++)
                   {
                       //挑出未被删除的学生
                       if(student[i].getnote()!=0)
                       {
                           if(student[i].getsex()=='m')
                           {
                               boyNum++;
                               tempBoyNum[boyNum]=student[i].getnumber();
                           }
                           else
                           {
                               girlNum++;
                               tempGirlNum[girlNum]=student[i].getnumber();
                           }
                       }
                   }
                   //按学号排序，从小到大
                   sort(tempBoyNum,tempBoyNum+boyNum+1);
                   sort(tempGirlNum,tempGirlNum+girlNum+1);


                   //分配宿舍&床位

                   //男生
                   roomNum=0;
                   count=1;          //用于计数，每四个换一间宿舍
                   for(int i=0;i<=boyNum;i++)
                   {
                       //先判断宿舍够不够
                       if(roomNum>dorNum)
                       {
                           cout<<"\n男生宿舍数量不够！请先添加宿舍！"<<endl;
                           Sleep(1000);
                           break;
                       }
                       //先找到该学生
                       ps=queryNum(tempBoyNum[i]);
                       if(ps==NULL)
                       {
                           cout<<"\n出错！无法找到学生！"<<endl;
                           break;
                       }

                       if(count>4)
                       {
                           roomNum++;
                           count=1;     //一间宿舍床位共4个
                       }

                       while(1)
                       {
                           //先判断宿舍够不够
                           if(roomNum>dorNum) break;
                           //分配宿舍&床位
                           if(dormitory[roomNum].getdormitorySex()=='m')
                           {
                               //将床位信息登记到学生的信息中
                               ps->setroom_bed(dormitory[roomNum].getdormitoryNumber(),count);
                               dormitory[roomNum].use_bed(count,tempBoyNum[i]);
                               count++;
                               break;
                           }
                           else roomNum++;
                       }
                   }

                   //女生
                   roomNum=0;
                   count=1;          //用于计数，每四个换一间宿舍
                   for(int i=0;i<=girlNum;i++)
                   {
                       //先判断宿舍够不够
                       if(roomNum>dorNum)
                       {
                           cout<<"\n女生宿舍数量不够！请先添加宿舍！"<<endl;
                           Sleep(1000);
                           break;
                       }
                       //先找到该学生
                       ps=queryNum(tempGirlNum[i]);
                       if(ps==NULL)
                       {
                           cout<<"\n出错！无法找到学生！"<<endl;
                           break;
                       }

                       if(count>4)
                       {
                           roomNum++;
                           count=1;     //一间宿舍床位共4个
                       }

                       while(1)
                       {
                           //判断宿舍够不够
                           if(roomNum>dorNum) break;
                           //分配宿舍&床位
                           if(dormitory[roomNum].getdormitorySex()=='f')
                           {
                               //将床位信息登记到学生的信息中
                               ps->setroom_bed(dormitory[roomNum].getdormitoryNumber(),count);
                               dormitory[roomNum].use_bed(count,tempGirlNum[i]);
                               count++;
                               break;
                           }
                           else roomNum++;
                       }//end while
                   }//end for

                   break;
            }//end switch
            system("cls");
        }//end if
        else
        {
            cout<<"请输入正确的选择！"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while
}
