#include <iostream>
#include <stdlib.h>
#include <stack>
#include "calculator.h"

using namespace std;



//����ջ������������ȼ���
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


//����ջ������������ȼ���
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


//�ж��ַ��Ƿ�Ϊ����
bool Calculator::IsDigit(char ch)
{
    if(ch>='0'&&ch<='9')return true;
    else return false;
}


//��ǰ׺���ʽת��Ϊ��׺���ʽ
void Calculator::ToPostfix()
{
    stack<char> sop;
    int i=0,j=0;
    char ch;

    //�Ȱ����ȼ�����͵�#����ջ��
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

            //���ȼ�ջ�⣾ջ��
            if(icp(inExpression[i])>isp(ch))
            {
                sop.push(inExpression[i]);
                i++;
            }
            //���ȼ�ջ�⣼ջ��
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
            //ch='('����ʱ'('��')'���ȼ���ͬ
            else
            {
                sop.pop();
                i++;
            }
        }//end else
    }//end while
    postExpression[j]='\0';
}


//��������������һ�μ���
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
                cerr<<"����Ϊ0��"<<endl;
                exit(1);
            }
            return left/right;
        default:
            cerr<<"�����������"<<endl;
            exit(1);
    }
}


//�Ժ�׺���ʽ��������
void Calculator::calculate()
{
    stack<int> snum;
    int j=0,left,right,num;

    while(postExpression[j]!=0)
    {
        switch (postExpression[j])
        {
        //�Ӽ��˳�
        case '+':case '-':case '*':case '/':
            //������Ҳ�����
            if(snum.empty()==true)
            {
                cerr<<"ȱ���Ҳ�������"<<endl;
                exit(1);
            }
            right=snum.top();
            snum.pop();

            if(snum.empty()==true)
            {
                cerr<<"ȱ�����������"<<endl;
                exit(1);
            }
            left=snum.top();
            snum.pop();

            //������������ջ��
            snum.push(DoOperator(postExpression[j],left,right));
            //�����ո�
            j+=2;

            break;

        //�����ַ���ջ��
        default:
            //��������Ϊ��λ����λ���ϵ����
            num=0;
            while(postExpression[j]!=' ')
            {
                num=num*10+postExpression[j]-'0';
                j++;
            }
            snum.push(num);
            //�����ո�
            j++;

            break;
        }
    }
    //������
    cout<<inExpression<<"="<<snum.top()<<endl;
    snum.pop();
}



//���м�����
void Calculator::Run()
{
    while(cin>>inExpression)
    {
        //ת��Ϊ��׺���ʽ
        ToPostfix();
        //���㲢������ʽ�Ľ��
        calculate();
    }
}
