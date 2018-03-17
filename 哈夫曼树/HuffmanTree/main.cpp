//////////////////////////////////////////////////////////////////////
//  ��������main.cpp
//  �����ܣ�����������Ӧ��
//  ���ߣ�pipi
//  ���ڣ�2016.12.23
//  �汾��1.0
//  �޸����ݣ���
//  �޸����ڣ���
//  �޸����ߣ���
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
    system("color F3");             //�޸Ľ�����ɫ

    int select=1;

    HuffmanTree<char> tree('$');

    while(select!=0)
    {
        cout<<"       ����������Ӧ�ã�"<<endl;
        cout<<"================================="<<endl;
        cout<<"| 1---��ʼ����������������      |"<<endl;
        cout<<"| 2---�ù����������ļ����б���  |"<<endl;
        cout<<"| 3---�ù����������ļ�����      |"<<endl;
        cout<<"| 4---��ӡ�����ļ�              |"<<endl;
        cout<<"| 5---��ӡ��������              |"<<endl;
        cout<<"| 0---�˳�                      |"<<endl;
        cout<<"================================="<<endl;
        cout<<"������ѡ��";
        cin>>select;
        system("cls");

        if(select>=0&&select<=5)
        {
            switch(select)
            {
            case 1://��ʼ����������������
                cout<<"������������"<<endl;
                cout<<"��ֱ������ַ�������Ӧ��Ȩ��(�������ʱ�뽫Ȩ������Ϊ-1)��"<<endl;

                tree.Initialization("hfmTree.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 2://�ù����������ļ����б���
                tree.Encoding("hfmTree.dat","ToBeTran.dat","CodeFile.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 3://�ù����������ļ�����
                tree.Decoding("hfmTree.dat","CodeFile.dat","TextFile.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 4://��ӡ�����ļ�
                tree.Print("CodeFile.dat","CodePrin.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 5://��ӡ��������
                tree.TreePrint("hfmTree.dat","TreePrint.dat");
                Sleep(3000);
                //system("cls");
                break;

            case 0://�˳�ϵͳ

                cout<<"�˳�ϵͳ��"<<endl;
                exit(1);

            }//end switch

        }//end if

        else
        {
            cout<<"����û�д�ѡ�"<<endl;
            Sleep(1000);
            system("cls");
        }

    }//end while

    return 0;
}
