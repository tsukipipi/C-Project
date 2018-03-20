#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

//////////////////////////////////////////////////////
//
//说明：类Function的函数成员的函数体在以下文件中:
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

const int Maxa=20;                                   //最多20位管理员
const int Maxs=500;                                  //最多500名学生
const int Maxd=200;                                  //最多200间宿舍
const int Maxv=100;                                  //最多登记100个来访者
const int Max=500;                                   //最多登记500个早出晚归信息


class Function
{
private:

    //登录管理
    Administrator administrator[Maxa];
    int adNum;


    //学生管理
    Student student[Maxs];
    int stuNum;
    Student *ps;

    //宿舍管理
    Dormitory dormitory[Maxd];
    int dorNum;
    Dormitory *pd;

    //出入管理
    Visitor visitor[Maxv];
    int visNum;
    Morning_Evening_record stud[Max];
    int studNum;
    Morning_Evening_record *pr;

public:
    //Function()在文件construction.cpp中
    Function();                                       //构造函数
    //~Function()在文件destructor.cpp中
    ~Function();                                      //析构函数


    //登录管理
    //以下函数成员在文件login.cpp中
    int queryUserName(char *na);                     //查询用户名
    int queryUser(char *na,char *pass);              //查询用户
    void Register();                                 //注册账号
    int sign_in();                                   //登录
    int login();                                     //登录管理


    //学生基本信息管理
    //以下函数在文件student_IM_function.cpp中
    void addstudent(char *na,char s,int num,char *ph);//增加学生
    bool deletestudent(int num);                      //删除学生
    void modify(Student *p);                          //修改学生信息
    Student *queryNum(int num);                       //查找学生

    //void studentdatabase()在文件student_IM.cpp中
    void studentdatabase();                           //学生基本信息管理


    //住宿管理
    //以下函数在文件dormitory_IM_function.cpp中
    void addDormitory(int num,char sex);              //增加宿舍
    void modifyDormitory(Dormitory *p);               //修改宿舍信息
    void deleteDormitory(int room);                   //删除宿舍
    Dormitory *queryroom(int num);                    //查询宿舍信息

    //void allotDormitory()在文件allot_dormitory.cpp中
    void allotDormitory();                            //分配宿舍
    //void liveDormitory()在文件live_in_dormitory.cpp中
    void liveDormitory();                             //入宿登记
    //void leaveDormitory()在文件leave_dormitory.cpp中
    void leaveDormitory();                            //退宿处理
    //void adjustDormitory()在文件adjust_dormitory.cpp中
    void adjustDormitory();                           //调宿处理
    //void dormitorydatabase()在文件dormitory_IM.cpp中
    void dormitorydatabase();                         //宿舍基本信息管理
    //void dormitoryManage()在文件dormitory_manage.cpp中
    void dormitoryManage();                           //住宿管理


    //出入管理
    //以下函数在文件get_in_out_manage.cpp中
    Morning_Evening_record *query(int num);           //查找早出晚归学生
    void morning_go_out();                            //早出登记
    void evening_go_back();                           //晚归登记
    void visit_record();                              //来访者登记
    void get_in_out_manage();                         //出入管理


    //信息查询
    //void query_information()在文件query_information.cpp中
    void query_information();                          //信息查询
};

#endif // FUNCTION_H_INCLUDED
