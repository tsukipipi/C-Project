#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED

//////////////////////////////////////////////////////
//
//说明：类Administrator的函数成员的函数体在administrator.cpp中
//
//////////////////////////////////////////////////////

class Administrator
{
private:
    char userName[20];
    char password[20];
public:
    char *getUserName();                       //获取用户名
    char *getPassword();                       //获取密码
    void addAdministrator(char *na,char *pass);//增加管理员
};

#endif // ADMINISTRATOR_H_INCLUDED

