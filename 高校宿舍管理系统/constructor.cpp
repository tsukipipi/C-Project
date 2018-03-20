//////////////////////////////////////////////
//
//�ļ�����construction.cpp
//�����ܣ�Function��Ĺ��캯��
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "student.h"
#include "dormitory.h"
#include "function.h"
#include "record.h"

using namespace std;


/////////////////////////////////////////////
//���캯��
//�������ܣ�
//1.��student.dat�ļ�����Student��Ķ�������
//2.��dormitory.dat�ļ�����Dormitory��Ķ�������
//3.��visitor.dat�ļ�����Visitor��Ķ�������
//4.��morning_evening_record.dat�ļ�����Morning_evening_record��Ķ�������
//5.��administrator.dat�ļ�����Administrator��Ķ�������
//������������
//��������ֵ����
//
Function::Function()
{

    //ѧ������
    Student s;
    stuNum=-1;
    //�Զ��뷽ʽ���ļ�
    fstream file1("student.dat",ios::in|ios::binary);
    if(!file1)
    {
        cerr<<"student.dat�޷�������!"<<endl;
        exit(1);
    }
    //����ѧ��������
    while(1)
    {
        file1.read((char*)&s,sizeof(s));
        if(!file1)break;     //���������ϣ���ֹѭ��
        stuNum++;
        student[stuNum]=s;
    }
    file1.close();





    //�������
    Dormitory d;
    dorNum=-1;
    //�Զ��뷽ʽ���ļ�
    fstream file2("dormitory.dat",ios::in|ios::binary);
    if(!file2)
    {
        cout<<"dormitory.dat�޷������򿪣�"<<endl;
        exit(1);
    }
    //�������������
    while(1)
    {
        file2.read((char*)&d,sizeof(d));
        if(!file2)break;     //���������ϣ���ֹѭ��
        dorNum++;
        dormitory[dorNum]=d;
    }
    file2.close();





    //�������


    //������
    Visitor v;
    visNum=-1;
    //�Զ��뷽ʽ���ļ�
    fstream file3("visitor.dat",ios::in|ios::binary);
    if(!file3)
    {
        cout<<"visitor.dat�޷������򿪣�"<<endl;
        exit(1);
    }
    //���������ߵ�����
    while(1)
    {
        file3.read((char*)&v,sizeof(v));
        if(!file3)break;     //���������ϣ���ֹѭ��
        visNum++;
        visitor[visNum]=v;
    }
    file3.close();



    //ѧ��������
    Morning_Evening_record st;
    studNum=-1;
    //�Զ��뷽ʽ���ļ�
    fstream file4("morning_evening_record.dat",ios::in|ios::binary);
    if(!file4)
    {
        cout<<"morning_evening_record.dat�޷������򿪣�"<<endl;
        exit(1);
    }
    //���������������
    while(1)
    {
        file4.read((char*)&st,sizeof(st));
        if(!file4)break;     //���������ϣ���ֹѭ��
        studNum++;
        stud[studNum]=st;
    }
    file4.close();





    //��¼����
    Administrator a;
    adNum=-1;
    //�Զ��뷽ʽ���ļ�
    fstream file5("administrator.dat",ios::in|ios::binary);
    if(!file5)
    {
        cout<<"administrator.dat�޷������򿪣�"<<endl;
        exit(1);
    }
    //�������Ա������
    while(1)
    {
        file5.read((char*)&a,sizeof(a));
        if(!file5)break;     //���������ϣ���ֹѭ��
        adNum++;
        administrator[adNum]=a;
    }
    file5.close();
}
