//////////////////////////////////////////////
//
//�ļ�����student_IM_function.cpp
//�����ܣ�Function��ĳ�Ա����,ѧ��������Ϣ��ɾ���
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



//ѧ����Ϣ�����ģ��


/////////////////////////////////////////////
//���Һ���
//�������ܣ���ѧ�Ų���ѧ��
//�������������ͣ�numΪѧ��ѧ��
//��������ֵ��Student��ָ�룬���ز��ҵ���ѧ������ĵ�ַ
//
Student *Function::queryNum(int num)
{
    for(int i=0;i<=stuNum;i++)
    {
        if(num==student[i].getnumber()&&student[i].getnote()==1)//�������ͬ��δ��ɾ��(0��ɾ�� 1��δɾ��)
            return &student[i];
    }
    return NULL;
}


/////////////////////////////////////////////
//��Ӻ���
//�������ܣ�����ѧ��
//����������1.�ַ���ָ�룬*naָ��ѧ������
//          2.�ַ��ͣ�sΪѧ���Ա�
//          3.���ͣ�numΪѧ��ѧ��
//          4.�ַ���ָ�룬*phָ��ѧ���绰
//��������ֵ����
//
void Function::addstudent(char *na,char s,int num,char *ph)
{
    ps=queryNum(num);
    if(ps==NULL)
    {
        stuNum++;
        student[stuNum].addstudent(na,s,num,ph);
        cout<<"\nѧ����Ϣ��ӳɹ���"<<endl;
    }
    else cout<<"\n��ѧ���Ѵ��ڣ�ѧ����Ϣ���ʧ�ܣ�"<<endl;
}


/////////////////////////////////////////////
//ɾ������
//�������ܣ���ѧ��ɾ��ѧ��
//�������������ͣ�numΪѧ��ѧ��
//��������ֵ�������ͣ�0--ɾ��ʧ�� 1--ɾ���ɹ�
//
bool Function::deletestudent(int num)
{
    Dormitory *p;

    ps=queryNum(num);
    if(ps==NULL)
    {
        cout<<"\n��ѧ�������ڣ�"<<endl;
        return 0;
    }
    else if(ps->getmark()==1)
    {
        cout<<"\nѧ���Ѿ����ޣ�"<<endl;
        return 0;
    }
    else
    {
        if(ps->getroomNumber()!=0)
        {
            p=queryroom(ps->getroomNumber());
            if(p==NULL)
            {
                cout<<"�����޷��ҵ�ѧ����ס�����ᣡ"<<endl;
                return 0;
            }
            //�ճ���λ
            else p->not_use_bed(ps->getbedNumber());
        }
        ps->delstudent();
        return 1;
    }
}


/////////////////////////////////////////////
//�޸ĺ���
//�������ܣ�ͨ��ָ��ѧ�������ָ���޸�ѧ����Ϣ
//����������Student��ָ��
//��������ֵ����
//
void Function::modify(Student *p)
{
    char name[15];
    char phone[15];
    char sex;
    int select=1;

    while(select)
    {
        cout<<"     ��Ϣ�޸ģ�"<<endl;
        cout<<"===================="<<endl;
        cout<<"|    1.�޸�����    |"<<endl;
        cout<<"|    2.�޸ĵ绰    |"<<endl;
        cout<<"|    3.�޸��Ա�    |"<<endl;
        cout<<"|    0.�˳�        |"<<endl;
        cout<<"===================="<<endl;
        cout<<"������ѡ��";
        cin>>select;
        cout<<endl;

        if(select>=0&&select<=3)
        {
            switch(select)
            {
            case 1://�޸�����
                   cout<<"������������";
                   cin>>name;
                   p->setname(name);
                   cout<<"\n���óɹ���"<<endl;
                   Sleep(1000);

                   break;

            case 2://�޸ĵ绰
                   cout<<"������绰���룺";
                   cin>>phone;
                   p->setphone(phone);
                   cout<<"\n���óɹ���"<<endl;
                   Sleep(1000);

                   break;

            case 3://�޸��Ա�
                   if(p->getmark()==1)
                   {
                       cout<<"��ѧ���Ѿ����ޣ��޷��޸��Ա�"<<endl;
                       Sleep(1000);
                       break;
                   }
                   cout<<"�������Ա�(�У�m Ů��f)��";
                   cin>>sex;
                   if(sex=='f'||sex=='m')
                   {
                       p->setsex(sex);
                       cout<<"\n���óɹ���"<<endl;
                       Sleep(1000);
                   }
                   else
                   {
                       cout<<"\n�Ա��������"<<endl;
                       Sleep(1000);
                       break;
                   }

                   break;
            }
            system("cls");
        }//end if
        else
        {
            cout<<"��������ȷ��ѡ��"<<endl;
            Sleep(500);
            system("cls");
        }
    }
}
