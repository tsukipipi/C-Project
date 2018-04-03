#ifndef SORTCLASS_H_INCLUDED
#define SORTCLASS_H_INCLUDED

#define N 10000

class SortTimeCompare
{
private:
    //每组十个数据
    int data[N];

    //划分算法
    void split(int low,int high,int &w);
    //递归快速排序
    void quicksort(int low,int high);

    //合并算法
    void Merge(int low,int mid,int high);
    //归并排序
    void mergesort(int low,int high);

    //选择排序
    void selectsort(int i);

    //将数据写入相应的文件
    void writefile(char *filename);

public:
    //随机数生成函数
    int Random(int m, int n);
    //随机生成数据的函数
    void RandomCreateData();
    //快速排序
    void quicksort();
    //归并排序
    void mergesort();
    //选择排序
    void selectsort();
    //比较三种排序算法的平均排序时间
    void Compare();
};

#endif // SORTCLASS_H_INCLUDED
