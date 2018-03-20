#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED


//////////////////////////////////////////////////////
//
//说明：类Morning_Evening_record的函数成员的函数体在record.cpp中
//
//////////////////////////////////////////////////////

//学生早出晚归登记
class Morning_Evening_record
{
private:
    char studentName[10];
    int studentNumber;
    int morningTimes;                       //早出次数
    int eveningTimes;                       //晚归此数
public:
    Morning_Evening_record();               //构造函数
    int getNum();                           //获取学号
    void morningRecord();                   //学生早出次数增加
    void eveningRecord();                   //学生晚归次数增加
    void addStud(char *na,int nu);          //添加早出晚归的学生
    void showStudentInformation();          //展示学生早出晚归信息
};




//////////////////////////////////////////////////////
//
//说明：类Visitor的函数成员的函数体在record.cpp中
//
//////////////////////////////////////////////////////

//来访者登记
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
    void setVisitInformation(char *na,char se,char *v_t,char *l_t,char *re,int dorNum);//设置信息
    void showVisitorInformation();  //展示来访信息
};


#endif // RECORD_H_INCLUDED
