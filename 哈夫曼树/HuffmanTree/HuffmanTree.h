#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED

#include "HuffmanNode.h"

template <class T>
class HuffmanTree{
protected:
    //树的根节点
    HuffmanNode<T> *root;
    //输入的停止标志
    int stop;
    //扩充二叉树的结点
    HuffmanNode<T> extend;

    //释放huffman树的结点空间结点
    void makeEmpty(HuffmanNode<T> *&subTree);
    //合并二叉树
    void MergeTree(HuffmanNode<T> *&tree1,HuffmanNode<T> *&tree2,HuffmanNode<T> *&p);
    //对叶子结点进行编码
    void CreatCode(HuffmanNode<T>* subTree,char *c,int i);

    //从文件读出huffman树
    void ReadHuffmanTree(HuffmanNode<T> *&subTree,fstream &file);
    //寻找某一叶子结点的数据对应的代码
    void SearchCode(T x,char *code,HuffmanNode<T> *subTree);
    //寻找某一段代码对应的叶子结点的数据
    bool SearchData(T x[],char *code,HuffmanNode<T> *subTree,int i,int &j);
    //用凹入表的形式输出树，并将树写入文件中
    void TreePrint(HuffmanNode<T> *subTree,int space,fstream &file);

public:
    //用文件保存huffman树
    void WriteHuffmanTree(HuffmanNode<T> *subTree,fstream &file);
    //构造函数
    HuffmanTree(T d);
    //析构函数
    ~HuffmanTree();
    //获得根节点
    HuffmanNode<T> *getRoot();
    //建立哈夫曼树
    void CreatHuffmanTree();
    //前序遍历哈夫曼树
    void PreTraverse(HuffmanNode<T> *subTree);

    //初始化
    void Initialization(char *hfmTree);
    //编码
    void Encoding(char *hfmTree,char *toBeTran,char *codeFile);
    //译码
    void Decoding(char *hfmTree,char *codeFile,char *textFile);
    //打印代码文件
    void Print(char *codeFile,char *codePrin);
    //打印哈夫曼树
    void TreePrint(char *hfmTree,char *treePrint);
};

#endif // HUFFMANTREE_H_INCLUDED
