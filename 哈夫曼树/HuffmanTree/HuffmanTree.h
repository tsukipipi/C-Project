#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED

#include "HuffmanNode.h"

template <class T>
class HuffmanTree{
protected:
    //���ĸ��ڵ�
    HuffmanNode<T> *root;
    //�����ֹͣ��־
    int stop;
    //����������Ľ��
    HuffmanNode<T> extend;

    //�ͷ�huffman���Ľ��ռ���
    void makeEmpty(HuffmanNode<T> *&subTree);
    //�ϲ�������
    void MergeTree(HuffmanNode<T> *&tree1,HuffmanNode<T> *&tree2,HuffmanNode<T> *&p);
    //��Ҷ�ӽ����б���
    void CreatCode(HuffmanNode<T>* subTree,char *c,int i);

    //���ļ�����huffman��
    void ReadHuffmanTree(HuffmanNode<T> *&subTree,fstream &file);
    //Ѱ��ĳһҶ�ӽ������ݶ�Ӧ�Ĵ���
    void SearchCode(T x,char *code,HuffmanNode<T> *subTree);
    //Ѱ��ĳһ�δ����Ӧ��Ҷ�ӽ�������
    bool SearchData(T x[],char *code,HuffmanNode<T> *subTree,int i,int &j);
    //�ð�������ʽ�������������д���ļ���
    void TreePrint(HuffmanNode<T> *subTree,int space,fstream &file);

public:
    //���ļ�����huffman��
    void WriteHuffmanTree(HuffmanNode<T> *subTree,fstream &file);
    //���캯��
    HuffmanTree(T d);
    //��������
    ~HuffmanTree();
    //��ø��ڵ�
    HuffmanNode<T> *getRoot();
    //������������
    void CreatHuffmanTree();
    //ǰ�������������
    void PreTraverse(HuffmanNode<T> *subTree);

    //��ʼ��
    void Initialization(char *hfmTree);
    //����
    void Encoding(char *hfmTree,char *toBeTran,char *codeFile);
    //����
    void Decoding(char *hfmTree,char *codeFile,char *textFile);
    //��ӡ�����ļ�
    void Print(char *codeFile,char *codePrin);
    //��ӡ��������
    void TreePrint(char *hfmTree,char *treePrint);
};

#endif // HUFFMANTREE_H_INCLUDED
