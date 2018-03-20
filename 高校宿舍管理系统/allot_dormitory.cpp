//////////////////////////////////////////////
//
//�ļ�����allot_dormitory.cpp
//�����ܣ�Function��ĳ�Ա����,����ѧ������
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <algorithm>     //sort����
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "student.h"
#include "dormitory.h"
#include "function.h"

using namespace std;


/////////////////////////////////////////////
//�������ắ��
//�������ܣ���������
//������������
//��������ֵ����
//
void Function::allotDormitory()
{
    int tempBoyNum[Maxs],tempGirlNum[Maxs],girlNum,boyNum;//������������ʱ���Ա�ѧ������
    int roomNum,count;
    int studentNumber;
    int select=1,opt=1;
    int room,bed;

    while(select)
    {
        cout<<"            ����������"<<endl;
        cout<<"======================================="<<endl;
        cout<<"| 1.�˹���������&��λ                 |"<<endl;
        cout<<"| 2.ϵͳ������������&��λ(��ѧ�ŷ���) |"<<endl;
        cout<<"| 0.�˳�                              |"<<endl;
        cout<<"======================================="<<endl;
        cout<<"������ѡ��";
        cin>>select;
        cout<<endl;
        system("cls");

        if(select<=2&&select>=0)
        {
            switch(select)
            {
            case 1://�˹����Ŵ�λ
                   cout<<"������ѧ����ѧ�ţ�";
                   cin>>studentNumber;
                   //���Ҳ��ж�ѧ���Ƿ����
                   ps=queryNum(studentNumber);
                   if(ps==NULL)
                   {
                       cout<<"\n�޷��ҵ���ѧ����"<<endl;
                       Sleep(1000);
                       break;
                   }


                   //��ѧ����δ���䵽��λ
                   if(ps->getroomNumber()==0||ps->getbedNumber()==0)
                   {

                       //�ҵ������пմ�λ������
                       cout<<"\n�����������пմ�λ��\n"<<endl;
                       cout<<"�����  ʹ���Ա�"<<endl;
                       for(int i=0;i<=dorNum;i++)
                       {
                           if(dormitory[i].use_dormitory()<4)
                           {
                                cout<<' '<<dormitory[i].getdormitoryNumber()<<"       ";
                                if(dormitory[i].getdormitorySex()=='f')cout<<"Ů"<<endl;
                                else cout<<"��"<<endl;
                           }
                       }

                       //��ӡ��ѧ����Ϣ
                       cout<<"\nѧ����Ϣ���£�"<<endl;
                       ps->show();

                       Sleep(5000);
                       system("cls");

                       while(1)
                       {
                           cout<<"��Ϊ��ѧ���������ἰ��λ��\n"<<endl;
                           cout<<"����������ţ�";
                           cin>>room;

                           //�����������
                           pd=queryroom(room);
                           if(pd==NULL)
                           {
                               cout<<"\n�����ڴ����ᣡ"<<endl;
                               Sleep(1000);
                               system("cls");
                               break;
                           }
                           else
                           {
                               //ѧ���Ա�������ʹ���Ա�һ�²��ܷ��䴲λ
                               if(ps->getsex()==pd->getdormitorySex())
                               {
                                   system("cls");
                                   //չʾ��λʹ�������������ѡ��
                                   pd->showbed();

                                   cout<<"\n\n================"<<endl;
                                   cout<<"|  1.ѡ��λ  |"<<endl;
                                   cout<<"|  0.����      |"<<endl;
                                   cout<<"================"<<endl;
                                   cout<<"��ѡ��";
                                   cin>>opt;

                                   if(opt==1)
                                   {
                                       //ѡ��λ
                                       cout<<"\n�����봲λ��(1~4)��";
                                       cin>>bed;
                                       //�жϴ�λ�Ƿ��ѱ�ʹ��
                                       if(pd->bed_use_case(bed)==1)
                                       {
                                           cout<<"\n���Ŵ��ѱ�ʹ�ã�"<<endl;
                                           Sleep(1000);
                                           system("cls");
                                       }
                                       else
                                       {
                                           system("cls");
                                           //ʹ�ô�λ
                                           ps->setroom_bed(room,bed);
                                           pd->use_bed(bed,ps->getnumber());
                                           //��ʾѧ����Ϣ
                                           cout<<"����ɹ����µ�ѧ����Ϣ���£�\n"<<endl;
                                           ps->show();
                                           Sleep(4000);
                                           system("cls");
                                           break;
                                       }
                                   }
                                   if(opt!=0&&opt!=1)
                                   {
                                       cout<<"\n��������ȷ��ѡ��"<<endl;
                                       Sleep(500);
                                   }
                                   system("cls");
                               }//end if �ж��Ա��Ƿ����
                               else
                               {
                                   cout<<"\n����ʹ���Ա𲻷��ϣ�"<<endl;
                                   Sleep(1000);
                                   system("cls");
                               }
                            }//end else �ж������Ƿ����
                       }//end while
                   }//end if �ж�ѧ���Ƿ��Ѿ������˴�λ
                   else
                   {
                       //��ӡ��ѧ����Ϣ
                       ps->show();

                       cout<<"\n��ѧ���Ѿ������˴�λ��"<<endl;
                       Sleep(2000);
                       system("cls");
                   }

                   break;

            case 2://ϵͳ�������Ŵ�λ����ѧ�Ž��з���
                   //��ʼ��ѧ�������ѧ������
                   boyNum=-1;
                   girlNum=-1;

                   cout<<"���ڷ�����. . ."<<endl;
                   Sleep(1000);

                   //�Ƚ�ѧ���ǵ�ѧ�Ű����Ա�洢�������У��Ա�����
                   for(int i=0;i<=stuNum;i++)
                   {
                       //����δ��ɾ����ѧ��
                       if(student[i].getnote()!=0)
                       {
                           if(student[i].getsex()=='m')
                           {
                               boyNum++;
                               tempBoyNum[boyNum]=student[i].getnumber();
                           }
                           else
                           {
                               girlNum++;
                               tempGirlNum[girlNum]=student[i].getnumber();
                           }
                       }
                   }
                   //��ѧ�����򣬴�С����
                   sort(tempBoyNum,tempBoyNum+boyNum+1);
                   sort(tempGirlNum,tempGirlNum+girlNum+1);


                   //��������&��λ

                   //����
                   roomNum=0;
                   count=1;          //���ڼ�����ÿ�ĸ���һ������
                   for(int i=0;i<=boyNum;i++)
                   {
                       //���ж����ṻ����
                       if(roomNum>dorNum)
                       {
                           cout<<"\n����������������������������ᣡ"<<endl;
                           Sleep(1000);
                           break;
                       }
                       //���ҵ���ѧ��
                       ps=queryNum(tempBoyNum[i]);
                       if(ps==NULL)
                       {
                           cout<<"\n�����޷��ҵ�ѧ����"<<endl;
                           break;
                       }

                       if(count>4)
                       {
                           roomNum++;
                           count=1;     //һ�����ᴲλ��4��
                       }

                       while(1)
                       {
                           //���ж����ṻ����
                           if(roomNum>dorNum) break;
                           //��������&��λ
                           if(dormitory[roomNum].getdormitorySex()=='m')
                           {
                               //����λ��Ϣ�Ǽǵ�ѧ������Ϣ��
                               ps->setroom_bed(dormitory[roomNum].getdormitoryNumber(),count);
                               dormitory[roomNum].use_bed(count,tempBoyNum[i]);
                               count++;
                               break;
                           }
                           else roomNum++;
                       }
                   }

                   //Ů��
                   roomNum=0;
                   count=1;          //���ڼ�����ÿ�ĸ���һ������
                   for(int i=0;i<=girlNum;i++)
                   {
                       //���ж����ṻ����
                       if(roomNum>dorNum)
                       {
                           cout<<"\nŮ��������������������������ᣡ"<<endl;
                           Sleep(1000);
                           break;
                       }
                       //���ҵ���ѧ��
                       ps=queryNum(tempGirlNum[i]);
                       if(ps==NULL)
                       {
                           cout<<"\n�����޷��ҵ�ѧ����"<<endl;
                           break;
                       }

                       if(count>4)
                       {
                           roomNum++;
                           count=1;     //һ�����ᴲλ��4��
                       }

                       while(1)
                       {
                           //�ж����ṻ����
                           if(roomNum>dorNum) break;
                           //��������&��λ
                           if(dormitory[roomNum].getdormitorySex()=='f')
                           {
                               //����λ��Ϣ�Ǽǵ�ѧ������Ϣ��
                               ps->setroom_bed(dormitory[roomNum].getdormitoryNumber(),count);
                               dormitory[roomNum].use_bed(count,tempGirlNum[i]);
                               count++;
                               break;
                           }
                           else roomNum++;
                       }//end while
                   }//end for

                   break;
            }//end switch
            system("cls");
        }//end if
        else
        {
            cout<<"��������ȷ��ѡ��"<<endl;
            Sleep(500);
            system("cls");
        }
    }//end while
}
