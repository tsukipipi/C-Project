//////////////////////////////////////////////////////////////////////
//  程序名：main.cpp
//  程序功能：哈夫曼树的应用
//  作者：pipi
//  日期：2016.12.23
//  版本：1.0
//  修改内容：无
//  修改日期：无
//  修改作者：无
//
//

#include <iostream>
#include <windows.h>
#include <stdlib.h>

#include "HuffmanNode.h"
#include "MinHeap.h"
#include "HuffmanTree.h"

#include "HuffmanTree.cpp"
#include "HuffmanNode.cpp"

using namespace std;

int main()
{
    system("color F3");             //修改界面颜色

    int select=1;

    HuffmanTree<char> tree('$');

    while(select!=0)
    {
        cout<<"       哈夫曼树的应用："<<endl;
        cout<<"================================="<<endl;
        cout<<"| 1---初始化并建立哈夫曼树      |"<<endl;
        cout<<"| 2---用哈夫曼树对文件进行编码  |"<<endl;
        cout<<"| 3---用哈夫曼树将文件译码      |"<<endl;
        cout<<"| 4---打印代码文件              |"<<endl;
        cout<<"| 5---打印哈夫曼树              |"<<endl;
        cout<<"| 0---退出                      |"<<endl;
        cout<<"================================="<<endl;
        cout<<"请输入选择：";
        cin>>select;
        system("cls");

        if(select>=0&&select<=5)
        {
            switch(select)
            {
            case 1://初始化并建立哈夫曼树
                cout<<"建立哈夫曼树"<<endl;
                cout<<"请分别输入字符和它对应的权重(输入结束时请将权重输入为-1)："<<endl;

                tree.Initialization("hfmTree.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 2://用哈夫曼树对文件进行编码
                tree.Encoding("hfmTree.dat","ToBeTran.dat","CodeFile.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 3://用哈夫曼树将文件译码
                tree.Decoding("hfmTree.dat","CodeFile.dat","TextFile.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 4://打印代码文件
                tree.Print("CodeFile.dat","CodePrin.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 5://打印哈夫曼树
                tree.TreePrint("hfmTree.dat","TreePrint.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 0://退出系统

                cout<<"退出系统！"<<endl;
                exit(1);

            }//end switch

        }//end if

        else
        {
            cout<<"错误！没有此选项！"<<endl;
            Sleep(1000);
            system("cls");
        }

    }//end while

    return 0;
}
