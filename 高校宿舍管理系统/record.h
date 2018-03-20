#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED


//////////////////////////////////////////////////////
//
//˵������Morning_Evening_record�ĺ�����Ա�ĺ�������record.cpp��
//
//////////////////////////////////////////////////////

//ѧ��������Ǽ�
class Morning_Evening_record
{
private:
    char studentName[10];
    int studentNumber;
    int morningTimes;                       //�������
    int eveningTimes;                       //������
public:
    Morning_Evening_record();               //���캯��
    int getNum();                           //��ȡѧ��
    void morningRecord();                   //ѧ�������������
    void eveningRecord();                   //ѧ������������
    void addStud(char *na,int nu);          //����������ѧ��
    void showStudentInformation();          //չʾѧ����������Ϣ
};




//////////////////////////////////////////////////////
//
//˵������Visitor�ĺ�����Ա�ĺ�������record.cpp��
//
//////////////////////////////////////////////////////

//�����ߵǼ�
class Visitor
{
private:
    char visitorName[10];
    char visitorSex;
    char visitTime[8];
    char leaveTime[8];
    char reason[50];
    int visitDorNum;
public:
    void setVisitInformation(char *na,char se,char *v_t,char *l_t,char *re,int dorNum);//������Ϣ
    void showVisitorInformation();  //չʾ������Ϣ
};


#endif // RECORD_H_INCLUDED
