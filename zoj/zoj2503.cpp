#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int main()
{
    char english[11],foreign[11];
    //ÿ�ζ���һ���ַ�
    char Letter;
    //���ڲ�ѯ
    char word[11];
    //��¼�������Ե�ӳ��
    map<string,string> translate;
    //��¼foreign��engliash�����ӳ���Ƿ����
    map<string,bool>appear;
    while(1)
    {
        //�ж��Ƿ������˿���
        if((Letter=getchar())=='\n')
            break;
        english[0]=Letter;
        //�ӵڶ�����ĸ��ʼ
        int i=1;
        while(true)
        {
            Letter=getchar();
            if(Letter==' ')
            {
                english[i]='\0';
                break;
            }
            else
                english[i++]=Letter;
        }
        cin>>foreign;
        //ȥ��foreign����Ļس���
        getchar();
        translate[foreign]=english;
        //��Ӧ�ı�־��Ϊ1
        appear[foreign]=1;
    }
    while(cin>>word)
    {
        //�жϵ����Ƿ���ֹ�
        if(appear[word])cout<<translate[word]<<endl;
        else cout<<"eh"<<endl;
    }

    return 0;
}
