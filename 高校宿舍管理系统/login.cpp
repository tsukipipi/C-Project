//////////////////////////////////////////////
//
//�ļ�����login.cpp
//�����ܣ�Function��ĳ�Ա����,��¼����ģ��
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>	     //getch����ͷ�ļ�
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "administrator.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//��ѯ����
//�������ܣ���ѯ�û���
//�����������ַ���ָ�룬ָ��Ҫ���ҵ��û���
//��������ֵ�����ͣ�1�����ҳɹ� 0������ʧ��
//
int Function::queryUserName(char *na)
{
    for(int i=0;i<=adNum;i++)
    {
        //�ҵ����û���
        if(strcmp(administrator[i].getUserName(),na)==0)
            return 1;
    }
    return 0;
}


/////////////////////////////////////////////
//��ѯ����
//�������ܣ���ѯ�û�
//����������1.�ַ���ָ��*na��ָ��Ҫ���ҵ��û���
//          2.�ַ���ָ��*pass,ָ��Ҫ���ҵ��û�����
//��������ֵ�����ͣ�1�����ҳɹ� 0������ʧ��
//
int Function::queryUser(char *na,char *pass)
{
    for(int i=0;i<=adNum;i++)
    {
        //�ҵ����û���������
        if(strcmp(administrator[i].getUserName(),na)==0&&strcmp(administrator[i].getPassword(),pass)==0)
            return 1;
        //�û�����ȷ,�������
        if(strcmp(administrator[i].getUserName(),na)==0&&strcmp(administrator[i].getPassword(),pass)!=0)
            return 2;
    }
    return 0;
}


/////////////////////////////////////////////
//ע�ắ��
//�������ܣ�����Աע���˺�
//������������
//��������ֵ����
//
void Function::Register()
{
    int temp;
    char Name[20];
    char Password[20];

    while(1)
    {
        cout<<"�û���(20���ַ�����)��";
        cin>>Name;
        temp=queryUserName(Name);
        if(temp==1)
        {
            cout<<"\n���û����Ѵ��ڣ�"<<endl;
            Sleep(1000);
            system("cls");
        }
        else break;
    }
    cout<<"��  ��(20���ַ�����)��";
    cin>>Password;

    //ע���˺�
    adNum++;
    administrator[adNum].addAdministrator(Name,Password);

    //��֤�Ƿ�ע��ɹ�
    temp=queryUser(Name,Password);
    if(temp==1)
    {
        cout<<"\nע��ɹ���"<<endl;
        Sleep(1000);
        system("cls");
    }
    else
    {
        cout<<"\nע��ʧ�ܣ�"<<endl;
        Sleep(1000);
        system("cls");
    }
}


/////////////////////////////////////////////
//��¼����
//�������ܣ�����Ա��¼
//������������
//��������ֵ�����ͣ�1.��¼�ɹ���0����¼ʧ��
//
int Function::sign_in()
{
    int index=0;        //���ڽ�������ʾΪ*��
    int temp;
    char Name[20];
    char Password[20];

    cout<<"�û���(20���ַ�����)��";
    cin>>Name;
    cout<<"��  ��(20���ַ�����)��";
    //���´���齫�����������ʾΪ*��
    while(1)
    {
        char ch;
        ch=getch();
        if(ch==8)//�˸��'\b'
        {
            if(index!=0)
            {
                cout<<char(8)<<" "<<char(8);
                index--;
            }
        }
        else if(ch==13) //�س���'\r'
        {
            Password[index]='\0';
            cout<<endl;
            break;
        }
        else
        {
            cout<<"*";
            Password[index++]=ch;
        }
    }//�����Ǻ�end


    //��¼����
    temp=queryUser(Name,Password);

    //��֤�Ƿ��¼�ɹ�
    if(temp==1)
    {
        cout<<"\n��½�ɹ���"<<endl;
        Sleep(1000);
        system("cls");
        return 1;
    }
    if(temp==2)
    {
        cout<<"\n�������"<<endl;
        Sleep(1000);
        system("cls");
    }
    if(temp==0)
    {
        cout<<"\n�û��������ڣ�"<<endl;
        Sleep(1000);
        system("cls");
    }
    return 0;
}


/////////////////////////////////////////////
//��¼������
//�������ܣ���¼����
//      1.��¼
//      2.ע��
//      0.�˳�ϵͳ
//������������
//��������ֵ�����ͣ�1.��¼�ɹ���0���˳�ϵͳ
//
int Function::login()
{
    int choice=1;

    while(1)
    {
        cout<<"��ӭʹ�á���У�������ϵͳ����"<<endl;
        cout<<"==========================="<<endl;
        cout<<"|       1.��¼            |"<<endl;
        cout<<"|       2.ע��            |"<<endl;
        cout<<"|       0.�˳�ϵͳ        |"<<endl;
        cout<<"==========================="<<endl;
        cout<<"��ѡ��";
        cin>>choice;
        system("cls");

        if(choice<=2&&choice>=0)
        {
            switch (choice)
            {
            case 1://��¼
                   if(sign_in()==1)return 1;

                   break;

            case 2://ע��
                   Register();

                   break;

            case 0://�˳�ϵͳ
                   return 0;

                   break;
            }//end switch
        }//end if
        else
        {
            cout<<"\n����û�д�ѡ�"<<endl;
            Sleep(500);
        }
        system("cls");
    }//end while
}
