#include<iostream>
#include "reader.h"
#ifndef _rdatabase_h_
#define _rdatabase_h_

using namespace std;

const int Maxr=100;                 //最大读者数

class RDatabase                     //读者库类
{
private:
    int top;                        //读者记录指针
    Reader read[Maxr];              //读者记录
    int j=0;                        //用于删除某一读者时记录读者的位置
public:
    RDatabase();                    //构造函数初始化：读文件
    void clear();                   //删除所有读者信息
    int addreader(int n,char *na);  //添加读者记录时，先确定该读者是否已经存在
    Reader *query(int readerid,int &i);//按编号查找
    void list();                    //输出所有读者信息
    int delreader(int readerid);    //删除读者
    void readerdata();              //读者库维护
    ~RDatabase();                   //析构函数：写文件
};

#endif
