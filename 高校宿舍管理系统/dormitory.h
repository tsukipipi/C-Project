#ifndef DORMITORY_H_INCLUDED
#define DORMITORY_H_INCLUDED

//////////////////////////////////////////////////////
//
//˵������Dormitory�ĺ�����Ա�ĺ�������dormitory.cpp��
//
//////////////////////////////////////////////////////

class Dormitory
{
  private:
      int dormitoryNumber;                //�����
      int bedNum[4];                      //ÿ�����Ĵ�λ��
      bool bed[4];                        //��λʹ�������0���մ� 1����ʹ�ã�
      char dormitorySex;                  //Ů���᣺f �����᣺m
      int beduser[4];                     //ÿ����λ��ʹ���ߵ�ѧ��
      bool delNote;                       //ɾ����ǣ�0��ɾ�� 1��δɾ��
  public:
      Dormitory();                        //���캯��
      int getdormitoryNumber();           //��������
      bool getdelNote();                  //���ɾ�����
      char getdormitorySex();             //��������ʹ���Ա�
      int use_dormitory();                //��������ʹ�����
      bool bed_use_case(int bedNum);      //��þ���ĳ����λ��ʹ�����
      void showbed();                     //չʾȫ����λ��ʹ�����
      void setdormitoryNumber(int dorNum);//���������
      void setdormitorySex(char sex);     //��������ʹ���Ա�
      void deletedormitory();             //ɾ������
      void not_use_bed(int bedNum);       //�ճ���λ
      void use_bed(int bedNum,int num);   //ʹ�ô�λ
      void addDormitory(int num,char sex);//��������
};

#endif // DORMITORY_H_INCLUDED
