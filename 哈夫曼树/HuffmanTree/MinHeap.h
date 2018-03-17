#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

#define DefaultSize 30
#include "HuffmanNode.h"

//��С������ȫ������
template <class T>
class MinHeap{
private:
    //�����С����Ԫ�ص�����
    HuffmanNode<T>* *heap;
    //��С�ѵ�ǰԪ�ظ���
    int currentSize;
    //��С����������Ԫ�ظ���
    int maxHeapSize;

    //��start��m�»�������Ϊ��С��
    void siftDown(int start,int m);
    //��start��0�ϻ�������Ϊ��С��
    void siftUp(int start);

public:
    //���캯��
    MinHeap(int s=DefaultSize);
    //��������
    ~MinHeap();
    //����С���ÿ�
    void makeEmpty();
    //�����Сֵ
    HuffmanNode<T>* getMin();
    //����С���в���Ԫ��
    bool Insert(HuffmanNode<T> *x);
    //ɾ���Ѷ���Ԫ��(��Сֵ)
    bool Remove();
    //�ж���С���Ƿ�Ϊ��
    bool IsEmpty();
    //�ж���С���Ƿ�����
    bool IsFull();
    //������С�ѵ�Ԫ����Ŀ
    int Size();
    //��α���С����
    void LevelTraverse();
};

#endif // MINHEAP_H_INCLUDED
