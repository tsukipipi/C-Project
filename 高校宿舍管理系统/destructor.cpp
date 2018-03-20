//////////////////////////////////////////////
//
//�ļ�����destructor.cpp
//�����ܣ�Function�����������
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
//��������
//�������ܣ�
//1.��Student��Ķ�������д��student.dat�ļ�
//2.��Dormitory��Ķ�������д��dormitory.dat�ļ�
//3.��Visitor��Ķ�������д��visitor.dat�ļ�
//4.��Morning_evening_record��Ķ�������д��morning_evening_record.dat�ļ�
//5.��Administrator��Ķ�������д��administrator.dat�ļ�
//������������
//��������ֵ����
//
Function::~Function()
{
    //ѧ������
    fstream file1("student.dat",ios::out|ios::binary);
    if(!file1)
    {
        cout<<"student.dat�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    for(int i=0;i<=stuNum;i++)
        if(student[i].getnote()==1)
            file1.write((char*)&student[i],sizeof(student[i]));
    file1.close();





    //�������
    fstream file2("dormitory.dat",ios::out|ios::binary);
    if(!file2)
    {
        cout<<"dormitory.dat�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    for(int i=0;i<=dorNum;i++)
        if(dormitory[i].getdelNote()==1)
            file2.write((char*)&dormitory[i],sizeof(dormitory[i]));
    file2.close();





    //�������

    //������
    fstream file3("visitor.dat",ios::out|ios::binary);
    if(!file3)
    {
        cout<<"visitor.dat�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    for(int i=0;i<=visNum;i++)
        file3.write((char*)&visitor[i],sizeof(visitor[i]));
    file3.close();



    //ѧ��������
    fstream file4("morning_evening_record.dat",ios::out|ios::binary);
    if(!file4)
    {
        cout<<"morning_evening_record.dat�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    for(int i=0;i<=studNum;i++)
        file4.write((char*)&stud[i],sizeof(stud[i]));
    file4.close();





    //��¼����
    fstream file5("administrator.dat",ios::out|ios::binary);
    if(!file5)
    {
        cout<<"administrator.dat�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    for(int i=0;i<=adNum;i++)
        file5.write((char*)&administrator[i],sizeof(administrator[i]));
    file5.close();
}


