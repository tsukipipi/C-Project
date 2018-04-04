#include <iostream>
#include <queue>

#define Max 100

using namespace std;

//�ڽӾ���
int cost[Max][Max];
//������Ŀ
int n;
//����ֵ
struct Edge{
    int start;
    int end;
    int value;
}distant[Max],temp;


bool operator<(const Edge &a ,const Edge &b )
{
    if(a.value>b.value) return true ;
    else return false;
}

priority_queue <Edge> PQ;


void Input()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
}

void Dijkstra(int start)
{
    //���ó��������ڵıߵ�Ȩ���޸ľ���ֵ���ֵ�����������ȶ�����
    for(int i=0;i<n;i++)
    {
        distant[i].start=start;
        distant[i].end=i;
        distant[i].value=cost[start][i];
        PQ.push(distant[i]);
    }
    //����������Ϊ�ѷ��ʹ�����1��ʾ���ʹ�
    cost[start][start]=1;

    //�����ж��Ƿ��ҵ���һ����������·��
    bool flag;
    //n��������Ҫ�ҵ�n-1����������·��
    for(int i=0;i<n-1;i++)
    {
        flag=false;
        //�ҳ���һ�����·��
        while(!flag&&!PQ.empty())
        {
            temp=PQ.top();
            PQ.pop();
            //�������δ���ʱ�ʾ�ҵ��ö�������·��
            if(cost[temp.end][temp.end]==0)
                flag=true;
        }
        //�������־λ�ѷ���
        cost[temp.end][temp.end]=1;
        //�������ڵ�δ���ʹ��Ĳ��Ҿ���ֵС��ԭ�Ⱦ���ı߲�����С���ȶ���
        for(int j=0;j<n;j++)
        {
            //������δ���ʹ��ҵ�ǰ·�����ڴӽ��temp.end��ת��·��
            if((distant[j].value>distant[temp.end].value+cost[temp.end][j])&&cost[j][j]==0)
            {
                distant[j].start=temp.end;
                //�޸ľ���ֵ��
                distant[j].value=distant[temp.end].value+cost[temp.end][j];
                PQ.push(distant[j]);
            }
        }
    }

}


void Output(int start)
{
    for(int i=0;i<n;i++)
        cout<<start<<"--->"<<i<<":"<<distant[i].value<<endl;
}

int main()
{
    Input();
    Dijkstra(0);
    Output(0);
    return 0;
}
