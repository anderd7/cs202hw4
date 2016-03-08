#include "dynamicarray.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    DynamicArray darr1;
    DynamicArray darr2(6, 0, 5);
    darr1.Display();
    darr2.Display();
    
    return 0;
}
