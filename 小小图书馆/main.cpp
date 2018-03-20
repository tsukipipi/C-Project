#include <iostream>
#include <fstream>
#include <stdlib.h>      //system函数头文件
#include <windows.h>     //sleep函数头文件

#include "reader.h"
#include "rdatabase.h"
#include "book.h"
#include "bdatabase.h"

using namespace std;

int main()
{
    int j=0;                //用于删除某一本书或某一读者时记录书本的位置

    system("color F3");                 //修改界面颜色

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
    cout<<"*************************欢迎进入“小小图书馆”管理软件*************************\n"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    Sleep(2000);        //停留时间单位是毫秒
    system("cls");      //页面清除

    while(choice!=0)
    {
        cout<<"    功能选择："<<endl;
        cout<<"----------------"<<endl;
        cout<<"|  1.借书      |"<<endl;
        cout<<"|  2.还书      |"<<endl;
        cout<<"|  3.图书维护  |"<<endl;
        cout<<"|  4.读者维护  |"<<endl;
        cout<<"|  0.离开      |"<<endl;
        cout<<"----------------"<<endl;
        cout<<"请选择：";
        cin>>choice;
        system("cls");      //页面清除

        switch(choice)
        {
            case 1: //借书
                   cout<<"输入借书读者编号：";
                   cin>>readerid;
                   cout<<"\n输入图书编号：";
                   cin>>bookid;
                   r=ReaderDB.query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"\n该读者不存在，不能借书！\n"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   b=BookDB.query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n该图书不存在，不能借书！\n"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   if(b->borrowbook()==0)
                   {
                       cout<<"\n该图书已经借出，不能借书！\n"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   r->borrowbook(b->getnumber());
                   Sleep(2000);
                   system("cls");
                   break;

            case 2: //还书
                   cout<<"输入还书读者编号：";
                   cin>>readerid;
                   cout<<"\n输入图书编号：";
                   cin>>bookid;
                   r=ReaderDB.query(readerid,j);
                   if(r==NULL)
                   {
                       cout<<"\n该读者不存在，不能还书！"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   b=BookDB.query(bookid,j);
                   if(b==NULL)
                   {
                       cout<<"\n该图书不存在，不能还书！"<<endl;
                       Sleep(2000);
                       system("cls");
                       break;
                   }
                   b->retbook();
                   r->retbook(b->getnumber());
                   Sleep(2000);
                   system("cls");
                   break;

            case 3: //图书维护
                   BookDB.bookdata();
                   Sleep(2000);
                   system("cls");
                   break;

            case 4: //读者维护
                   ReaderDB.readerdata();
                   Sleep(2000);
                   system("cls");
                   break;
        }//end switch
    }//end while
    return 0;
}
