//////////////////////////////////////////////
//
//�ļ�����dormitory_IM.cpp
//�����ܣ�Function��ĳ�Ա����,���������Ϣ����
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
//��Ϣ������
//�������ܣ����������Ϣ����˵�ѡ��
//          1.�������
//          2.��ѯ������Ϣ
//          3.�޸�������Ϣ
//          4.ɾ������
//          0.�˳�
//������������
//��������ֵ����
//
void Function::dormitorydatabase()
{
    int choice=1;
    int roomNumber;
    char sex;

    while(choice!=0)
    {
        cout<<"    ���������Ϣ����"<<endl;
        cout<<"========================"<<endl;
        cout<<"|    1.�������        |"<<endl;
        cout<<"|    2.��ѯ������Ϣ    |"<<endl;
        cout<<"|    3.�޸�������Ϣ    |"<<endl;
        cout<<"|    4.ɾ������        |"<<endl;
        cout<<"|    0.�˳�            |"<<endl;
        cout<<"========================"<<endl;
        cout<<"������ѡ��";
        cin>>choice;
        system("cls");

        if(choice<=4&&choice>=0)
        {
            switch(choice)
            {
            case 1://�������
                   cout<<"������Ҫ��ӵ������(3λ��)��";
                   cin>>roomNumber;
                   if(roomNumber<=0||roomNumber>=1000)
                   {
                       cout<<"\n����Ŵ���"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   cout<<"�����������ʹ���Ա�(������m Ů����f)��";
                   cin>>sex;
                   //�ж��Ա������Ƿ���ȷ
                   if(sex=='f'||sex=='m')
                   {
                       addDormitory(roomNumber,sex);
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

            case 2://��ѯ������Ϣ
                   cout<<"������Ҫ��ѯ������������(3λ��)��";
                   cin>>roomNumber;
                   if(roomNumber<=0||roomNumber>=1000)
                   {
                       cout<<"\n����Ŵ���"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   pd=queryroom(roomNumber);
                   if(pd==NULL)
                   {
                       cout<<"\nδ�ҵ������ᣡ"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //չʾ������Ϣ
                   cout<<"\n����ţ�"<<pd->getdormitoryNumber()<<endl;
                   cout<<"����ʹ���Ա�";
                   if(pd->getdormitorySex()=='f')cout<<"Ů";
                   else cout<<"��";
                   pd->showbed();
                   Sleep(4000);
                   system("cls");

                   break;

            case 3://�޸�������Ϣ
                   cout<<"������Ҫ�޸ĵ�����������(3λ��)��";
                   cin>>roomNumber;
                   if(roomNumber<=0||roomNumber>=1000)
                   {
                       cout<<"\n����Ŵ���"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   pd=queryroom(roomNumber);
                   if(pd==NULL)
                   {
                       cout<<"\n�޷��޸ģ������᲻���ڣ�"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   modifyDormitory(pd);

                   break;

            case 4://ɾ������
                   cout<<"������Ҫɾ��������ţ�";
                   cin>>roomNumber;
                   if(roomNumber<0)
                   {
                       cout<<"\n����Ŵ���"<<endl;
                       break;
                   }
                   deleteDormitory(roomNumber);
                   system("cls");

                   break;
            }
        }
        else
        {
            cout<<"��������ȷ��ѡ��"<<endl;
            Sleep(500);
            system("cls");
        }
    }
}
