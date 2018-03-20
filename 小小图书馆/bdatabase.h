#include <iostream>
#ifndef _bdatebase_h_
#define _bdatebase_h_
#include "book.h"
using namespace std;

const int Maxb=100;         //���ͼ������

class BDatabase             //ͼ�����
{
private:
    int top;                //ͼ���¼ָ��
    Book book[Maxb];        //ͼ���¼
    int j=0;                //����ɾ��ĳһ����ʱ��¼�鱾��λ��
public:
    BDatabase();            //���캯����ʼ�������ļ�
    void clear();           //ȫ��ɾ��
    int addbook(int n,char *na);//���ͼ��
    Book *query(int bookid,int &i);//����ͼ��
    int delbook(int bookid);    //ɾ��ͼ��
    void list();                //���ͼ����Ϣ
    void bookdata();            //ͼ���ά��
    ~BDatabase();               //����������д�ļ�
};

#endif
