#include <iostream>
#include <stdlib.h>

#include "MinHeap.h"
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;


//˽�г�Ա����


//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ���startλ�õ�mλ���»�������Ϊ��С��
//  �������������ͣ���ʶҪ������λ��
//  ��������ֵ����
//
template <class T>
void MinHeap<T>::siftDown(int start,int m)
{
    //temp����Ҫ���µ�����ֵ
    HuffmanNode<T>* temp=heap[start];
    //���µ�����parent��Ϊÿ�����±Ƚϵ��±�
    int parent=start;
    //child�ȱ������ӵ��±꣬�ٱ������Һ����н�С�ĺ��ӵ��±�
    int child=2*parent+1;
    //���ں��ӣ������ѭ�����µ���
    while(child<=m)
    {
        //�����Һ��Ӳ����Һ��ӵ�ֵС�����ӣ���child�����Һ��ӵ��±�
        if(child+1<=m&&(heap[child]->weight)>heap[child+1]->weight)child++;
        if(temp->weight>heap[child]->weight)
        {
            heap[parent]=heap[child];
            parent=child;
            //��������
            child=2*parent+1;
        }
        else break;
    }
    heap[parent]=temp;
}


//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ���startλ�õ���λ���ϻ�������Ϊ��С��
//  �������������ͣ���ʶҪ������λ��
//  ��������ֵ����
//
template <class T>
void MinHeap<T>::siftUp(int start)
{
    //�ݴ�Ҫ���ϵ��������ݵ�ֵ
    HuffmanNode<T>* temp=heap[start];
    //��start���ϵ�����child��Ϊÿ�����ϱȽϵĺ���
    int child=start;
    //parent��Ϊÿ�����ϱȽϵ�˫��
    int parent;
    //����δ�ƶ�������ʱ���������ϵ���
    while(child>0)
    {
        parent=(child-1)/2;
        if(heap[parent]->weight>temp->weight)
        {
            heap[child]=heap[parent];
            child=parent;
        }
        else break;
    }
    heap[child]=temp;

}




//���г�Ա����


//////////////////////////////////////////////////////////////////////////////
//  ���캯��
//  �������ܣ���ʼ���ѵĴ�С�������ÿ�
//  �������������ͣ��ѵĴ�С
//  ��������ֵ����
//
template <class T>
MinHeap<T>::MinHeap(int s)
{
    //��ʼ���ѵĴ�С
    if(s>DefaultSize)maxHeapSize=s;
    else maxHeapSize=DefaultSize;
    //�����ÿ�
    currentSize=0;
    //����ռ�
    heap=new HuffmanNode<T>*[maxHeapSize];
    if(heap==NULL)
    {
        cerr<<"�洢�������"<<endl;
        exit(1);
    }
}


//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ��ͷŶѵĿռ�
//  ������������
//  ��������ֵ����
//
template <class T>
MinHeap<T>::~MinHeap()
{
    //�ͷŶѵĿռ�
    delete []heap;
}


//////////////////////////////////////////////////////////////////////////////
//  �ÿպ���
//  �������ܣ�����С���ÿ�
//  ������������
//  ��������ֵ����
//
template <class T>
void MinHeap<T>::makeEmpty()
{
    currentSize=0;
}


//////////////////////////////////////////////////////////////////////////////
//  ��ú���
//  �������ܣ������Сֵ���Ѷ�
//  ������������
//  ��������ֵ����
//
template <class T>
HuffmanNode<T>* MinHeap<T>::getMin()
{
    return heap[0];
}


//////////////////////////////////////////////////////////////////////////////
//  ���뺯��
//  �������ܣ�����С���в���Ԫ��
//  ����������huffman������ͣ�Ҫ�����ֵ
//  ��������ֵ�������ͣ�����ɹ����
//
template <class T>
bool MinHeap<T>::Insert(HuffmanNode<T> *x)
{
    //����������ʧ��
    if(currentSize==maxHeapSize)
    {
        cerr<<"����������ʧ�ܣ�"<<endl;
        return false;
    }

    //����ɹ����

    //�Ƚ�Ԫ�ز����ڶѵ����һ��λ��
    heap[currentSize]=x;
    //����Ԫ�����ϵ���
    siftUp(currentSize);
    //�ѵ�Ԫ����Ŀ+1
    currentSize++;

    //���ز���ɹ�
    return true;
}


//////////////////////////////////////////////////////////////////////////////
//  ɾ������
//  �������ܣ�ɾ���Ѷ���Ԫ��(��Сֵ)
//  ������������
//  ��������ֵ�������ͣ�ɾ���ɹ����
//
template <class T>
bool MinHeap<T>::Remove()
{
    //�ж��Ƿ�Ϊ�ն�
    if(currentSize==0)
    {
        cerr<<"�նѣ�ɾ��ʧ�ܣ�"<<endl;
        return false;
    }

    //ɾ���ɹ����

    //�öѵ����һ��ֵ���ǵ�һ��ֵ
    heap[0]=heap[currentSize-1];
    //�ѵ�Ԫ����Ŀ-1
    currentSize--;
    //���ƶ����Ѷ���Ԫ�����µ���
    siftDown(0,currentSize-1);

    //����ɾ���ɹ�
    return true;
}


//////////////////////////////////////////////////////////////////////////////
//  �пպ���
//  �������ܣ��ж���С���Ƿ�Ϊ��
//  ������������
//  ��������ֵ�������ͣ���ʶ�Ƿ�Ϊ�ն�
//
template <class T>
bool MinHeap<T>::IsEmpty()
{
    if(currentSize==0)return true;
    else return false;
}


//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ��ж���С���Ƿ�����
//  ������������
//  ��������ֵ�������ͣ���ʶ�Ƿ����
//
template <class T>
bool MinHeap<T>::IsFull()
{
    if(currentSize>=maxHeapSize)return true;
    else return false;
}


//////////////////////////////////////////////////////////////////////////////
//  ��ú���
//  �������ܣ�������С�ѵ�Ԫ����Ŀ
//  ������������
//  ��������ֵ�����ͣ�������С�ѵ�Ԫ����Ŀ
//
template <class T>
int MinHeap<T>::Size()
{
    return currentSize;
}


//////////////////////////////////////////////////////////////////////////////
//  ��������
//  �������ܣ���α���С����
//  ������������
//  ��������ֵ����
//
template <class T>
void MinHeap<T>::LevelTraverse()
{
    int i=0;
    while(i<currentSize)
    {
        cout<<heap[i]->data<<' '<<heap[i]->weight<<endl;
        i++;
    }
}
