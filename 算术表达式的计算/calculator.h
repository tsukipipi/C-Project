#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stack>
#define Size 100

class Calculator
{
private:
    char inExpression[Size];
    char postExpression[Size];

    int isp(char op);           //返回优先级别
    int icp(char op);           //返回优先级别
    bool IsDigit(char ch);      //判断是否为数字
    void ToPostfix();           //将前缀表达式转换为后缀表达式
    void calculate();           //对后缀表达式进行运算
    int DoOperator(char op,int left,int right);//对两个操作数做一次计算

public:
    Calculator(){}          //计算一个表达式
    void Run();             //输入并计算表达式
    //void Clear();

};



#endif // CALCULATOR_H_INCLUDED
