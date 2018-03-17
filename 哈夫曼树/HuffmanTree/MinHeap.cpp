#include <iostream>
#include <stdlib.h>

#include "MinHeap.h"
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;


//私有成员函数


//////////////////////////////////////////////////////////////////////////////
//  调整函数
//  函数功能：从start位置到m位置下滑调整成为最小堆
//  函数参数：整型，标识要调整的位置
//  函数返回值：无
//
template <class T>
void MinHeap<T>::siftDown(int start,int m)
{
    //temp保存要向下调整的值
    HuffmanNode<T>* temp=heap[start];
    //向下调整，parent作为每次向下比较的下标
    int parent=start;
    //child先保存左孩子的下标，再保存左右孩子中较小的孩子的下标
    int child=2*parent+1;
    //存在孩子，则继续循环向下调整
    while(child<=m)
    {
        //存在右孩子并且右孩子的值小于左孩子，让child保存右孩子的下标
        if(child+1<=m&&(heap[child]->weight)>heap[child+1]->weight)child++;
        if(temp->weight>heap[child]->weight)
        {
            heap[parent]=heap[child];
            parent=child;
            //进入左孩子
            child=2*parent+1;
        }
        else break;
    }
    heap[parent]=temp;
}


//////////////////////////////////////////////////////////////////////////////
//  调整函数
//  函数功能：从start位置到根位置上滑调整成为最小堆
//  函数参数：整型，标识要调整的位置
//  函数返回值：无
//
template <class T>
void MinHeap<T>::siftUp(int start)
{
    //暂存要向上调整的数据的值
    HuffmanNode<T>* temp=heap[start];
    //从start向上调整，child作为每次向上比较的孩子
    int child=start;
    //parent作为每次向上比较的双亲
    int parent;
    //当还未移动到根部时，继续向上调整
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




//公有成员函数


//////////////////////////////////////////////////////////////////////////////
//  构造函数
//  函数功能：初始化堆的大小，将堆置空
//  函数参数：整型，堆的大小
//  函数返回值：无
//
template <class T>
MinHeap<T>::MinHeap(int s)
{
    //初始化堆的大小
    if(s>DefaultSize)maxHeapSize=s;
    else maxHeapSize=DefaultSize;
    //将堆置空
    currentSize=0;
    //申请空间
    heap=new HuffmanNode<T>*[maxHeapSize];
    if(heap==NULL)
    {
        cerr<<"存储分配出错！"<<endl;
        exit(1);
    }
}


//////////////////////////////////////////////////////////////////////////////
//  析构函数
//  函数功能：释放堆的空间
//  函数参数：无
//  函数返回值：无
//
template <class T>
MinHeap<T>::~MinHeap()
{
    //释放堆的空间
    delete []heap;
}


//////////////////////////////////////////////////////////////////////////////
//  置空函数
//  函数功能：将最小堆置空
//  函数参数：无
//  函数返回值：无
//
template <class T>
void MinHeap<T>::makeEmpty()
{
    currentSize=0;
}


//////////////////////////////////////////////////////////////////////////////
//  获得函数
//  函数功能：获得最小值即堆顶
//  函数参数：无
//  函数返回值：无
//
template <class T>
HuffmanNode<T>* MinHeap<T>::getMin()
{
    return heap[0];
}


//////////////////////////////////////////////////////////////////////////////
//  插入函数
//  函数功能：向最小堆中插入元素
//  函数参数：huffman结点类型，要插入的值
//  函数返回值：布尔型，插入成功与否
//
template <class T>
bool MinHeap<T>::Insert(HuffmanNode<T> *x)
{
    //堆满，插入失败
    if(currentSize==maxHeapSize)
    {
        cerr<<"堆满！插入失败！"<<endl;
        return false;
    }

    //插入成功情况

    //先将元素插入在堆的最后一个位置
    heap[currentSize]=x;
    //将该元素向上调整
    siftUp(currentSize);
    //堆的元素数目+1
    currentSize++;

    //返回插入成功
    return true;
}


//////////////////////////////////////////////////////////////////////////////
//  删除函数
//  函数功能：删除堆顶的元素(最小值)
//  函数参数：无
//  函数返回值：布尔型，删除成功与否
//
template <class T>
bool MinHeap<T>::Remove()
{
    //判断是否为空堆
    if(currentSize==0)
    {
        cerr<<"空堆！删除失败！"<<endl;
        return false;
    }

    //删除成功情况

    //用堆的最后一个值覆盖第一个值
    heap[0]=heap[currentSize-1];
    //堆的元素数目-1
    currentSize--;
    //将移动到堆顶的元素向下调整
    siftDown(0,currentSize-1);

    //返回删除成功
    return true;
}


//////////////////////////////////////////////////////////////////////////////
//  判空函数
//  函数功能：判断最小堆是否为空
//  函数参数：无
//  函数返回值：布尔型，标识是否为空堆
//
template <class T>
bool MinHeap<T>::IsEmpty()
{
    if(currentSize==0)return true;
    else return false;
}


//////////////////////////////////////////////////////////////////////////////
//  判满函数
//  函数功能：判断最小堆是否已满
//  函数参数：无
//  函数返回值：布尔型，标识是否堆满
//
template <class T>
bool MinHeap<T>::IsFull()
{
    if(currentSize>=maxHeapSize)return true;
    else return false;
}


//////////////////////////////////////////////////////////////////////////////
//  获得函数
//  函数功能：返回最小堆的元素数目
//  函数参数：无
//  函数返回值：整型，返回最小堆的元素数目
//
template <class T>
int MinHeap<T>::Size()
{
    return currentSize;
}


//////////////////////////////////////////////////////////////////////////////
//  遍历函数
//  函数功能：层次遍历小根堆
//  函数参数：无
//  函数返回值：无
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
