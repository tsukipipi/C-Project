//////////////////////////////////////////////
//
//�ļ�����administrator.cpp
//�����ܣ�����Ա��ĳ�Ա����
//���ߣ�Pipi
//���ڣ�2016.10.15
//
//////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>	     //getch����ͷ�ļ�
#include <stdlib.h>      //system����ͷ�ļ�
#include <windows.h>     //sleep����ͷ�ļ�

#include "administrator.h"

using namespace std;


/////////////////////////////////////////////
//��ȡ�û�������
//�������ܣ���ȡ�û���
//������������
//��������ֵ���ַ���ָ�룬ָ���û���
//
char *Administrator::getUserName()
{return userName;}


/////////////////////////////////////////////
//��ȡ���뺯��
//�������ܣ���ȡ����
//������������
//��������ֵ���ַ���ָ�룬ָ������
//
char *Administrator::getPassword()
{return password;}


/////////////////////////////////////////////
//���ӹ���Ա����
//�������ܣ����ӹ���Ա
//�����������ַ�ָ�룬���û�����������Ϊ��������������Ա
//��������ֵ����
//
void Administrator::addAdministrator(char *na,char *pass)
{
    strcpy(userName,na);
    strcpy(password,pass);
}
