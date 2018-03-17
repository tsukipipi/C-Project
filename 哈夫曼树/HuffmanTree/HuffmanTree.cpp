#include <iostream>
#include <fstream>
#include <stack>
#include <stdlib.h>
#include <string.h>

#include "MinHeap.h"
#include "HuffmanTree.h"
#include "HuffmanNode.h"

#include "MinHeap.cpp"

using namespace std;


//私有成员函数


//////////////////////////////////////////////////////////////////////////////
//  置空函数
//  函数功能：递归函数，释放huffman树的结点空间结点
//  函数参数：huffman结点
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::makeEmpty(HuffmanNode<T> *&subTree)
{
    if(subTree!=0)
    {
        //将左子树置空
        makeEmpty(subTree->leftchild);
        //将右子树置空
        makeEmpty(subTree->leftchild);
        //释放当前结点空间
        delete subTree;
    }
}


//////////////////////////////////////////////////////////////////////////////
//  合并函数
//  函数功能：合并两棵二叉树，并保存在新开辟的结点上
//  函数参数：huffman结点，分别是两棵要合并的子树，和新的双亲结点
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::MergeTree(HuffmanNode<T> *&tree1,HuffmanNode<T> *&tree2,HuffmanNode<T> *&p)
{
    //新建结点作为两棵子树的双亲
    p=new HuffmanNode<T>;
    if(p==0)
    {
        cerr<<"存储分配出错！"<<endl;
        exit(1);
    }
    //双亲的权重为两棵子树的权重之和
    p->weight=tree1->weight+tree2->weight;
    p->leftchild=tree1;
    p->rightchild=tree2;
    tree1->parent=p;
    tree2->parent=p;
}


//////////////////////////////////////////////////////////////////////////////
//  编码函数
//  函数功能：对叶子结点进行编码
//  函数参数：huffman结点，字符数组，保存编码，整型，保存编码的长度
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::CreatCode(HuffmanNode<T>* subTree,char *c,int i)
{
    //结点不为空
    if(subTree!=0)
    {
        //结点有双亲结点
        if(subTree->parent!=0)
        {
            //左孩子标记为0
            if(subTree->parent->leftchild==subTree)
                c[i]='0';
            //右孩子标记为1
            else c[i]='1';
            //i指向下一个字符
            i++;
            //叶子结点则保存编码
            if(subTree->leftchild==0&&subTree->rightchild==0)
            {
                //结尾加入结束符'\0'
                c[i]='\0';
                strcpy(subTree->code,c);
                return ;
            }
        }
        //遍历左子树
        CreatCode(subTree->leftchild,c,i);
        //遍历右子树
        CreatCode(subTree->rightchild,c,i);
    }
}


//////////////////////////////////////////////////////////////////////////////
//  写文件函数
//  函数功能：递归函数，用文件保存huffman树
//  函数参数：huffman结点，要写入数据的文件
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::WriteHuffmanTree(HuffmanNode<T> *subTree,fstream &file)
{
    if(subTree!=0)
    {
        //写入当前结点
        file.write((char*)&(*subTree),sizeof(*subTree));
        //file<<subTree->data<<' '<<subTree->weight<<' '<<subTree->code<<' ';
        //写入左边子树
        WriteHuffmanTree(subTree->leftchild,file);
        //写入右边子树
        WriteHuffmanTree(subTree->rightchild,file);
    }
    else
    {
        //写入扩充的标志
        file.write((char*)&(extend),sizeof(extend));
        //file<<extend.data<<' '<<extend.weight<<' '<<extend.code<<' ';
    }
}


//////////////////////////////////////////////////////////////////////////////
//  读文件函数
//  函数功能：递归函数，从文件读出huffman树的结点并建树
//  函数参数：huffman结点，要读出数据的文件
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::ReadHuffmanTree(HuffmanNode<T> *&subTree,fstream &file)
{
    HuffmanNode<T> *p;
    p=new HuffmanNode<T>;
    file.read((char*)&(*p),sizeof(*p));
    //file>>p->data>>p->weight>>p->code;
    //判断是否为文件结尾
    if(!file)
    {
        delete p;
        return ;
    }

    //不包含扩充字符
    if(p->data!=extend.data)
    {
        //cout<<p->data<<' '<<p->weight<<' '<<p->code<<endl;
        subTree=p;
        ReadHuffmanTree(subTree->leftchild,file);
        ReadHuffmanTree(subTree->rightchild,file);
    }
    else delete p;

}


//////////////////////////////////////////////////////////////////////////////
//  查找函数
//  函数功能：寻找某个数据对应的某一叶子结点的数据，并获得其对应的编码
//  函数参数：要查找的数据，字符数组保存编码，huffman结点
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::SearchCode(T x,char *code,HuffmanNode<T> *subTree)
{
    //子树非空
    if(subTree!=0)
    {
        //判断是否为寻找的叶子结点
        if(subTree->leftchild==0&&subTree->rightchild==0)
        {
            //找到数据对应的结点
            if(subTree->data==x) strcpy(code,subTree->code);
            return ;
        }

        //分别查找左右子树
        SearchCode(x,code,subTree->leftchild);
        SearchCode(x,code,subTree->rightchild);
    }
}


//////////////////////////////////////////////////////////////////////////////
//  查找函数
//  函数功能：寻找某一段代码对应的叶子结点的数据，将一段代码译码
//  函数参数：保存译码后的数据的数组，字符数组保存编码，huffman结点，当前译码的代码数目，译码成功的数据的数目
//  函数返回值：布尔型，表示译码成功或失败
//
template <class T>
bool HuffmanTree<T>::SearchData(T x[],char *code,HuffmanNode<T> *subTree,int i,int &j)
{
    //子树非空
    if(subTree!=0)
    {
        //叶子结点
        if(subTree->leftchild==0&&subTree->rightchild==0)
        {
            cout<<subTree->data<<':'<<subTree->code<<endl;
            x[j]=subTree->data;
            //读到代码结尾
            if(code[i]=='\0')return true;
            //计算数据的数目
            j++;
            //返回根节点
            subTree=root;
        }
        //进入左子树
        if(code[i]=='0') return SearchData(x,code,subTree->leftchild,i+1,j);
        //进入右子树
        else return SearchData(x,code,subTree->rightchild,i+1,j);
    }
    //存在代码，进入空子树，出错
    return false;
}


//////////////////////////////////////////////////////////////////////////////
//  打印函数
//  函数功能：递归函数，用凹入表的形式输出树，并将树写入文件中
//  函数参数：huffman结点，空格数目，用来保存结点文件
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::TreePrint(HuffmanNode<T> *subTree,int space,fstream &file)
{
    //当前结点不空
    if(subTree!=0)
    {
        //输出空格，并将空格写入文件中
        for(int i=0;i<space;i++)
        {
            cout<<' ';
            file<<' ';
        }
        //叶子结点，输出权重和数据并写入文件中
        if(subTree->rightchild==0&&subTree->rightchild==0)
        {
            cout<<subTree->weight<<"["<<subTree->data<<"]"<<endl;
            file<<subTree->weight<<"["<<subTree->data<<"]"<<'\r'<<'\n';
        }
        //非叶子结点，输出权重并写入文件中
        else
        {
            cout<<subTree->weight<<endl;
            file<<subTree->weight<<'\r'<<'\n';
            //打印左子树
            TreePrint(subTree->leftchild,space+2,file);
            //打印右子树
            TreePrint(subTree->rightchild,space+2,file);
        }
    }
}





//公有成员函数


//////////////////////////////////////////////////////////////////////////////
//  构造函数
//  函数功能：构造函数，将根节点置空，初始化停止输入值，初始化扩充二叉树的值
//  函数参数：T类型，用于初始化扩充二叉树的结点
//  函数返回值：无
//
template <class T>
HuffmanTree<T>::HuffmanTree(T d='$')
{
    root=NULL;
    stop=-1;
    extend.data=d;
}


//////////////////////////////////////////////////////////////////////////////
//  析构函数
//  函数功能：释放结点空间
//  函数参数：无
//  函数返回值：无
//
template <class T>
HuffmanTree<T>::~HuffmanTree()
{
    makeEmpty(root);
    root=NULL;
}


//////////////////////////////////////////////////////////////////////////////
//  获得函数
//  函数功能：获得根节点
//  函数参数：无
//  函数返回值：无
//
template <class T>
HuffmanNode<T> *HuffmanTree<T>::getRoot()
{
    return root;
}


//////////////////////////////////////////////////////////////////////////////
//  建树函数
//  函数功能：建立哈夫曼树
//  函数参数：无
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::CreatHuffmanTree()
{
    MinHeap<T> Heap;
    HuffmanNode<T> *p,*firstTree,*secondTree;
    HuffmanNode<T> temp;

    //输入结点的值和相应的权重
    cin>>temp.data>>temp.weight;
    while(temp.weight!=stop)
    {
        p=new HuffmanNode<T>;
        if(p==0)
        {
            cerr<<"存储分配出错！"<<endl;
            exit(1);
        }
        p->data=temp.data;
        p->weight=temp.weight;
        Heap.Insert(p);
        cin>>temp.data>>temp.weight;
    }
    //对最小堆前序遍历
    //Heap.LevelTraverse();

    while(1)
    {
        //当堆中只剩一个结点时说明建树完毕
        if(Heap.Size()==1)break;

        firstTree=Heap.getMin();
        Heap.Remove();
        secondTree=Heap.getMin();
        Heap.Remove();

        //合并两棵子树
        MergeTree(firstTree,secondTree,p);
        //将新的结点插入堆中
        Heap.Insert(p);
    }
    root=p;
}



//////////////////////////////////////////////////////////////////////////////
//  遍历函数
//  函数功能：前序遍历哈夫曼树
//  函数参数：huffman结点类型
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::PreTraverse(HuffmanNode<T> *subTree)
{
    if(subTree!=0)
    {
        cout<<subTree->data<<":"<<subTree->weight<<'['<<subTree->code<<']'<<endl;
        PreTraverse(subTree->leftchild);
        PreTraverse(subTree->rightchild);
    }
}


//////////////////////////////////////////////////////////////////////////////
//  初始化函数
//  函数功能：建立huffman树，对叶子结点进行编码，将整棵树写入文件中
//  函数参数：字符串类型，是要进行操作的文件名
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::Initialization(char *hfmTree)
{
    //建立huffman树
    CreatHuffmanTree();
    //保存结点的编码
    char Code[10];
    //为各个叶子结点编码
    CreatCode(root,Code,0);

    //前序遍历打印huffman树
    cout<<"前序遍历输出huffman树各结点的数据、权重及相应编码："<<endl;
    PreTraverse(root);

    fstream outfile(hfmTree,ios::out|ios::binary);
    //判断文件是否可以正常打开
    if(!outfile)
    {
        cout<<"文件无法正常打开！"<<endl;
        exit(1);
    }
    //将huffman树的数据写入文件中
    WriteHuffmanTree(root,outfile);
    //关闭文件
    outfile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  编码函数
//  函数功能：从文件中读入要进行编码的数据，将编码后的代码写入另一个文件中
//  函数参数：字符串类型，是要进行操作的文件名
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::Encoding(char *hfmTree,char *toBeTran,char *codeFile)
{
    //先判断是否为空树，若为空树，从文件中读入并建立huffman树
    if(root==NULL)
    {
        fstream infile(hfmTree,ios::in|ios::binary);
        //判断文件是否可以正常打开
        if(!infile)
        {
            cout<<"文件无法正常打开！"<<endl;
            exit(1);
        }
        //读入并建立huffman树
        ReadHuffmanTree(root,infile);
        //关闭写有huffman树数据的文件
        infile.close();
        //前序遍历打印huffman树
        //PreTraverse(root);
    }

    //编码
    T data;             //用于保存从文件中读入的数据
    char code[10];      //保存数据对应的编码
    fstream encodingFile(toBeTran,ios::in|ios::binary);
    fstream saveCodeFile(codeFile,ios::out|ios::binary);
    //判断文件是否可以正常打开
    if(!encodingFile||!saveCodeFile)
    {
        cout<<"文件无法正常打开！"<<endl;
        exit(1);
    }

    cout<<"读入的数据及相应编码如下："<<endl;
    while(1)
    {
        //从文件中读入需要编码的数据
        encodingFile.read((char*)&(data),sizeof(data));
        //读入结束
        if(!encodingFile)break;
        //寻找数据对应的编码
        SearchCode(data,code,root);
        //将编码写入另一个文件
        saveCodeFile<<code;
        cout<<data<<':'<<code<<endl;
    }

    //关闭文件
    encodingFile.close();
    saveCodeFile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  译码函数
//  函数功能：从文件中读入要进行译码的代码，进行译码，将译码后的数据写入另一个文件中
//  函数参数：字符串类型，是要进行操作的文件名
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::Decoding(char *hfmTree,char *codeFile,char *textFile)
{
    //先判断是否为空树，若为空树，从文件中读入并建立huffman树
    if(root==NULL)
    {
        fstream infile(hfmTree,ios::in|ios::binary);
        //判断文件是否可以正常打开
        if(!infile)
        {
            cout<<"文件无法正常打开！"<<endl;
            exit(1);
        }
        //读入并建立huffman树
        ReadHuffmanTree(root,infile);
        //关闭写有huffman树数据的文件
        infile.close();
        //前序遍历打印huffman树
        //PreTraverse(root);
    }

    //保存完成译码的数据
    T data[30];
    //读入编码的数据
    char c,code[100];
    int i=0;
    //数据数目
    int count=0;

    fstream saveCodeFile(codeFile,ios::in|ios::binary);
    fstream decodingFile(textFile,ios::out|ios::binary);
    //判断文件是否可以正常打开
    if(!decodingFile||!saveCodeFile)
    {
        cout<<"文件无法正常打开！"<<endl;
        exit(1);
    }

    while(1)
    {
        //读入编码的数据
        saveCodeFile.read((char*)&(c),sizeof(c));
        //读入结束
        if(!saveCodeFile)break;
        code[i]=c;
        i++;
    }
    code[i]='\0';

    cout<<"需要译码的数据：";
    cout<<code<<endl<<endl;
    //译码
    SearchData(data,code,root,0,count);

    //将译码完成的数据写入文件
    cout<<"\n译码完成后的数据：";
    for(i=0;i<=count;i++)
    {
        cout<<data[i];
        decodingFile.write((char*)&(data[i]),sizeof(data[i]));
    }

    //关闭文件
    saveCodeFile.close();
    decodingFile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  打印函数
//  函数功能：从文件中读入代码，打印代码，将代码打印到另一个文件中
//  函数参数：字符串类型，是要进行操作的文件名
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::Print(char *codeFile,char *codePrin)
{
    //保存读入的代码
    char c;
    fstream saveCodeFile(codeFile,ios::in|ios::binary);
    fstream printCodeFile(codePrin,ios::out|ios::binary);
    //判断文件是否可以正常打开
    if(!printCodeFile||!saveCodeFile)
    {
        cout<<"文件无法正常打开！"<<endl;
        exit(1);
    }
    //从文件读出，再写入另一个文件中
    cout<<"打印出代码：";
    while(1)
    {
        //读入代码
        saveCodeFile.read((char*)&(c),sizeof(c));
        //读入结束
        if(!saveCodeFile)break;
        cout<<c;
        //写入保存代码的文件中
        printCodeFile.write((char*)&(c),sizeof(c));
    }
    //关闭文件
    saveCodeFile.close();
    printCodeFile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  打印函数
//  函数功能：用凹入表的形式打印哈夫曼树，并写入另一个文件中
//  函数参数：字符串类型，是要进行操作的文件名
//  函数返回值：无
//
template <class T>
void HuffmanTree<T>::TreePrint(char *hfmTree,char *treePrint)
{
    //先判断是否为空树，若为空树，从文件中读入并建立huffman树
    if(root==NULL)
    {
        fstream infile(hfmTree,ios::in|ios::binary);
        //判断文件是否可以正常打开
        if(!infile)
        {
            cout<<"文件无法正常打开！"<<endl;
            exit(1);
        }
        //读入并建立huffman树
        ReadHuffmanTree(root,infile);
        //关闭写有huffman树数据的文件
        infile.close();
        //前序遍历打印huffman树
        //PreTraverse(root);
    }

    //写入huffman树树形的文件
    fstream treeFile(treePrint,ios::out|ios::binary);
    if(!treeFile)
    {
        cout<<"文件无法正常打开！"<<endl;
        exit(1);
    }

    //输出huffman树，并将huffman树写入文件中
    cout<<"用凹入表形式前序输出huffman树："<<endl;
    TreePrint(root,0,treeFile);
    //关闭打印树的文件
    treeFile.close();
}
