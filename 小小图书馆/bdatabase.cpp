#include<fstream>
#include<iostream>
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include"bdatabase.h"

using namespace std;

BDatabase::BDatabase()            //���캯����ʼ�������ļ�
{
    Book s;		//�м�ͼ�����
    top=-1;
    fstream file;
    file.open("book.dat",ios::in|ios::binary);
    //�ж��ļ��Ƿ�������
    if(!file)
    {
        cerr<<"book.dat �޷���ȷ��!\n"<<endl;
        exit(1);
    }
    while(1)
    {
        //����Ϣ��f������io��
        file.read((char*)&s,sizeof(s));
        //�ж��ļ��Ƿ�������
        if(!file)break;
        top++;
        book[top]=s;
    }
    file.close();
}

void BDatabase::clear()           //ɾ������ͼ����Ϣ
{top=-1;}

Book *BDatabase::query(int bookid,int &i)    //����ͼ��
{
    for(i=0;i<=top;i++)
    {
        if(book[i].getnumber()==bookid&&book[i].getnote()==0)
            return &book[i];
    }
    return NULL;
}

int BDatabase::addbook(int n,char *na)//���ͼ��
{
    Book *p=query(n,j);
    if(p==NULL)
    {
        top++;
        book[top].addbook(n,na);
        cout<<"\nͼ����ӳɹ���\n"<<endl;
        return 1;
    }
    cout<<"\nͼ�����ʧ�ܣ�\n"<<endl;
    return 0;
}

int BDatabase::delbook(int bookid)    //ɾ��ͼ��
{
    Book *b;
    b=query(bookid,j);
    if(b==NULL)
    {
        cout<<"\nɾ��ʧ�ܣ���ͼ�鲻���ڣ�"<<endl;
        Sleep(2000);
        system("cls");
        return 0;
    }
    b->delbook();
    book[j]=book[top];
    top--;
    cout<<"\nɾ����ϣ�"<<endl;
    Sleep(2000);
    system("cls");
    return 1;
}

void BDatabase::list()                //���ͼ����Ϣ
{
    cout<<"ͼ����   ����     �ݴ���Ŀ"<<endl;
    for(int i=0;i<=top;i++)
        book[i].list();
}

BDatabase::~BDatabase()               //����������д�ļ�
{
    fstream file;
    file.open("book.dat",ios::out|ios::binary);
    //�ж��ļ��Ƿ�������
    if(!file)
    {
        cerr<<"book.dat �޷���ȷ��!\n"<<endl;
        exit(1);
    }
    for(int i=0;i<=top;i++)
    {
        if(book[i].getnote()==0)
            file.write((char*)&book[i],sizeof(book[i]));
    }
    file.close();
}

void BDatabase::bookdata()            //ͼ���ά��
{
    int choice=1;
    char bookname[20];
    int bookid;
    Book *b;

    while(choice!=0)
    {
        cout<<"  ����ͼ��ά��"<<endl;
        cout<<"----------------"<<endl;
        cout<<"|  1.����      |"<<endl;
        cout<<"|  2.����      |"<<endl;
        cout<<"|  3.ɾ��      |"<<endl;
        cout<<"|  4.����      |"<<endl;
        cout<<"|  5.��ʾ      |"<<endl;
        cout<<"|  6.ȫɾ      |"<<endl;
        cout<<"|  0.�˳�      |"<<endl;
        cout<<"----------------"<<endl;
        cout<<"��ѡ��";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1: //����
                   cout<<"����ͼ���ţ�";
                   cin>>bookid;
                   cout<<"\n����ͼ������";
                   cin>>bookname;
                   addbook(bookid,bookname);
                   Sleep(1000);
                   system("cls");
                   break;

            case 2: //����
                   cout<<"����ͼ���ţ�";
                   cin>>bookid;
                   b=query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n��ͼ�鲻���ڣ�"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"\n�����µ�ͼ������";
                   cin>>bookname;
                   b->setname(bookname);
                   system("cls");
                   break;

            case 3: //ɾ��
                   cout<<"����ͼ���ţ�";
                   cin>>bookid;
                   delbook(bookid);
                   break;

            case 4: //����
                   cout<<"����ͼ���ţ�";
                   cin>>bookid;
                   b=query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n��ͼ�鲻���ڣ�"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"ͼ����   ����     �ݴ���Ŀ"<<endl;
                   b->list();
                   Sleep(2000);
                   system("cls");
                   break;

            case 5: //��ʾ
                   list();
                   Sleep(5000);
                   system("cls");
                   break;

            case 6: //ȫɾ
                   clear();
                   system("cls");
                   break;
        }//end switch
    }//end while
}
