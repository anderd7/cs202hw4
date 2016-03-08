#include "dynamicarray.h"
#include <iostream>
#include <cstdlib>

using namespace std;


/*
*DynamicArray:  Default constructor.
*Parameters:  N/A
*Return Value:  N/A
*/
DynamicArray::DynamicArray(){
    size = 1;
    rangeMin = 0;
    rangeMax = 0;
    int *darr;
    darr = new int [size];
    arrayPtr = &darr;
}

/*
*DynamicArray:  Paramterized Constructor.  Creates a dynamic array of size "size" and fills with random integers between the given min and max values.
*Parameters:  interger values for size of the array, and min and max values.
*Return Value:  N/A
*/
DynamicArray::DynamicArray(int s, int rmn, int rmx){
    size = s;
    rangeMin = rmn;
    rangeMax = rmx;
    int *darr;
    darr = new int [size];
    arrayPtr = &darr;
    
    for(int i = 0; i < size; i++){
        j = rand() % rangeMin + rangeMax;
        *arrayPtr = j;
        *arrayPtr++;
    }
}

/*
*~DynamicArray:  Destructor.
*Parameters:  N/A
*Return Value: N/A
*/
DynamicArray::~DynamicArray(){
}

void DynamicArray::Display(){
    for(int i = 0; i < size; i++){
        cout << *arrayPtr << endl;
        *arrayPtr++;
    }
    
}

