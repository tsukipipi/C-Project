#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

//////////////////////////////////////////////////////
//
//˵������Function�ĺ�����Ա�ĺ������������ļ���:
//1.adjust_dormitory.cpp  2.allot_dormitory.cpp  3.construction.cpp  4.destructor.cpp
//5.dormitory_IM.cpp  6.dormitory_IM_function.cpp  7.dormitory_manage.cpp
//8.get_in_out_manage.cpp  9.leave_dormitory.cpp  10.live_in_dormitory.cpp
//11.login.cpp  12.query_information.cpp  13.student_IM.cpp  14.student_IM_function.cpp
//
//////////////////////////////////////////////////////

#include "administrator.h"
#include "student.h"
#include "dormitory.h"
#include "record.h"

using namespace std;

const int Maxa=20;                                   //���20λ����Ա
const int Maxs=500;                                  //���500��ѧ��
const int Maxd=200;                                  //���200������
const int Maxv=100;                                  //���Ǽ�100��������
const int Max=500;                                   //���Ǽ�500����������Ϣ


class Function
{
private:

    //��¼����
    Administrator administrator[Maxa];
    int adNum;


    //ѧ������
    Student student[Maxs];
    int stuNum;
    Student *ps;

    //�������
    Dormitory dormitory[Maxd];
    int dorNum;
    Dormitory *pd;

    //�������
    Visitor visitor[Maxv];
    int visNum;
    Morning_Evening_record stud[Max];
    int studNum;
    Morning_Evening_record *pr;

public:
    //Function()���ļ�construction.cpp��
    Function();                                       //���캯��
    //~Function()���ļ�destructor.cpp��
    ~Function();                                      //��������


    //��¼����
    //���º�����Ա���ļ�login.cpp��
    int queryUserName(char *na);                     //��ѯ�û���
    int queryUser(char *na,char *pass);              //��ѯ�û�
    void Register();                                 //ע���˺�
    int sign_in();                                   //��¼
    int login();                                     //��¼����


    //ѧ��������Ϣ����
    //���º������ļ�student_IM_function.cpp��
    void addstudent(char *na,char s,int num,char *ph);//����ѧ��
    bool deletestudent(int num);                      //ɾ��ѧ��
    void modify(Student *p);                          //�޸�ѧ����Ϣ
    Student *queryNum(int num);                       //����ѧ��

    //void studentdatabase()���ļ�student_IM.cpp��
    void studentdatabase();                           //ѧ��������Ϣ����


    //ס�޹���
    //���º������ļ�dormitory_IM_function.cpp��
    void addDormitory(int num,char sex);              //��������
    void modifyDormitory(Dormitory *p);               //�޸�������Ϣ
    void deleteDormitory(int room);                   //ɾ������
    Dormitory *queryroom(int num);                    //��ѯ������Ϣ

    //void allotDormitory()���ļ�allot_dormitory.cpp��
    void allotDormitory();                            //��������
    //void liveDormitory()���ļ�live_in_dormitory.cpp��
    void liveDormitory();                             //���޵Ǽ�
    //void leaveDormitory()���ļ�leave_dormitory.cpp��
    void leaveDormitory();                            //���޴���
    //void adjustDormitory()���ļ�adjust_dormitory.cpp��
    void adjustDormitory();                           //���޴���
    //void dormitorydatabase()���ļ�dormitory_IM.cpp��
    void dormitorydatabase();                         //���������Ϣ����
    //void dormitoryManage()���ļ�dormitory_manage.cpp��
    void dormitoryManage();                           //ס�޹���


    //�������
    //���º������ļ�get_in_out_manage.cpp��
    Morning_Evening_record *query(int num);           //����������ѧ��
    void morning_go_out();                            //����Ǽ�
    void evening_go_back();                           //���Ǽ�
    void visit_record();                              //�����ߵǼ�
    void get_in_out_manage();                         //�������


    //��Ϣ��ѯ
    //void query_information()���ļ�query_information.cpp��
    void query_information();                          //��Ϣ��ѯ
};

#endif // FUNCTION_H_INCLUDED
