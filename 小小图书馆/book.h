#include <iostream>
#ifndef _book_h_
#define _book_h_
using namespace std;

class Book                      //ͼ����
{
private:
    int note;                   //ɾ����ʶ��1����ɾ��0��δɾ��
    int number;                 //ͼ����
    char name[20];              //����
    int onshelf;                //�ϼܱ�־
public:
    Book(){}
    char *getname();            //�������
    int getnote();              //���ɾ����ʶ
    int getnumber();            //���ͼ����
    void setname(char na[]);    //��������
    void delbook();             //ɾ��ͼ��
    void addbook(int n,char *na);//���ͼ��
    int borrowbook();           //�������
    void retbook();             //�������
    void list();                //���ͼ��
};

#endif
