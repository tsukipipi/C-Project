#include <iostream>
#include <string.h>
#include <queue>

#include "BranchAndBound.h"

using namespace std;


int main()
{
    CostMatrix test;
    test.input();
    test.BranchAndBound();
    return 0;
}
