#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

#define DefaultSize 30
#include "HuffmanNode.h"

//最小堆是完全二叉树
template <class T>
class MinHeap{
private:
    //存放最小堆中元素的数组
    HuffmanNode<T>* *heap;
    //最小堆当前元素个数
    int currentSize;
    //最小堆最多允许的元素个数
    int maxHeapSize;

    //从start到m下滑调整成为最小堆
    void siftDown(int start,int m);
    //从start到0上滑调整成为最小堆
    void siftUp(int start);

public:
    //构造函数
    MinHeap(int s=DefaultSize);
    //析构函数
    ~MinHeap();
    //将最小堆置空
    void makeEmpty();
    //获得最小值
    HuffmanNode<T>* getMin();
    //向最小堆中插入元素
    bool Insert(HuffmanNode<T> *x);
    //删除堆顶的元素(最小值)
    bool Remove();
    //判断最小堆是否为空
    bool IsEmpty();
    //判断最小堆是否已满
    bool IsFull();
    //返回最小堆的元素数目
    int Size();
    //层次遍历小根堆
    void LevelTraverse();
};

#endif // MINHEAP_H_INCLUDED
