#include<iostream>
#include "reader.h"
#ifndef _rdatabase_h_
#define _rdatabase_h_

using namespace std;

const int Maxr=100;                 //��������

class RDatabase                     //���߿���
{
private:
    int top;                        //���߼�¼ָ��
    Reader read[Maxr];              //���߼�¼
    int j=0;                        //����ɾ��ĳһ����ʱ��¼���ߵ�λ��
public:
    RDatabase();                    //���캯����ʼ�������ļ�
    void clear();                   //ɾ�����ж�����Ϣ
    int addreader(int n,char *na);  //��Ӷ��߼�¼ʱ����ȷ���ö����Ƿ��Ѿ�����
    Reader *query(int readerid,int &i);//����Ų���
    void list();                    //������ж�����Ϣ
    int delreader(int readerid);    //ɾ������
    void readerdata();              //���߿�ά��
    ~RDatabase();                   //����������д�ļ�
};

#endif
