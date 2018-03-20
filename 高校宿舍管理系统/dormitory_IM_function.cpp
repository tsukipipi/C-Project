//////////////////////////////////////////////
//
//�ļ�����dormitory_IM_function.cpp
//�����ܣ�Function�����dormitory_IM�ĳ�Ա����
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


//������Ϣ����ģ��


/////////////////////////////////////////////
//��ѯ����
//�������ܣ���ѯ������Ϣ
//�������������ͣ�numΪҪ��ѯ�������
//��������ֵ��Dormitory��ָ�룬ָ����ҵ����������
//
Dormitory *Function::queryroom(int num)
{
    for(int i=0;i<=dorNum;i++)
    {
        if(num==dormitory[i].getdormitoryNumber()&&dormitory[i].getdelNote()==1)
            return &dormitory[i];
    }
    return NULL;
}


/////////////////////////////////////////////
//��Ӻ���
//�������ܣ���������
//����������1.���ͣ�numΪ��������������
//          2.�ַ��ͣ�sexΪ���������ʹ���Ա�
//��������ֵ����
//
void Function::addDormitory(int num,char sex)
{
    pd=queryroom(num);
    if(pd==NULL)
    {
        dorNum++;
        dormitory[dorNum].addDormitory(num,sex);
        cout<<"\n��ӳɹ���"<<endl;
    }
    else cout<<"\n���ʧ�ܣ��������Ѵ��ڣ�"<<endl;
}


/////////////////////////////////////////////
//�޸ĺ���
//�������ܣ��޸�������Ϣ
//      1.�޸������
//      2.�޸�����ʹ���Ա�
//����������Dormitory��ָ�룬ָ��Ҫ�޸���Ϣ���������
//��������ֵ����
//
void Function::modifyDormitory(Dormitory *p)
{
    int select=1;
    int number;
    char sex;

    //����Ϊ�ղ����޸���Ϣ
    if(p->use_dormitory()==0)
    {
        cout<<"\n����һ������ᣡ���Խ�����Ϣ�޸ģ�\n"<<endl;
        Sleep(1000);
        system("cls");
        while(select)
        {
            cout<<"      ��Ϣ�޸ģ�"<<endl;
            cout<<"======================="<<endl;
            cout<<"| 1.�޸������        |"<<endl;
            cout<<"| 2.�޸�����ʹ���Ա�  |"<<endl;
            cout<<"| 0.�˳�              |"<<endl;
            cout<<"======================="<<endl;
            cout<<"������ѡ��";
            cin>>select;
            cout<<endl;
            system("cls");

            if(select<=2||select>=0)
            {
                switch(select)
                {
                case 1://�޸������
                       cout<<"�������µ������(3λ��)��";
                       cin>>number;
                       if(number<=0||number>=1000)
                       {
                           cout<<"\n����Ŵ���"<<endl;
                           Sleep(1000);
                           system("cls");
                           break;
                       }
                       pd=queryroom(number);
                       //�ж�������Ƿ��Ѿ�����
                       if(pd==NULL)
                       {
                           p->setdormitoryNumber(number);
                           cout<<"\n���óɹ���"<<endl;
                       }
                       else cout<<"\n��������Ѵ��ڣ��޷��޸ģ�"<<endl;
                       Sleep(1000);
                       system("cls");

                       break;

                case 2://�޸�����ʹ���Ա�
                       cout<<"�������µ�����ʹ���Ա�(Ů���᣺f �����᣺m)��";
                       cin>>sex;
                       if(sex=='f'||sex=='m')
                       {
                           p->setdormitorySex(sex);
                           cout<<"\n���óɹ���"<<endl;
                           Sleep(1000);
                           system("cls");
                       }
                       else
                       {
                           cout<<"\n�Ա��������"<<endl;
                           Sleep(1000);
                           system("cls");
                           break;
                       }

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
    }//end if
    else
    {
        cout<<"\n�����������ѧ����ס���޷��޸���Ϣ��"<<endl;
        cout<<"������Ϣ���£�"<<endl;
        cout<<"\n����ţ�"<<pd->getdormitoryNumber()<<endl;
        cout<<"����ʹ���Ա�";
        if(pd->getdormitorySex()=='f')cout<<"Ů";
        else cout<<"��";
        pd->showbed();
        Sleep(4000);
        system("cls");
    }
}


/////////////////////////////////////////////
//ɾ������
//�������ܣ�ɾ������
//�������������ͣ�roomΪҪɾ���������
//��������ֵ����
//
void Function::deleteDormitory(int room)
{
    pd=queryroom(room);
    if(pd==NULL)
    {
        cout<<"\n�޷�ɾ���������᲻���ڣ�"<<endl;
        Sleep(1000);
    }
    else
    {
        if(pd->use_dormitory()==0)
        {
            pd->deletedormitory();
            cout<<"\n����һ������ᣡɾ����ϣ�"<<endl;
            Sleep(1000);
        }
        else
        {
            cout<<"\n�����������ѧ����ס���޷�ɾ����"<<endl;
            cout<<"��Ҫɾ�������ȵ�����Щѧ����ס����"<<endl;
            cout<<"������Ϣ���£�"<<endl;
            cout<<"\n����ţ�"<<pd->getdormitoryNumber()<<endl;
            cout<<"����ʹ���Ա�";
            if(pd->getdormitorySex()=='f')cout<<"Ů";
            else cout<<"��";
            pd->showbed();
            Sleep(4000);
        }
    }
}
