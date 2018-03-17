#ifndef HUFFMANNODE_H_INCLUDED
#define HUFFMANNODE_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

template <class T>
struct HuffmanNode{
    //��������
    T data;
    //����Ȩ��
    int weight;
    //ָ����
    HuffmanNode *leftchild,*rightchild,*parent;
    //�˽��ı���
    char code[10];

    //���캯��
    HuffmanNode(T d='#')
    {
        data=d;
        weight=-1;
        leftchild=0;
        rightchild=0;
        parent=0;
        strcpy(code,"*");
    }

    //���캯��
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
    //���������
    friend istream &operator>>(istream &input,HuffmanNode<T> &h);
    friend ostream &operator<<(ostream &output,HuffmanNode<T> &h);
    bool operator>(HuffmanNode<T> h);
    bool operator<(HuffmanNode<T> h);
    bool operator==(HuffmanNode<T> h);
    bool operator!=(HuffmanNode<T> h);
    */
};

#endif // HUFFMANNODE_H_INCLUDED
