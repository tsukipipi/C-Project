#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int main()
{
    char english[11],foreign[11];
    //每次读入一个字符
    char Letter;
    //用于查询
    char word[11];
    //记录两种语言的映射
    map<string,string> translate;
    //记录foreign与engliash的配对映射是否出现
    map<string,bool>appear;
    while(1)
    {
        //判定是否输入了空行
        if((Letter=getchar())=='\n')
            break;
        english[0]=Letter;
        //从第二个字母开始
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
        //去掉foreign后面的回车符
        getchar();
        translate[foreign]=english;
        //对应的标志置为1
        appear[foreign]=1;
    }
    while(cin>>word)
    {
        //判断单词是否出现过
        if(appear[word])cout<<translate[word]<<endl;
        else cout<<"eh"<<endl;
    }

    return 0;
}
