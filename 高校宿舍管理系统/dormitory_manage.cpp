//////////////////////////////////////////////
//
//�ļ�����dormitory_manage.cpp
//�����ܣ�Function��ĳ�Ա������ס�޹���˵�
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;



/////////////////////////////////////////////
//ס�޹�����
//�������ܣ�ס�޹���
//          1.���������Ϣ����
//          2.����������
//          3.���޵Ǽ�
//          4.���޴���
//          5.���޴���
//������������
//��������ֵ����
//
void Function::dormitoryManage()
{
    int choice=1;

    while(choice!=0)
    {
        cout<<"       ס�޹���"<<endl;
        cout<<"========================"<<endl;
        cout<<"| 1.���������Ϣ����   |"<<endl;
        cout<<"| 2.����������       |"<<endl;
        cout<<"| 3.���޵Ǽ�           |"<<endl;
        cout<<"| 4.���޴���           |"<<endl;
        cout<<"| 5.���޴���           |"<<endl;
        cout<<"| 0.�˳�               |"<<endl;
        cout<<"========================"<<endl;
        cout<<"������ѡ��";
        cin>>choice;
        system("cls");

        if(choice<=5&&choice>=0)
        {
            switch(choice)
            {
            case 1://���������Ϣ����
                   dormitorydatabase();

                   break;

            case 2://����������
                   allotDormitory();

                   break;

            case 3://���޵Ǽ�
                   liveDormitory();

                   break;

            case 4://���޴���
                   leaveDormitory();

                   break;

            case 5://���޴���
                   adjustDormitory();

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
