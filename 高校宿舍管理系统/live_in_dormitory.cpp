//////////////////////////////////////////////
//
//�ļ�����live_in_dormitory.cpp
//�����ܣ�Function��ĳ�Ա����,ѧ���Ǽ�����
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
//���޵ǼǺ���
//�������ܣ����޵Ǽ�
//������������
//��������ֵ����
//
void Function::liveDormitory()
{
    int studentNumber;

    cout<<"������ѧ����ѧ�ţ�";
    cin>>studentNumber;

    ps=queryNum(studentNumber);
    if(ps==NULL)cout<<"\nδ�ҵ���ѧ����"<<endl;
    else if(ps->getmark()==1) cout<<"\n��ѧ���Ѿ����ޣ��޷��ظ��Ǽ����ޣ�"<<endl;
    else if(ps->getroomNumber()==0) cout<<"\n����Ϊѧ���������ᣡ"<<endl;
    else
    {
        //�������ޱ��
        ps->live();
        if(ps->getmark()==1)cout<<"\nѧ���ɹ��Ǽ����ޣ�"<<endl;
        else cout<<"\n����ѧ���Ǽ�����ʧ�ܣ�"<<endl;
    }
    Sleep(1000);
    system("cls");
}
