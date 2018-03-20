//////////////////////////////////////////////
//
//�ļ�����get_in_out_manage.cpp
//�����ܣ�Function��ĳ�Ա����,�������
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "student.h"
#include "dormitory.h"
#include "function.h"
#include "record.h"

using namespace std;


/////////////////////////////////////////////
//���Һ���
//�������ܣ�����������ѧ��
//�������������ͣ�num��Ҫ���ҵ�ѧ��ѧ��
//��������ֵ��Morning_Evening_record��ָ��
//
Morning_Evening_record *Function::query(int num)
{
    for(int i=0;i<=studNum;i++)
    {
        if(num==stud[i].getNum())
            return &stud[i];
    }
    return NULL;
}


/////////////////////////////////////////////
//����ǼǺ���
//�������ܣ��Ǽ����ѧ����Ϣ
//������������
//��������ֵ����
//
void Function::morning_go_out()
{
    int num;
    cout<<"������Ǽ������ѧ����ѧ��(4λ��)��";
    while(1)
    {
        cin>>num;

        ps=queryNum(num);
        if(ps==NULL)
        {
            cout<<"\n�����ڴ�ѧ����"<<endl;
            Sleep(1000);
            system("cls");
        }
        else if(ps->getmark()==0)
        {
            cout<<"\n��ѧ����δ���ޣ���Ϣ����"<<endl;
            Sleep(1000);
            system("cls");
            break;
        }
        else
        {
            pr=query(num);
            //�ж�ѧ���Ƿ��Ѿ����ڣ��������������ѧ��
            cout<<"\nѧ����Ϣ���£�"<<endl;
            if(pr==NULL)
            {
                studNum++;
                stud[studNum].addStud(ps->getname(),num);
                stud[studNum].morningRecord();
                stud[studNum].showStudentInformation();
            }
            else
            {
                pr->morningRecord();
                pr->showStudentInformation();
            }


            cout<<"\n�����Ϣ�Ǽǳɹ���"<<endl;
            Sleep(4000);
            system("cls");
            break;
        }
        cout<<"����������ѧ��(4λ��)��";
    }
}


/////////////////////////////////////////////
//���ǼǺ���
//�������ܣ��Ǽ����ѧ����Ϣ
//������������
//��������ֵ����
//
void Function::evening_go_back()
{
    int num;

    cout<<"������Ǽ�����ѧ����ѧ��(4λ��)��";
    while(1)
    {
        cin>>num;

        ps=queryNum(num);
        if(ps==NULL)
        {
            cout<<"\n�����ڴ�ѧ����"<<endl;
            Sleep(1000);
            system("cls");
        }
        else if(ps->getmark()==0)
        {
            cout<<"\n��ѧ����δ���ޣ���Ϣ����"<<endl;
            Sleep(1000);
            system("cls");
            break;
        }
        else
        {
            pr=query(num);
            //�ж�ѧ���Ƿ��Ѿ����ڣ��������������ѧ��
            cout<<"\nѧ����Ϣ���£�"<<endl;
            if(pr==NULL)
            {
                studNum++;
                stud[studNum].addStud(ps->getname(),num);
                stud[studNum].eveningRecord();
                stud[studNum].showStudentInformation();
            }
            else
            {
                pr->eveningRecord();
                pr->showStudentInformation();
            }

            cout<<"\n�����Ϣ�Ǽǳɹ���"<<endl;
            Sleep(4000);
            system("cls");
            break;
        }
        cout<<"����������ѧ��(4λ��)��";
    }
}


/////////////////////////////////////////////
//�����ߵǼǺ���
//�������ܣ��Ǽ���������Ϣ
//������������
//��������ֵ����
//
void Function::visit_record()
{
    char name[10];
    char sex;
    char visitTime[8];
    char leaveTime[8];
    char reason[50];
    int visitDorNum;

    cout<<"������������������";
    cin>>name;
    cout<<"�������������Ա�(�У�m Ů��f)��";
    cin>>sex;
    cout<<"���������ʱ��(24Сʱ��,��ʽ��xx:xx)��";
    cin>>visitTime;
    cout<<"���������ʱ��(24Сʱ��,��ʽ��xx:xx)��";
    cin>>leaveTime;
    cout<<"������������ɣ�";
    cin>>reason;
    cout<<"�������������ţ�";
    while(1)
    {
        cin>>visitDorNum;
        pd=queryroom(visitDorNum);
        if(pd==NULL) cout<<"\n����Ŵ���\n\n���������룺";
        else if(pd->use_dormitory()==0) cout<<"\n����һ������ᣡ\n\n������ѡ��";
        else break;
    }

    visNum++;
    visitor[visNum].setVisitInformation(name,sex,visitTime,leaveTime,reason,visitDorNum);
    cout<<"\n��������Ϣ�Ǽǳɹ���"<<endl;
    Sleep(1000);
    system("cls");
}


/////////////////////////////////////////////
//���������
//�������ܣ��������
//      1.����Ǽ�
//      2.���Ǽ�
//      3.�����ߵǼ�
//������������
//��������ֵ����
//
void Function::get_in_out_manage()
{
    int choice=1;

    while(choice!=0)
    {
        cout<<"    �������"<<endl;
        cout<<"=================="<<endl;
        cout<<"|  1.����Ǽ�    |"<<endl;
        cout<<"|  2.���Ǽ�    |"<<endl;
        cout<<"|  3.�����ߵǼ�  |"<<endl;
        cout<<"|  0.�˳�        |"<<endl;
        cout<<"=================="<<endl;
        cout<<"������ѡ��";
        cin>>choice;
        system("cls");

        if(choice<=3&&choice>=0)
        {
            switch(choice)
            {
            case 1://����Ǽ�
                   morning_go_out();

                   break;

            case 2://���Ǽ�
                   evening_go_back();

                   break;

            case 3://�����ߵǼ�
                   visit_record();

                   break;
            }
        }
    }
}
