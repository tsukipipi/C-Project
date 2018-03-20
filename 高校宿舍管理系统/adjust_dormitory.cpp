//////////////////////////////////////////////
//
//�ļ�����adjust_dormitory.cpp
//�����ܣ�Function��ĳ�Ա����,����ѧ������
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
//�������ܣ�����ѧ������
//������������
//��������ֵ����
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
        cout<<"        ���޹���"<<endl;
        cout<<"=========================="<<endl;
        cout<<"|  1.��ѧ����������      |"<<endl;
        cout<<"|  2.����һ��ѧ��������  |"<<endl;
        cout<<"|  0.����                |"<<endl;
        cout<<"=========================="<<endl;
        cout<<"������ѡ��";
        cin>>select;
        system("cls");

        if(select<=2&&select>=0)
        {
            switch(select)
            {
            case 1://��ѧ����������
                   while(1)
                   {
                       cout<<"��������Ҫ�����������ѧ����ѧ�ţ�";
                       cout<<"\nѧ��1��";
                       cin>>stuNum1;
                       cout<<"ѧ��2��";
                       cin>>stuNum2;
                       if(stuNum2!=stuNum1)break;
                       cout<<"\n��ѧ��ѧ����ͬ������\n"<<endl;
                       Sleep(1000);
                       system("cls");
                   }

                   p1=queryNum(stuNum1);
                   p2=queryNum(stuNum2);
                   if(p1!=NULL&&p2!=NULL)
                   {
                       //��ȷ����ѧ���Ա���ͬ
                       if(p1->getsex()==p2->getsex())
                       {
                           //չʾĿǰ�����
                           cout<<"\n��ѧ����Ϣ���£�"<<endl;
                           p1->show();
                           p2->show();
                           Sleep(6000);
                           system("cls");

                           //���������˵�����
                           temp_roomNum=p1->getroomNumber();
                           temp_bed=p1->getbedNumber();
                           p1->setroom_bed(p2->getroomNumber(),p2->getbedNumber());
                           p2->setroom_bed(temp_roomNum,temp_bed);

                           //�޸������������Ϣ

                           //ѧ��1
                           pd=queryroom(p1->getroomNumber());
                           if(pd==NULL)
                           {
                               cout<<"\n�޷��ҵ�ѧ���������ᣡ"<<endl;
                               Sleep(1000);
                               system("cls");
                               break;
                           }
                           pd->use_bed(p1->getbedNumber(),p1->getnumber());
                           //ѧ��2
                           pd=queryroom(p2->getroomNumber());
                           if(pd==NULL)
                           {
                               cout<<"\n�޷��ҵ�ѧ���������ᣡ"<<endl;
                               Sleep(1000);
                               system("cls");
                               break;
                           }
                           pd->use_bed(p2->getbedNumber(),p2->getnumber());

                           //չʾ�µ����
                           cout<<"\n��������֮����Ϣ���£�"<<endl;
                           p1->show();
                           p2->show();
                           Sleep(6000);
                           system("cls");
                       }//end if �ж���ѧ���Ա��Ƿ���ͬ
                       else
                       {
                           cout<<"\n��ѧ�����Ա�ͬ���޷��������ᣡ"<<endl;
                           Sleep(1000);
                           system("cls");
                       }
                   }//end if �ж��Ƿ�����ҵ�ѧ��
                   else
                   {
                       cout<<"\nѧ�Ŵ����޷��ҵ�ѧ����"<<endl;
                       Sleep(1000);
                       system("cls");
                   }

                   break;

            case 2://����һѧ������
                   cout<<"��������Ҫ���������ѧ����ѧ�ţ�";
                   cin>>stuNum1;

                   ps=queryNum(stuNum1);
                   if(ps==NULL)
                   {
                       cout<<"\nδ�ҵ���ѧ����"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }


                   //����ǰ

                   //�ҵ������пմ�λ������
                   cout<<"\n�����������пմ�λ��\n"<<endl;
                   cout<<"�����  ʹ���Ա�"<<endl;
                   for(int i=0;i<=dorNum;i++)
                   {
                       if(dormitory[i].use_dormitory()<4)
                       {
                            cout<<' '<<dormitory[i].getdormitoryNumber()<<"       ";
                            if(dormitory[i].getdormitorySex()=='f')cout<<"Ů"<<endl;
                            else cout<<"��"<<endl;
                       }
                   }
                   //��ӡѧ����Ϣ
                   cout<<"\nѧ����Ϣ���£�"<<endl;
                   ps->show();

                   Sleep(5000);
                   system("cls");

                   cout<<"������Ҫ����������ţ�";
                   cin>>roomNum;

                   pd=queryroom(roomNum);
                   if(pd==NULL)
                   {
                       cout<<"\n�����᲻���ڣ�"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   //�ж�����ʹ���Ա���ѧ���Ա��Ƿ�һ��
                   if(pd->getdormitorySex()==ps->getsex())
                   {
                       cout<<"\n������Ϣ���£�"<<endl;
                       cout<<"����ţ�"<<pd->getdormitoryNumber()<<endl;
                       cout<<"ʹ���Ա�";
                       if(pd->getdormitorySex()=='f')cout<<"Ů"<<endl;
                       else cout<<"��"<<endl;
                       pd->showbed();

                       cout<<"\n�����봲λ�ţ�ѡ��һ���մ���";
                       cin>>bed;
                       if(bed>4||bed<1)
                       {
                           cout<<"\n��λ�ų���"<<endl;
                           Sleep(1000);
                           system("cls");
                           break;
                       }

                       if(pd->bed_use_case(bed)==0)
                       {
                           //��������
                           temp_bed=ps->getbedNumber();
                           temp_roomNum=ps->getroomNumber();
                           ps->setroom_bed(roomNum,bed);

                           //��ѧ����Ϣ�����µ�������
                           pd->use_bed(bed,ps->getnumber());

                           //��ԭ���������Ϣɾȥ
                           pd=queryroom(temp_roomNum);
                           pd->not_use_bed(temp_bed);
                           system("cls");

                           //������
                           cout<<"\n������֮����Ϣ���£�"<<endl;
                           ps->show();
                           Sleep(3000);
                           system("cls");
                       }//end if �жϸô�λ�Ƿ��ѱ�ʹ��
                       else
                       {
                           cout<<"\n�ô�λ�ѱ�ʹ�ã�"<<endl;
                           Sleep(1000);
                           system("cls");
                       }
                   }//end if �ж�����ʹ���Ա���ѧ���Ա��Ƿ�һ��
                   else
                   {
                       cout<<"\n����ʹ���Ա���ѧ���Ա�һ�£��޷������ᣡ"<<endl;
                       Sleep(1000);
                       system("cls");
                   }

                   break;
            }//end switch
        }//end if
        else
        {
            cout<<"��������ȷѡ��"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while
}
