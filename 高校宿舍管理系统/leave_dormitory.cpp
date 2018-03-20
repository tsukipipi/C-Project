//////////////////////////////////////////////
//
//�ļ�����leave_dormitory.cpp
//�����ܣ�Function��ĳ�Ա����,����������ع���
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//���޴�����
//�������ܣ����޴���
//      1.�˹�����
//      2.��������
//������������
//��������ֵ����
//
void Function::leaveDormitory()
{
    int select=1;
    int studentNumber;

    while(select)
    {
        cout<<"   ���޴���"<<endl;
        cout<<"================="<<endl;
        cout<<"|  1.�˹�����   |"<<endl;
        cout<<"|  2.��������   |"<<endl;
        cout<<"|  0.�˳�       |"<<endl;
        cout<<"================="<<endl;
        cout<<"������ѡ��";
        cin>>select;
        system("cls");

        if(select>=0&&select<=2)
        {
            switch(select)
            {
            case 1://�˹�����
                   cout<<"������Ҫ���޵�ѧ����ѧ�ţ�";
                   cin>>studentNumber;
                   ps=queryNum(studentNumber);
                   //���ж��Ƿ�����ҵ���ѧ��
                   if(ps==NULL)
                   {
                       cout<<"\n��ѧ�������ڣ�"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //���жϸ�ѧ���Ƿ��Ѿ������޵Ǽ�
                   else if(ps->getmark()==0)
                   {
                       cout<<"\n�޷����ޣ���ѧ��δ�Ǽ����ޣ�"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //���޲�ɾ��ѧ��
                   ps->leave();
                   if(ps->getmark()==0)
                   {
                       //�ҵ����ᣬ�ճ���λ
                       pd=queryroom(ps->getroomNumber());
                       if(pd==NULL)
                       {
                           cout<<"\n�����޷��ҵ���ѧ���������ᣡ"<<endl;
                           Sleep(1000);
                           system("cls");
                           break;
                       }
                       pd->not_use_bed(ps->getbedNumber());
                       ps->delstudent();
                       cout<<"\n���޳ɹ���"<<endl;
                       Sleep(1000);
                   }
                   else
                   {
                       cout<<"\n����ʧ�ܣ�"<<endl;
                       Sleep(1000);
                   }
                   system("cls");

                   break;

            case 2://��������
                   cout<<"����������..."<<endl;
                   Sleep(1000);

                   //ѧ���������ޱ�ǲ�ɾ��
                   for(int i=0;i<stuNum;i++)
                   {
                       //�ж�ѧ���Ƿ��Ѿ�����
                       if(student[i].getmark()==1)
                       {
                           student[i].leave();
                           if(student[i].getmark()==0)
                           {
                               //��ѧ������Ϣ��������ɾ��
                               pd=queryroom(student[i].getroomNumber());
                               if(pd==NULL)
                               {
                                   cout<<"\n�����޷��ҵ���ѧ���������ᣡ"<<endl;
                                   Sleep(1000);
                                   system("cls");
                                   break;
                               }
                               pd->not_use_bed(ps->getbedNumber());
                           }
                           student[i].delstudent();
                       }
                   }
                   system("cls");

                   break;
            }//end switch
        }//end if
        else
        {
            cout<<"��������ȷ��ѡ��"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while
}
