#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

/*
*DynamicArray:  Creates a dynamic array with size, min and max values as parameters.  Performs operations to display and manipulate the dynamic array.
*Constructors:
*   DynamicArray();
*   DynamicArray(int s, int rmn, int rmx);
*PublicFunctions:
*   Display
*   Minimum
*   Maximum
*   SwapElements
*   SubArray
*   Concatenate
*Private Data Members:
*   arrayPtr
*   size
*   rangemin
*   rangemax
*Static Variables: N/A
*/
class DynamicArray{
  private:
    int *arrayPtr;
    int size;
    int rangeMin;
    int rangeMax;

  public:
    DynamicArray();
    DynamicArray(int s, int rmn, int rmx);
    ~DynamicArray();
    void Display();
    void Minimum();
    void Maximum();
    void SwapElements(int a, int b);
    void SubArray(int a, int b);
    void Concatenante();
};

#endif