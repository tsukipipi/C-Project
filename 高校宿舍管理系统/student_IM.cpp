//////////////////////////////////////////////
//
//�ļ�����student_IM.cpp
//�����ܣ�Function��ĳ�Ա����,ѧ��������Ϣ����
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <algorithm>     //sort����
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//ѧ��������Ϣ������
//�������ܣ�ѧ��������Ϣ����
//      1.���ѧ��
//      2.��ѯѧ����Ϣ
//      3.�޸�ѧ����Ϣ
//      4.ɾ��ѧ��
//������������
//��������ֵ����
//
void Function::studentdatabase()
{
    int choice=1;
    int number;
    char name[15];
    char sex;
    char phone[15];

    while(choice!=0)
    {
        cout<<"    ѧ��������Ϣ����"<<endl;
        cout<<"========================"<<endl;
        cout<<"|    1.���ѧ��        |"<<endl;
        cout<<"|    2.��ѯѧ����Ϣ    |"<<endl;
        cout<<"|    3.�޸�ѧ����Ϣ    |"<<endl;
        cout<<"|    4.ɾ��ѧ��        |"<<endl;
        cout<<"|    0.�˳�            |"<<endl;
        cout<<"========================"<<endl;
        cout<<"������ѡ��";
        cin>>choice;
        system("cls");

        if(choice<=4&&choice>=0)
        {
            switch(choice)
            {
            case 1://���ѧ��
                   cout<<"������ѧ����������";
                   cin>>name;
                   cout<<"������ѧ����ѧ��(4λ����)��";
                   cin>>number;
                   cout<<"������ѧ�����Ա�(������m Ů����f)��";
                   cin>>sex;
                   cout<<"������ѧ���ĵ绰���룺";
                   cin>>phone;
                   //���ѧ����Ϣ
                   addstudent(name,sex,number,phone);
                   Sleep(1000);
                   system("cls");

                   break;

            case 2://��ѯѧ����Ϣ
                   cout<<"��������Ҫ��ѯ��ѧ����ѧ��(4λ����)��";
                   cin>>number;
                   ps=queryNum(number);
                   if(ps==NULL)
                   {
                       cout<<"\n�޷��ҵ���ѧ����"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   ps->show();
                   Sleep(3000);
                   system("cls");

                   break;

            case 3://�޸�ѧ����Ϣ
                   cout<<"��������Ҫ�޸���Ϣ��ѧ����ѧ��(4λ����)��";
                   cin>>number;
                   ps=queryNum(number);
                   if(ps==NULL)
                   {
                       cout<<"\n�޷��ҵ���ѧ����"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   system("cls");
                   //�޸�ѧ����Ϣ
                   modify(ps);

                   break;

            case 4://ɾ��ѧ��
                   cout<<"��������Ҫɾ����Ϣ��ѧ����ѧ��(4λ����)��";
                   cin>>number;
                   //ɾ��ѧ����Ϣ
                   if(deletestudent(number)==1)
                       cout<<"\nɾ���ɹ���"<<endl;
                   else cout<<"\nɾ��ʧ�ܣ�"<<endl;
                   Sleep(1000);
                   system("cls");

                   break;
            }
        }
        else
        {
            cout<<"��������ȷ��ѡ��"<<endl;
        }
    }
}
