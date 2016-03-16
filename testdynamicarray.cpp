/*
*David Anderson, CS 202, Assignment 4
*Description: Implement and test a class that represents a dynamic array of integers.  The class will be tested by creating an object with a specified size, minimum value, and maximum value.  Various operations will be performed to display information form the array as well as manipulate the array.  These operations incude displaying all values, the minimum and maximum values as well as their frequency, swaping elements, creating a sub-array, and concatenation between two objects of the array class. 
*Input: Array size, minimum and maximum values.
*Output: Array elements, minimum and maximum values, swapped elements, sub-array, and concatenated array.
*/
#include "dynamicarray.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    //Create objects of DynamicArray class.
    DynamicArray darr1;
    DynamicArray darr2(10,10,20);
    DynamicArray darr3(20, 0, 1000);
    
    //Calls to various functions
    darr1.Display();
    darr1.Minimum();
    darr1.Maximum();
    darr2.Display();
    darr2.Minimum();
    darr2.Maximum();
    darr2.SwapElements(7, 19);
    darr2.SubArray(2, 13);
    darr2.Concatenate(darr3);
    
    return 0;
}

