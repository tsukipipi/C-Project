#include <iostream>
#include <stdlib.h>      //system函数头文件
#include "SortClass.h"
using namespace std;


int main()
{
    //修改界面颜色
    system("color F3");

    SortTimeCompare object;
    object.Compare();

    return 0;
}
