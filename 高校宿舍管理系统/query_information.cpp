//////////////////////////////////////////////
//
//�ļ�����query_information.cpp
//�����ܣ�Function��ĳ�Ա����,ʵ�ָ�����Ϣ��ѯ
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
#include "record.h"

using namespace std;


/////////////////////////////////////////////
//�����Լ������
//�������ܣ�շת����������Լ��
//��������������m��n
//��������ֵ�����ͣ��������Լ��
//
int greatest_common_divisor(int m,int n)
{
    int a,b;
    if(n>m) {a=m;m=n;n=a;}//ȷ��������С��
    while(m%n!=0)
    {b=m%n;m=n;n=b;}
    return n;
}



/////////////////////////////////////////////
//��Ϣ��ѯ����
//�������ܣ���Ϣ��ѯ
//      1.��ѯѧ����Ϣ��ס����Ϣ
//      2.��ѯ������Ϣ��ס����Ϣ
//      3.��ѯ��������Ϣ
//      4.��ѯ��������Ϣ
//      5.��ѯ��������
//      6.��ѯ����մ����
//      7.��ѯס����Ů����
//������������
//��������ֵ����
//
void Function::query_information()
{
    int choice=1;
    int studentNum;
    int roomNum;
    int countStu;//��������
    int count,boyNum,girlNum;
    int n;  //���Լ��

    while(choice!=0)
    {
        cout<<"            ��Ϣ��ѯ��"<<endl;
        cout<<"================================="<<endl;
        cout<<"|   1.��ѯѧ����Ϣ��ס����Ϣ    |"<<endl;
        cout<<"|   2.��ѯ������Ϣ��ס����Ϣ    |"<<endl;
        cout<<"|   3.��ѯ��������Ϣ          |"<<endl;
        cout<<"|   4.��ѯ��������Ϣ            |"<<endl;
        cout<<"|   5.��ѯ��������              |"<<endl;
        cout<<"|   6.��ѯ����մ����          |"<<endl;
        cout<<"|   7.��ѯס����Ů����          |"<<endl;
        cout<<"|   0.�˳�                      |"<<endl;
        cout<<"================================="<<endl;
        cout<<"������ѡ��";
        cin>>choice;
        system("cls");

        if(choice<=7&&choice>=0)
        {
            switch(choice)
            {
            case 1://��ѯѧ����Ϣ
                   cout<<"��������Ҫ��ѯ��ѧ����ѧ��(4λ����)��";
                   cin>>studentNum;
                   ps=queryNum(studentNum);
                   if(ps==NULL)
                   {
                       cout<<"\n�޷��ҵ���ѧ����"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   ps->show();
                   Sleep(5000);
                   system("cls");

                   break;

            case 2://��ѯ������Ϣ
                   cout<<"������Ҫ��ѯ�����������ţ�";
                   cin>>roomNum;
                   if(roomNum<=0)
                   {
                       cout<<"\n����Ŵ���"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   pd=queryroom(roomNum);
                   if(pd==NULL)
                   {
                       cout<<"\nδ�ҵ������ᣡ"<<endl;
                       Sleep(1000);
                       system("cls");
                       break;
                   }
                   cout<<"\n������Ϣ���£�"<<endl;
                   cout<<"\n����ţ�"<<pd->getdormitoryNumber()<<endl;
                   cout<<"\n����ʹ���Ա�";
                   if(pd->getdormitorySex()=='f')cout<<"Ů"<<endl;
                   else cout<<"��"<<endl;
                   pd->showbed();
                   Sleep(5000);
                   system("cls");

                   break;

            case 3://��ѯ��������Ϣ
                   cout<<"������ѧ��������\n"<<endl;
                   for(int i=0;i<=studNum;i++)
                       stud[i].showStudentInformation();

                   Sleep(8000);
                   system("cls");

                   break;

            case 4://��ѯ��������Ϣ
                   cout<<"��������Ϣ���£�\n"<<endl;
                   for(int i=0;i<=visNum;i++)
                       visitor[i].showVisitorInformation();

                   Sleep(10000);
                   system("cls");

                   break;

            case 5://��ѯ��������
                   count=0;
                   for(int i=0;i<=stuNum;i++)
                      if(student[i].getnote()==1)count++;
                   cout<<"ѧ��������"<<count<<endl;
                   //��ͳ�����������ļ�������ʼ��Ϊ0
                   countStu=0;
                   for(int i=0;i<=stuNum;i++)
                       if(student[i].getnote()==1&&student[i].getmark()==1)//δɾ�����Ҵ�������״̬
                           countStu++;
                   cout<<"\n����������"<<countStu<<endl;

                   Sleep(1000);
                   system("cls");

                   break;

            case 6://��ѯ����մ����
                   cout<<"�����������пմ�λ��"<<endl;
                   cout<<"�����  ʹ���Ա�"<<endl;
                   for(int i=0;i<=dorNum;i++)
                       if(dormitory[i].use_dormitory()<4)
                       {
                           cout<<' '<<dormitory[i].getdormitoryNumber()<<"       ";
                           if(dormitory[i].getdormitorySex()=='f')cout<<"Ů"<<endl;
                           else cout<<"��"<<endl;
                       }

                   Sleep(10000);
                   system("cls");

                   break;

            case 7://��ѯס����Ů����
                   count=0;boyNum=0;girlNum=0;
                   for(int i=0;i<=stuNum;i++)
                      if(student[i].getnote()==1)count++;
                   cout<<"ѧ��������"<<count<<endl;
                   for(int i=0;i<=stuNum;i++)
                   {
                       if(student[i].getsex()=='f'&&student[i].getnote()==1)girlNum++;
                       else if(student[i].getsex()=='m'&&student[i].getnote()==1)boyNum++;
                   }
                   n=greatest_common_divisor(boyNum,girlNum);
                   cout<<"\nס����Ů������"<<boyNum/n<<':'<<girlNum/n<<endl;

                   Sleep(1000);
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
