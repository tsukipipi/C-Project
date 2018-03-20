//////////////////////////////////////////////
//
//�ļ�����record.cpp
//�����ܣ�Morning_Evening_record��ĳ�Ա����
//          Visitor��ĳ�Ա����
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <string.h>

#include "record.h"

using namespace std;


//ѧ��������Ǽ�


/////////////////////////////////////////////
//���캯��
//�������ܣ���ʼ�����������Ϊ0
//������������
//��������ֵ����
//
Morning_Evening_record::Morning_Evening_record()
{
    morningTimes=0;
    eveningTimes=0;
}


/////////////////////////////////////////////
//get����
//�������ܣ���ȡѧ��
//������������
//��������ֵ�����ͣ�����ѧ��ѧ��
//
int Morning_Evening_record::getNum()
{return studentNumber;}


/////////////////////////////////////////////
//����ǼǺ���
//�������ܣ�ѧ�������������
//������������
//��������ֵ����
//
void Morning_Evening_record::morningRecord()
{morningTimes++;}


/////////////////////////////////////////////
//���ǼǺ���
//�������ܣ�ѧ������������
//������������
//��������ֵ����
//
void Morning_Evening_record::eveningRecord()
{eveningTimes++;}


/////////////////////////////////////////////
//��Ӻ���
//�������ܣ�����������ѧ��
//�����������ַ���ָ�룺ָ�����������ͣ�ѧ��
//��������ֵ����
//
void Morning_Evening_record::addStud(char *na,int nu)
{
    strcpy(studentName,na);
    studentNumber=nu;
}


/////////////////////////////////////////////
//show����
//�������ܣ�չʾѧ����������Ϣ
//������������
//��������ֵ����
//
void Morning_Evening_record::showStudentInformation()
{
    cout<<"\n������"<<studentName<<endl;
    cout<<"ѧ�ţ�"<<studentNumber<<endl;
    cout<<"���������"<<morningTimes<<endl;
    cout<<"��������"<<eveningTimes<<endl;
}




//�����ߵǼ�

/////////////////////////////////////////////
//set����
//�������ܣ�������������Ϣ
//�����������ַ���ָ�룬�ַ��ͣ�ָ�������ߵĸ�����Ϣ
//��������ֵ����
//
void Visitor::setVisitInformation(char *na,char se,char *v_t,char *l_t,char *re,int dorNum)
{
    strcpy(visitorName,na);
    visitorSex=se;
    strcpy(visitTime,v_t);
    strcpy(leaveTime,l_t);
    strcpy(reason,re);
    visitDorNum=dorNum;
}


/////////////////////////////////////////////
//show����
//�������ܣ�չʾ������Ϣ
//������������
//��������ֵ����
//
void Visitor::showVisitorInformation()
{
    cout<<"\n������������"<<visitorName<<endl;
    cout<<"�������Ա�"<<visitorSex<<endl;
    cout<<"����ʱ�䣺"<<visitTime<<endl;
    cout<<"�뿪ʱ�䣺"<<leaveTime<<endl;
    cout<<"����ԭ��"<<reason<<endl;
    cout<<"��������ţ�"<<visitDorNum<<endl;
}
