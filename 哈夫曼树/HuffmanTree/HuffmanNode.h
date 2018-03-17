#ifndef HUFFMANNODE_H_INCLUDED
#define HUFFMANNODE_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

template <class T>
struct HuffmanNode{
    //结点的数据
    T data;
    //结点的权重
    int weight;
    //指针域
    HuffmanNode *leftchild,*rightchild,*parent;
    //此结点的编码
    char code[10];

    //构造函数
    HuffmanNode(T d='#')
    {
        data=d;
        weight=-1;
        leftchild=0;
        rightchild=0;
        parent=0;
        strcpy(code,"*");
    }

    //构造函数
    HuffmanNode(int w)
    {
        data='#';
        weight=w;
        leftchild=0;
        rightchild=0;
        parent=0;
        strcpy(code,"#");
    }


    /*
    //运算符重载
    friend istream &operator>>(istream &input,HuffmanNode<T> &h);
    friend ostream &operator<<(ostream &output,HuffmanNode<T> &h);
    bool operator>(HuffmanNode<T> h);
    bool operator<(HuffmanNode<T> h);
    bool operator==(HuffmanNode<T> h);
    bool operator!=(HuffmanNode<T> h);
    */
};

#endif // HUFFMANNODE_H_INCLUDED
