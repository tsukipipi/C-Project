#ifndef DORMITORY_H_INCLUDED
#define DORMITORY_H_INCLUDED

//////////////////////////////////////////////////////
//
//说明：类Dormitory的函数成员的函数体在dormitory.cpp中
//
//////////////////////////////////////////////////////

class Dormitory
{
  private:
      int dormitoryNumber;                //宿舍号
      int bedNum[4];                      //每个床的床位号
      bool bed[4];                        //床位使用情况（0：空床 1：已使用）
      char dormitorySex;                  //女宿舍：f 男宿舍：m
      int beduser[4];                     //每个床位的使用者的学号
      bool delNote;                       //删除标记（0：删除 1：未删）
  public:
      Dormitory();                        //构造函数
      int getdormitoryNumber();           //获得宿舍号
      bool getdelNote();                  //获得删除标记
      char getdormitorySex();             //获得宿舍的使用性别
      int use_dormitory();                //获得宿舍的使用情况
      bool bed_use_case(int bedNum);      //获得具体某个床位的使用情况
      void showbed();                     //展示全部床位的使用情况
      void setdormitoryNumber(int dorNum);//设置宿舍号
      void setdormitorySex(char sex);     //设置宿舍使用性别
      void deletedormitory();             //删除宿舍
      void not_use_bed(int bedNum);       //空出床位
      void use_bed(int bedNum,int num);   //使用床位
      void addDormitory(int num,char sex);//增加宿舍
};

#endif // DORMITORY_H_INCLUDED
