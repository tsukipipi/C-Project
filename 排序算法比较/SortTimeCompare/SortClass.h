#ifndef SORTCLASS_H_INCLUDED
#define SORTCLASS_H_INCLUDED

#define N 10000

class SortTimeCompare
{
private:
    //ÿ��ʮ������
    int data[N];

    //�����㷨
    void split(int low,int high,int &w);
    //�ݹ��������
    void quicksort(int low,int high);

    //�ϲ��㷨
    void Merge(int low,int mid,int high);
    //�鲢����
    void mergesort(int low,int high);

    //ѡ������
    void selectsort(int i);

    //������д����Ӧ���ļ�
    void writefile(char *filename);

public:
    //��������ɺ���
    int Random(int m, int n);
    //����������ݵĺ���
    void RandomCreateData();
    //��������
    void quicksort();
    //�鲢����
    void mergesort();
    //ѡ������
    void selectsort();
    //�Ƚ����������㷨��ƽ������ʱ��
    void Compare();
};

#endif // SORTCLASS_H_INCLUDED
