#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED

//////////////////////////////////////////////////////
//
//˵������Administrator�ĺ�����Ա�ĺ�������administrator.cpp��
//
//////////////////////////////////////////////////////

class Administrator
{
private:
    char userName[20];
    char password[20];
public:
    char *getUserName();                       //��ȡ�û���
    char *getPassword();                       //��ȡ����
    void addAdministrator(char *na,char *pass);//���ӹ���Ա
};

#endif // ADMINISTRATOR_H_INCLUDED

