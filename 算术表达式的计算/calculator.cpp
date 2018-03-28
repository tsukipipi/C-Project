#include <iostream>
#include <stdlib.h>
#include <stack>
#include "calculator.h"

using namespace std;



//返回栈中运算符的优先级别
int Calculator::isp(char op)
{
    switch (op)
    {
        case '#':return 0;break;
        case '(':return 1;break;
        case '*':case '/':case '%':return 5;break;
        case '+':case '-':return 3;break;
        case ')':return 6;
    }
    return -1;
}


//返回栈外运算符的优先级别
int Calculator::icp(char op)
{
    switch (op)
    {
        case '#':return 0;break;
        case '(':return 6;break;
        case '*':case '/':case '%':return 4;break;
        case '+':case '-':return 2;break;
        case ')':return 1;
    }
    return -1;
}


//判断字符是否为数字
bool Calculator::IsDigit(char ch)
{
    if(ch>='0'&&ch<='9')return true;
    else return false;
}


//将前缀表达式转换为后缀表达式
void Calculator::ToPostfix()
{
    stack<char> sop;
    int i=0,j=0;
    char ch;

    //先把优先级别最低的#放入栈中
    sop.push('#');

    while(sop.empty()==false)
    {
        if(IsDigit(inExpression[i]))
        {
            while(IsDigit(inExpression[i]))
            {
                postExpression[j]=inExpression[i];
                j++;i++;
            }
            postExpression[j]=' ';
            j++;
        }
        else
        {
            ch=sop.top();

            //优先级栈外＞栈内
            if(icp(inExpression[i])>isp(ch))
            {
                sop.push(inExpression[i]);
                i++;
            }
            //优先级栈外＜栈内
            else if(icp(inExpression[i])<isp(ch))
            {
                if(sop.top()!='#')
                {
                    postExpression[j]=ch;
                    postExpression[++j]=' ';
                    j++;
                }
                sop.pop();
            }
            //ch='('，此时'('与')'优先级相同
            else
            {
                sop.pop();
                i++;
            }
        }//end else
    }//end while
    postExpression[j]='\0';
}


//对两个操作数做一次计算
int Calculator::DoOperator(char op,int left,int right)
{
    switch (op)
    {
        case '+':return left+right;
        case '-':return left-right;
        case '*':return left*right;
        case '/':
            if(right==0)
            {
                cerr<<"除数为0！"<<endl;
                exit(1);
            }
            return left/right;
        default:
            cerr<<"不是运算符！"<<endl;
            exit(1);
    }
}


//对后缀表达式进行运算
void Calculator::calculate()
{
    stack<int> snum;
    int j=0,left,right,num;

    while(postExpression[j]!=0)
    {
        switch (postExpression[j])
        {
        //加减乘除
        case '+':case '-':case '*':case '/':
            //获得左右操作数
            if(snum.empty()==true)
            {
                cerr<<"缺少右操作数！"<<endl;
                exit(1);
            }
            right=snum.top();
            snum.pop();

            if(snum.empty()==true)
            {
                cerr<<"缺少左操作数！"<<endl;
                exit(1);
            }
            left=snum.top();
            snum.pop();

            //将运算结果放入栈中
            snum.push(DoOperator(postExpression[j],left,right));
            //跳过空格
            j+=2;

            break;

        //将数字放入栈中
        default:
            //考虑数字为两位及两位以上的情况
            num=0;
            while(postExpression[j]!=' ')
            {
                num=num*10+postExpression[j]-'0';
                j++;
            }
            snum.push(num);
            //跳过空格
            j++;

            break;
        }
    }
    //输出结果
    cout<<inExpression<<"="<<snum.top()<<endl;
    snum.pop();
}



//运行计算器
void Calculator::Run()
{
    while(cin>>inExpression)
    {
        //转化为后缀表达式
        ToPostfix();
        //计算并输出表达式的结果
        calculate();
    }
}
