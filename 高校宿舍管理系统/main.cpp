////////////////////////////////////////////////////////
//
//�ļ�����main.cpp
//�����ܣ�
//    ������������ʼ�����¼��ں͸�У�������ϵͳ�ܲ˵�
//���ߣ�Pipi
//���ڣ�2016.10.15
//
////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //Sleep����ͷ�ļ�

#include "administrator.h"
#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;

int main()
{
    system("color F3");             //�޸Ľ�����ɫ

    int choice=1;
    Function function_select;       //����һ��ѧ�����ݿ���Ķ���


    //��ʼ����
    cout<<"\n\n\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<" D D        OO     R R     M       M   I I I   T T T     OO     R R     Y     Y"<<endl;
    cout<<" D   D     O  O    R   R   M M   M M     I       T      O  O    R   R    Y   Y "<<endl;
    cout<<" D    D   O    O   R R     M  M M  M     I       T     O    O   R R        Y   "<<endl;
    cout<<" D   D     O  O    R  R    M   M   M     I       T      O  O    R  R       Y   "<<endl;
    cout<<" D D        OO     R   R   M       M   I I I     T       OO     R   R      Y   "<<endl;
    cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
    cout<<"\n**************************���ڽ��롰��У�������ϵͳ��**************************\n"<<endl;
    cout<<"\n--------------------------------------------------------------------------------"<<endl;
    Sleep(2000);        //ͣ��ʱ�䵥λ�Ǻ���
    system("cls");      //ҳ�����


    //����Ա��¼��ע��ģ��
    if(function_select.login()==0)
    {
        cout<<"\n�����˳�ϵͳ..."<<endl;
        function_select.~Function();
        exit(1);
    }


    //����ѡ��ģ��
    while(choice!=0)
    {
        cout<<"   ��У�������ϵͳ��"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"|  1.ѧ��������Ϣ����  |"<<endl;
        cout<<"|  2.ס�޹���          |"<<endl;
        cout<<"|  3.�������          |"<<endl;
        cout<<"|  4.��Ϣ��ѯ          |"<<endl;
        cout<<"|  0.�˳�ϵͳ          |"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"������ѡ��";
        cin>>choice;
        system("cls");

        if(choice<=4&&choice>=0)
        {
            switch(choice)
            {
            case 1://ѧ��������Ϣ����
                   function_select.studentdatabase();

                   break;

            case 2://ס�޹���
                   function_select.dormitoryManage();

                   break;

            case 3://�������
                   function_select.get_in_out_manage();

                   break;

            case 4://��Ϣ��ѯ
                   function_select.query_information();

                   break;

            case 0://�˳�ϵͳ
                   cout<<"�����˳�ϵͳ..."<<endl;
                   function_select.~Function();
                   Sleep(1000);
                   exit(1);

                   break;
            }
        }
        else
        {
            cout<<"��������ȷ��ѡ��"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while

    return 0;
}
