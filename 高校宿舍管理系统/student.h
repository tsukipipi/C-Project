#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

//////////////////////////////////////////////////////
//
//说明：类Student的函数成员的函数体在student.cpp中
//
//////////////////////////////////////////////////////

class Student
{
private:
    char name[10];          //姓名
    char sex;               //性别
    int number;             //学号
    char phone[15];         //电话号码
    int roomNumber;         //宿舍号
    int bedNumber;          //床位号
    bool mark;              //入宿标记（0：离宿状态 1：入宿状态）
    bool note;              //删除标记（0：已删 1：未删）
public:
    Student();                                        //构造函数
    char *getname();                                  //获得姓名
    char getsex();                                    //获得性别
    int getnumber();                                  //获得学号
    char *getphone();                                 //获得电话号码
    int getroomNumber();                              //获得宿舍号
    int getbedNumber();                               //获得床位号
    bool getmark();                                   //获得入宿状态
    bool getnote();                                   //获得删除标记
    void addstudent(char *na,char s,int num,char *ph);//加入新学生，登记信息
    void setname(char *na);                           //设置姓名
    void setphone(char *ph);                          //设置电话号码
    void setsex(char s);                              //设置性别
    void setroom_bed(int room,int bed);               //设置宿舍号和床位号
    void delstudent();                                //删除学生
    void show();                                      //展示学生信息
    void live();                                      //入宿
    void leave();                                     //退宿
};

#endif // STUDENT_H_INCLUDED
