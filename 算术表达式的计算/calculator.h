#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stack>
#define Size 100

class Calculator
{
private:
    char inExpression[Size];
    char postExpression[Size];

    int isp(char op);           //�������ȼ���
    int icp(char op);           //�������ȼ���
    bool IsDigit(char ch);      //�ж��Ƿ�Ϊ����
    void ToPostfix();           //��ǰ׺���ʽת��Ϊ��׺���ʽ
    void calculate();           //�Ժ�׺���ʽ��������
    int DoOperator(char op,int left,int right);//��������������һ�μ���

public:
    Calculator(){}          //����һ�����ʽ
    void Run();             //���벢������ʽ
    //void Clear();

};



#endif // CALCULATOR_H_INCLUDED
