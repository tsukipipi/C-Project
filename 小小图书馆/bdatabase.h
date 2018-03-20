#include <iostream>
#ifndef _bdatebase_h_
#define _bdatebase_h_
#include "book.h"
using namespace std;

const int Maxb=100;         //最大图数书量

class BDatabase             //图书库类
{
private:
    int top;                //图书记录指针
    Book book[Maxb];        //图书记录
    int j=0;                //用于删除某一本书时记录书本的位置
public:
    BDatabase();            //构造函数初始化，读文件
    void clear();           //全部删除
    int addbook(int n,char *na);//添加图书
    Book *query(int bookid,int &i);//查找图书
    int delbook(int bookid);    //删除图书
    void list();                //输出图书信息
    void bookdata();            //图书库维护
    ~BDatabase();               //析构函数：写文件
};

#endif
