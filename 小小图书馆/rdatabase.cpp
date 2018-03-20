#include<iostream>
#include<fstream>
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include"rdatabase.h"

using namespace std;

RDatabase::RDatabase()          //���캯����ʼ�������ļ�
{
    Reader s;
    top=-1;
    ifstream file;
    file.open("reader.dat",ios::in|ios::binary);
    //�ж��ļ��Ƿ�������
    if(!file)
    {
        cerr<<"reader.dat �޷���ȷ��!\n"<<endl;
        exit(1);
    }
    while(1)
    {
        file.read((char*)&s,sizeof(s));
        //�ж��ļ��Ƿ�������
        if(!file)break;
        top++;
        read[top]=s;
    }
    file.close();
}

void RDatabase::clear()         //ɾ�����ж�����Ϣ
{top=-1;}

Reader *RDatabase::query(int readerid,int &i)    //����Ų��Ҷ���
{
    for(i=0;i<=top;i++)
    {
        if(read[i].getnumber()==readerid&&read[i].getnote()==0)
            return &read[i];
    }
    return NULL;
}

int RDatabase::addreader(int n,char *na)  //��Ӷ��߼�¼ʱ����ȷ���ö����Ƿ��Ѿ�����
{
    Reader *p=query(n,j);
    if(p==NULL)
    {
        top++;
        read[top].addreader(n,na);
        cout<<"\n������ӳɹ���\n"<<endl;
        return 1;
    }
    cout<<"\n�������ʧ�ܣ�\n"<<endl;
    return 0;
}

int RDatabase::delreader(int readerid)    //ɾ������
{
    Reader *r;
    r=query(readerid,j);
    if(r==NULL)
    {
        cout<<"\nɾ��ʧ�ܣ��ö��߲����ڣ�"<<endl;
        Sleep(2000);
        system("cls");
        return 0;
    }
    r->delreader();
    read[j]=read[top];
    top--;
    cout<<"\nɾ����ϣ�"<<endl;
    Sleep(2000);
    system("cls");
    return 1;
}

void RDatabase::list()                    //������ж�����Ϣ
{
    cout<<"���߱��   ����     ������"<<endl;
    for(int i=0;i<=top;i++)
        read[i].list();
}

RDatabase::~RDatabase()                   //����������д�ļ�
{
    fstream file;
    file.open("reader.dat",ios::out|ios::binary);
    //�ж��ļ��Ƿ�������
    if(!file)
    {
        cerr<<"reader.dat �޷���ȷ��!\n"<<endl;
        exit(1);
    }
    for(int i=0;i<=top;i++)
    {
        if(read[i].getnote()==0)
            file.write((char*)&read[i],sizeof(read[i]));
    }
    file.close();
}

void RDatabase::readerdata()              //���߿�ά��
{
    int choice=1;
    char readername[20];
    int readerid;
    Reader *r;

    while(choice!=0)
    {
        cout<<"  �������ά��"<<endl;
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
                   cout<<"������߱�ţ�";
                   cin>>readerid;
                   cout<<"\n�������������";
                   cin>>readername;
                   addreader(readerid,readername);
                   Sleep(1000);
                   system("cls");
                   break;

            case 2: //����
                   cout<<"������߱�ţ�";
                   cin>>readerid;
                   r=query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"\n�ö��߲����ڣ�"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"�����µ�������";
                   cin>>readername;
                   r->setname(readername);
                   system("cls");
                   break;

            case 3: //ɾ��
                   cout<<"������߱�ţ�";
                   cin>>readerid;
                   delreader(readerid);
                   break;

            case 4: //����
                   cout<<"������߱�ţ�";
                   cin>>readerid;
                   r=query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"�ö��߲����ڣ�"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   cout<<"���߱��   ����     ������"<<endl;
                   r->list();
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
