#include <iostream>
#include <fstream>
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "reader.h"
#include "rdatabase.h"
#include "book.h"
#include "bdatabase.h"

using namespace std;

int main()
{
    int j=0;                //����ɾ��ĳһ�����ĳһ����ʱ��¼�鱾��λ��

    system("color F3");                 //�޸Ľ�����ɫ

    int choice=1,bookid,readerid;
    RDatabase ReaderDB;
    BDatabase BookDB;
    Reader *r;
    Book *b;

    cout<<"\n\n\n\n\n";
    cout<<"       *       * * *   * * *    * * *         *       * * *     *       *  "<<endl;
    cout<<"       *         *     *    *   *     *      * *      *     *     *   *    "<<endl;
    cout<<"       *         *     * * *    * * *       *   *     * * *         *      "<<endl;
    cout<<"       *         *     *    *   *   *      * * * *    *   *         *      "<<endl;
    cout<<"       * * *   * * *   * * *    *     *   *       *   *     *       *      "<<endl;
    cout<<"--------------------------------------------------------------------------------\n"<<endl;
    cout<<"*************************��ӭ���롰ССͼ��ݡ��������*************************\n"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    Sleep(2000);        //ͣ��ʱ�䵥λ�Ǻ���
    system("cls");      //ҳ�����

    while(choice!=0)
    {
        cout<<"    ����ѡ��"<<endl;
        cout<<"----------------"<<endl;
        cout<<"|  1.����      |"<<endl;
        cout<<"|  2.����      |"<<endl;
        cout<<"|  3.ͼ��ά��  |"<<endl;
        cout<<"|  4.����ά��  |"<<endl;
        cout<<"|  0.�뿪      |"<<endl;
        cout<<"----------------"<<endl;
        cout<<"��ѡ��";
        cin>>choice;
        system("cls");      //ҳ�����

        switch(choice)
        {
            case 1: //����
                   cout<<"���������߱�ţ�";
                   cin>>readerid;
                   cout<<"\n����ͼ���ţ�";
                   cin>>bookid;
                   r=ReaderDB.query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"\n�ö��߲����ڣ����ܽ��飡\n"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   b=BookDB.query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n��ͼ�鲻���ڣ����ܽ��飡\n"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   if(b->borrowbook()==0)
                   {
                       cout<<"\n��ͼ���Ѿ���������ܽ��飡\n"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   r->borrowbook(b->getnumber());
                   Sleep(2000);
                   system("cls");
                   break;

            case 2: //����
                   cout<<"���뻹����߱�ţ�";
                   cin>>readerid;
                   cout<<"\n����ͼ���ţ�";
                   cin>>bookid;
                   r=ReaderDB.query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"\n�ö��߲����ڣ����ܻ��飡"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   b=BookDB.query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n��ͼ�鲻���ڣ����ܻ��飡"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   b->retbook();
                   r->retbook(b->getnumber());
                   Sleep(2000);
                   system("cls");
                   break;

            case 3: //ͼ��ά��
                   BookDB.bookdata();
                   Sleep(2000);
                   system("cls");
                   break;

            case 4: //����ά��
                   ReaderDB.readerdata();
                   Sleep(2000);
                   system("cls");
                   break;
        }//end switch
    }//end while
    return 0;
}
