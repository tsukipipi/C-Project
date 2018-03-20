#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

//////////////////////////////////////////////////////
//
//˵������Student�ĺ�����Ա�ĺ�������student.cpp��
//
//////////////////////////////////////////////////////

class Student
{
private:
    char name[10];          //����
    char sex;               //�Ա�
    int number;             //ѧ��
    char phone[15];         //�绰����
    int roomNumber;         //�����
    int bedNumber;          //��λ��
    bool mark;              //���ޱ�ǣ�0������״̬ 1������״̬��
    bool note;              //ɾ����ǣ�0����ɾ 1��δɾ��
public:
    Student();                                        //���캯��
    char *getname();                                  //�������
    char getsex();                                    //����Ա�
    int getnumber();                                  //���ѧ��
    char *getphone();                                 //��õ绰����
    int getroomNumber();                              //��������
    int getbedNumber();                               //��ô�λ��
    bool getmark();                                   //�������״̬
    bool getnote();                                   //���ɾ�����
    void addstudent(char *na,char s,int num,char *ph);//������ѧ�����Ǽ���Ϣ
    void setname(char *na);                           //��������
    void setphone(char *ph);                          //���õ绰����
    void setsex(char s);                              //�����Ա�
    void setroom_bed(int room,int bed);               //��������źʹ�λ��
    void delstudent();                                //ɾ��ѧ��
    void show();                                      //չʾѧ����Ϣ
    void live();                                      //����
    void leave();                                     //����
};

#endif // STUDENT_H_INCLUDED
