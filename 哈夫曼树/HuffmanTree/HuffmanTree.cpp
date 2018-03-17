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


//˽�г�Ա����


//////////////////////////////////////////////////////////////////////////////
//  �ÿպ���
//  �������ܣ��ݹ麯�����ͷ�huffman���Ľ��ռ���
//  ����������huffman���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::makeEmpty(HuffmanNode<T> *&subTree)
{
    if(subTree!=0)
    {
        //���������ÿ�
        makeEmpty(subTree->leftchild);
        //���������ÿ�
        makeEmpty(subTree->leftchild);
        //�ͷŵ�ǰ���ռ�
        delete subTree;
    }
}


//////////////////////////////////////////////////////////////////////////////
//  �ϲ�����
//  �������ܣ��ϲ����ö����������������¿��ٵĽ����
//  ����������huffman��㣬�ֱ�������Ҫ�ϲ������������µ�˫�׽��
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::MergeTree(HuffmanNode<T> *&tree1,HuffmanNode<T> *&tree2,HuffmanNode<T> *&p)
{
    //�½������Ϊ����������˫��
    p=new HuffmanNode<T>;
    if(p==0)
    {
        cerr<<"�洢�������"<<endl;
        exit(1);
    }
    //˫�׵�Ȩ��Ϊ����������Ȩ��֮��
    p->weight=tree1->weight+tree2->weight;
    p->leftchild=tree1;
    p->rightchild=tree2;
    tree1->parent=p;
    tree2->parent=p;
}


//////////////////////////////////////////////////////////////////////////////
//  ���뺯��
//  �������ܣ���Ҷ�ӽ����б���
//  ����������huffman��㣬�ַ����飬������룬���ͣ��������ĳ���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::CreatCode(HuffmanNode<T>* subTree,char *c,int i)
{
    //��㲻Ϊ��
    if(subTree!=0)
    {
        //�����˫�׽��
        if(subTree->parent!=0)
        {
            //���ӱ��Ϊ0
            if(subTree->parent->leftchild==subTree)
                c[i]='0';
            //�Һ��ӱ��Ϊ1
            else c[i]='1';
            //iָ����һ���ַ�
            i++;
            //Ҷ�ӽ���򱣴����
            if(subTree->leftchild==0&&subTree->rightchild==0)
            {
                //��β���������'\0'
                c[i]='\0';
                strcpy(subTree->code,c);
                return ;
            }
        }
        //����������
        CreatCode(subTree->leftchild,c,i);
        //����������
        CreatCode(subTree->rightchild,c,i);
    }
}


//////////////////////////////////////////////////////////////////////////////
//  д�ļ�����
//  �������ܣ��ݹ麯�������ļ�����huffman��
//  ����������huffman��㣬Ҫд�����ݵ��ļ�
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::WriteHuffmanTree(HuffmanNode<T> *subTree,fstream &file)
{
    if(subTree!=0)
    {
        //д�뵱ǰ���
        file.write((char*)&(*subTree),sizeof(*subTree));
        //file<<subTree->data<<' '<<subTree->weight<<' '<<subTree->code<<' ';
        //д���������
        WriteHuffmanTree(subTree->leftchild,file);
        //д���ұ�����
        WriteHuffmanTree(subTree->rightchild,file);
    }
    else
    {
        //д������ı�־
        file.write((char*)&(extend),sizeof(extend));
        //file<<extend.data<<' '<<extend.weight<<' '<<extend.code<<' ';
    }
}


//////////////////////////////////////////////////////////////////////////////
//  ���ļ�����
//  �������ܣ��ݹ麯�������ļ�����huffman���Ľ�㲢����
//  ����������huffman��㣬Ҫ�������ݵ��ļ�
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::ReadHuffmanTree(HuffmanNode<T> *&subTree,fstream &file)
{
    HuffmanNode<T> *p;
    p=new HuffmanNode<T>;
    file.read((char*)&(*p),sizeof(*p));
    //file>>p->data>>p->weight>>p->code;
    //�ж��Ƿ�Ϊ�ļ���β
    if(!file)
    {
        delete p;
        return ;
    }

    //�����������ַ�
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
//  ���Һ���
//  �������ܣ�Ѱ��ĳ�����ݶ�Ӧ��ĳһҶ�ӽ������ݣ���������Ӧ�ı���
//  ����������Ҫ���ҵ����ݣ��ַ����鱣����룬huffman���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::SearchCode(T x,char *code,HuffmanNode<T> *subTree)
{
    //�����ǿ�
    if(subTree!=0)
    {
        //�ж��Ƿ�ΪѰ�ҵ�Ҷ�ӽ��
        if(subTree->leftchild==0&&subTree->rightchild==0)
        {
            //�ҵ����ݶ�Ӧ�Ľ��
            if(subTree->data==x) strcpy(code,subTree->code);
            return ;
        }

        //�ֱ������������
        SearchCode(x,code,subTree->leftchild);
        SearchCode(x,code,subTree->rightchild);
    }
}


//////////////////////////////////////////////////////////////////////////////
//  ���Һ���
//  �������ܣ�Ѱ��ĳһ�δ����Ӧ��Ҷ�ӽ������ݣ���һ�δ�������
//  �����������������������ݵ����飬�ַ����鱣����룬huffman��㣬��ǰ����Ĵ�����Ŀ������ɹ������ݵ���Ŀ
//  ��������ֵ�������ͣ���ʾ����ɹ���ʧ��
//
template <class T>
bool HuffmanTree<T>::SearchData(T x[],char *code,HuffmanNode<T> *subTree,int i,int &j)
{
    //�����ǿ�
    if(subTree!=0)
    {
        //Ҷ�ӽ��
        if(subTree->leftchild==0&&subTree->rightchild==0)
        {
            cout<<subTree->data<<':'<<subTree->code<<endl;
            x[j]=subTree->data;
            //���������β
            if(code[i]=='\0')return true;
            //�������ݵ���Ŀ
            j++;
            //���ظ��ڵ�
            subTree=root;
        }
        //����������
        if(code[i]=='0') return SearchData(x,code,subTree->leftchild,i+1,j);
        //����������
        else return SearchData(x,code,subTree->rightchild,i+1,j);
    }
    //���ڴ��룬���������������
    return false;
}


//////////////////////////////////////////////////////////////////////////////
//  ��ӡ����
//  �������ܣ��ݹ麯�����ð�������ʽ�������������д���ļ���
//  ����������huffman��㣬�ո���Ŀ�������������ļ�
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::TreePrint(HuffmanNode<T> *subTree,int space,fstream &file)
{
    //��ǰ��㲻��
    if(subTree!=0)
    {
        //����ո񣬲����ո�д���ļ���
        for(int i=0;i<space;i++)
        {
            cout<<' ';
            file<<' ';
        }
        //Ҷ�ӽ�㣬���Ȩ�غ����ݲ�д���ļ���
        if(subTree->rightchild==0&&subTree->rightchild==0)
        {
            cout<<subTree->weight<<"["<<subTree->data<<"]"<<endl;
            file<<subTree->weight<<"["<<subTree->data<<"]"<<'\r'<<'\n';
        }
        //��Ҷ�ӽ�㣬���Ȩ�ز�д���ļ���
        else
        {
            cout<<subTree->weight<<endl;
            file<<subTree->weight<<'\r'<<'\n';
            //��ӡ������
            TreePrint(subTree->leftchild,space+2,file);
            //��ӡ������
            TreePrint(subTree->rightchild,space+2,file);
        }
    }
}





//���г�Ա����


//////////////////////////////////////////////////////////////////////////////
//  ���캯��
//  �������ܣ����캯���������ڵ��ÿգ���ʼ��ֹͣ����ֵ����ʼ�������������ֵ
//  ����������T���ͣ����ڳ�ʼ������������Ľ��
//  ��������ֵ����
//
template <class T>
HuffmanTree<T>::HuffmanTree(T d='$')
{
    root=NULL;
    stop=-1;
    extend.data=d;
}


//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ��ͷŽ��ռ�
//  ������������
//  ��������ֵ����
//
template <class T>
HuffmanTree<T>::~HuffmanTree()
{
    makeEmpty(root);
    root=NULL;
}


//////////////////////////////////////////////////////////////////////////////
//  ��ú���
//  �������ܣ���ø��ڵ�
//  ������������
//  ��������ֵ����
//
template <class T>
HuffmanNode<T> *HuffmanTree<T>::getRoot()
{
    return root;
}


//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ�������������
//  ������������
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::CreatHuffmanTree()
{
    MinHeap<T> Heap;
    HuffmanNode<T> *p,*firstTree,*secondTree;
    HuffmanNode<T> temp;

    //�������ֵ����Ӧ��Ȩ��
    cin>>temp.data>>temp.weight;
    while(temp.weight!=stop)
    {
        p=new HuffmanNode<T>;
        if(p==0)
        {
            cerr<<"�洢�������"<<endl;
            exit(1);
        }
        p->data=temp.data;
        p->weight=temp.weight;
        Heap.Insert(p);
        cin>>temp.data>>temp.weight;
    }
    //����С��ǰ�����
    //Heap.LevelTraverse();

    while(1)
    {
        //������ֻʣһ�����ʱ˵���������
        if(Heap.Size()==1)break;

        firstTree=Heap.getMin();
        Heap.Remove();
        secondTree=Heap.getMin();
        Heap.Remove();

        //�ϲ���������
        MergeTree(firstTree,secondTree,p);
        //���µĽ��������
        Heap.Insert(p);
    }
    root=p;
}



//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ�ǰ�������������
//  ����������huffman�������
//  ��������ֵ����
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
//  ��ʼ������
//  �������ܣ�����huffman������Ҷ�ӽ����б��룬��������д���ļ���
//  �����������ַ������ͣ���Ҫ���в������ļ���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::Initialization(char *hfmTree)
{
    //����huffman��
    CreatHuffmanTree();
    //������ı���
    char Code[10];
    //Ϊ����Ҷ�ӽ�����
    CreatCode(root,Code,0);

    //ǰ�������ӡhuffman��
    cout<<"ǰ��������huffman�����������ݡ�Ȩ�ؼ���Ӧ���룺"<<endl;
    PreTraverse(root);

    fstream outfile(hfmTree,ios::out|ios::binary);
    //�ж��ļ��Ƿ����������
    if(!outfile)
    {
        cout<<"�ļ��޷������򿪣�"<<endl;
        exit(1);
    }
    //��huffman��������д���ļ���
    WriteHuffmanTree(root,outfile);
    //�ر��ļ�
    outfile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  ���뺯��
//  �������ܣ����ļ��ж���Ҫ���б�������ݣ��������Ĵ���д����һ���ļ���
//  �����������ַ������ͣ���Ҫ���в������ļ���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::Encoding(char *hfmTree,char *toBeTran,char *codeFile)
{
    //���ж��Ƿ�Ϊ��������Ϊ���������ļ��ж��벢����huffman��
    if(root==NULL)
    {
        fstream infile(hfmTree,ios::in|ios::binary);
        //�ж��ļ��Ƿ����������
        if(!infile)
        {
            cout<<"�ļ��޷������򿪣�"<<endl;
            exit(1);
        }
        //���벢����huffman��
        ReadHuffmanTree(root,infile);
        //�ر�д��huffman�����ݵ��ļ�
        infile.close();
        //ǰ�������ӡhuffman��
        //PreTraverse(root);
    }

    //����
    T data;             //���ڱ�����ļ��ж��������
    char code[10];      //�������ݶ�Ӧ�ı���
    fstream encodingFile(toBeTran,ios::in|ios::binary);
    fstream saveCodeFile(codeFile,ios::out|ios::binary);
    //�ж��ļ��Ƿ����������
    if(!encodingFile||!saveCodeFile)
    {
        cout<<"�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    cout<<"��������ݼ���Ӧ�������£�"<<endl;
    while(1)
    {
        //���ļ��ж�����Ҫ���������
        encodingFile.read((char*)&(data),sizeof(data));
        //�������
        if(!encodingFile)break;
        //Ѱ�����ݶ�Ӧ�ı���
        SearchCode(data,code,root);
        //������д����һ���ļ�
        saveCodeFile<<code;
        cout<<data<<':'<<code<<endl;
    }

    //�ر��ļ�
    encodingFile.close();
    saveCodeFile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  ���뺯��
//  �������ܣ����ļ��ж���Ҫ��������Ĵ��룬�������룬������������д����һ���ļ���
//  �����������ַ������ͣ���Ҫ���в������ļ���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::Decoding(char *hfmTree,char *codeFile,char *textFile)
{
    //���ж��Ƿ�Ϊ��������Ϊ���������ļ��ж��벢����huffman��
    if(root==NULL)
    {
        fstream infile(hfmTree,ios::in|ios::binary);
        //�ж��ļ��Ƿ����������
        if(!infile)
        {
            cout<<"�ļ��޷������򿪣�"<<endl;
            exit(1);
        }
        //���벢����huffman��
        ReadHuffmanTree(root,infile);
        //�ر�д��huffman�����ݵ��ļ�
        infile.close();
        //ǰ�������ӡhuffman��
        //PreTraverse(root);
    }

    //����������������
    T data[30];
    //������������
    char c,code[100];
    int i=0;
    //������Ŀ
    int count=0;

    fstream saveCodeFile(codeFile,ios::in|ios::binary);
    fstream decodingFile(textFile,ios::out|ios::binary);
    //�ж��ļ��Ƿ����������
    if(!decodingFile||!saveCodeFile)
    {
        cout<<"�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    while(1)
    {
        //������������
        saveCodeFile.read((char*)&(c),sizeof(c));
        //�������
        if(!saveCodeFile)break;
        code[i]=c;
        i++;
    }
    code[i]='\0';

    cout<<"��Ҫ��������ݣ�";
    cout<<code<<endl<<endl;
    //����
    SearchData(data,code,root,0,count);

    //��������ɵ�����д���ļ�
    cout<<"\n������ɺ�����ݣ�";
    for(i=0;i<=count;i++)
    {
        cout<<data[i];
        decodingFile.write((char*)&(data[i]),sizeof(data[i]));
    }

    //�ر��ļ�
    saveCodeFile.close();
    decodingFile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  ��ӡ����
//  �������ܣ����ļ��ж�����룬��ӡ���룬�������ӡ����һ���ļ���
//  �����������ַ������ͣ���Ҫ���в������ļ���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::Print(char *codeFile,char *codePrin)
{
    //�������Ĵ���
    char c;
    fstream saveCodeFile(codeFile,ios::in|ios::binary);
    fstream printCodeFile(codePrin,ios::out|ios::binary);
    //�ж��ļ��Ƿ����������
    if(!printCodeFile||!saveCodeFile)
    {
        cout<<"�ļ��޷������򿪣�"<<endl;
        exit(1);
    }
    //���ļ���������д����һ���ļ���
    cout<<"��ӡ�����룺";
    while(1)
    {
        //�������
        saveCodeFile.read((char*)&(c),sizeof(c));
        //�������
        if(!saveCodeFile)break;
        cout<<c;
        //д�뱣�������ļ���
        printCodeFile.write((char*)&(c),sizeof(c));
    }
    //�ر��ļ�
    saveCodeFile.close();
    printCodeFile.close();
}


//////////////////////////////////////////////////////////////////////////////
//  ��ӡ����
//  �������ܣ��ð�������ʽ��ӡ������������д����һ���ļ���
//  �����������ַ������ͣ���Ҫ���в������ļ���
//  ��������ֵ����
//
template <class T>
void HuffmanTree<T>::TreePrint(char *hfmTree,char *treePrint)
{
    //���ж��Ƿ�Ϊ��������Ϊ���������ļ��ж��벢����huffman��
    if(root==NULL)
    {
        fstream infile(hfmTree,ios::in|ios::binary);
        //�ж��ļ��Ƿ����������
        if(!infile)
        {
            cout<<"�ļ��޷������򿪣�"<<endl;
            exit(1);
        }
        //���벢����huffman��
        ReadHuffmanTree(root,infile);
        //�ر�д��huffman�����ݵ��ļ�
        infile.close();
        //ǰ�������ӡhuffman��
        //PreTraverse(root);
    }

    //д��huffman�����ε��ļ�
    fstream treeFile(treePrint,ios::out|ios::binary);
    if(!treeFile)
    {
        cout<<"�ļ��޷������򿪣�"<<endl;
        exit(1);
    }

    //���huffman��������huffman��д���ļ���
    cout<<"�ð������ʽǰ�����huffman����"<<endl;
    TreePrint(root,0,treeFile);
    //�رմ�ӡ�����ļ�
    treeFile.close();
}
