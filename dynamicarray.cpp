/*
*David Anderson, CS 202, Assignment 4
*Description: Implement and test a class that represents a dynamic array of integers.  The class will be tested by creating an object with a specified size, minimum value, and maximum value.  Various operations will be performed to display information form the array as well as manipulate the array.  These operations incude displaying all values, the minimum and maximum values as well as their frequency, swaping elements, creating a sub-array, and concatenation between two objects of the array class. 
*Input: Array size, minimum and maximum values.
*Output: Array elements, minimum and maximum values, swapped elements, sub-array, and concatenated array.
*/

/*
*DynamicArray:  Default constructor.
*Parameters:  N/A
*Return Value:  N/A
*/
DynamicArray::DynamicArray(){
    size = 1;
    rangeMin = 0;
    rangeMax = 0;
    arrayPtr = new int [size];
    *arrayPtr = 0;
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
    arrayPtr = new int [size];
  
    //Fills dynamic array of size "size" with random integers between the rangeMin and rangeMax values.
    for(int i = 0; i < size; i++){
        int j = rand() % ((rangeMax-rangeMin)+1)+rangeMin;
        arrayPtr+i;
        *(arrayPtr+i) = j;
    }
}

/* 
*~DynamicArray:  Destructor.
*Parameters:  N/A
*Return Value: N/A
*/
DynamicArray::~DynamicArray(){
}

/*
*Display:  Displays the integers stored in the dynamic array.
*Parameters:  N/A
*Return Value: N/A
*/
void DynamicArray::Display(){
    
    //incrememnts through the array and prints the values.
    for(int i = 0; i < size; i++){
        arrayPtr+i;
        cout << "Address of arrayPtr[" << i << "] is " <<arrayPtr+i << " and the value stored is " << *(arrayPtr+i) << "." << endl;
    }
    cout << endl;
}

/*
*Minimum:  Finds the smallest integer and its frequency in the object's array.
*Parameters:  N/A
*Return Value:  N/A
*/
void DynamicArray::Minimum(){

    int count = 0;
    int total;
    //Sets minimum value to the value stored in position 0 or array.
    int min = *arrayPtr;
  
    //Compares array elements to each other to find minimum value.
    for(int i = 1; i < size; i++){
        if(*(arrayPtr+i) < min){
            min = *(arrayPtr+i);
        }
    }
    
    //Iterates through array to find occurences of minimum value.
    for(int i = 0; i < size; i++){
        if(min == *(arrayPtr+i)){
            count++;
            total = count;
        }
    }
    
    if(count == 1)
        cout << "Minimum value is " << min << " and appears " << total << " time." << endl;
    else
        cout << "Minimum value is " << min << " and appears " << total << " times." << endl;
}

/*
*Maximum:  Finds the smallest integer and its frequency in the object's array.
*Parameters:  N/A
*Return Value:  N/A
*/
void DynamicArray::Maximum(){
  
    int count = 0;
    int total;
    //Sets maximum value to value stored in position 0 of array.
    int max = *arrayPtr;
    
    //Compares elements of array to find maximum value.
    for(int i = 1; i < size; i++){
        if(*(arrayPtr+i) > max){
            max = *(arrayPtr+i);
        }
    }
    
    //Iterates through array to find occureces of maximum value.
    for(int i = 0; i < size; i++){
        if(max == *(arrayPtr+i)){
            count++;
            total = count;
        }
    }
    
    if(count == 1)
        cout << "Maximum value is " << max << " and appears " << total << " time." << endl;
    else
        cout << "Maximum value is " << max << " and appears " << total << " times." << endl;
    cout << endl;
}

/*
SwapElements:  Swaps the values stored in two elements of array.
Parameters:  Two integers between 0 and array size - 1.
Return value:  N/A
*/
void DynamicArray::SwapElements(int a, int b){
    
    cout << "arrayPtr[" << a << "]" << " is "<< *(arrayPtr+a) << " and " << "arrayPtr[" << b << "]" << " is "<<  *(arrayPtr+b) << endl;
    int temp = 0;
    //sets temp to the value at arrPtr+a
    temp = *(arrayPtr+a);
    //Sets value at arrayPtr+a to  value of arrayPtr+b
    *(arrayPtr+a) =  *(arrayPtr+b);
    //Sets value at arrayPtr+b to value of temp
    *(arrayPtr+b) = temp;
    cout << "arrayPtr[" << a << "]" << " is "<< *(arrayPtr+a) << " and " << "arrayPtr[" << b << "]" << " is "<<  *(arrayPtr+b) << endl;
    cout << endl;
}


/*
*SubArray:  Creates a new array which hs a size of the difference between to elements.  All elements between the two positions passed in are stored in the new array.  The new array replaces the orignal array.
*Parameters:  Two integers between 0 and array size-1.
*Return Value:  N/A
*/
void DynamicArray::SubArray(int a, int b){
    int *subarrayPtr;
    int subsize;
    //Assures a positive value.
    if(b <= size - 1) {
        if (a >= 0 && a <= b) {
            subsize = (b - a) + 1;
        }
        
        subarrayPtr = new int [subsize];
        
        //Copies elements of original array to new array.
        for(int i = 0; i < b; i++){
            *(subarrayPtr+i) = *(arrayPtr+(a+i)); 
        }
        
        //deallocates the arrayPtr
        delete [] arrayPtr;
        //Assigns subarray to arrayPtr
        arrayPtr = subarrayPtr;
        size = subsize;
    }
    
    Display();
    Minimum();
    Maximum();
}

/*
*Concatenate: Adds a new array onto the end of the original array. 
*Parameters: A DynamicArray object.
*Return Value: N/A
*/
void DynamicArray::Concatenate(DynamicArray darr){
    int *conarrayPtr;
    int newsize = size + darr.size;
    
    conarrayPtr = new int [newsize];
    
    for(int i = 0; i < size; i++){
        *(conarrayPtr+i) = *(arrayPtr+i);
    }
    
    for(int i = size; i < newsize; i++){
        *(conarrayPtr+i) = *((darr.arrayPtr)+i);
    }
    
    //deallocates the arrayPtr
    delete [] arrayPtr;
    //Assigns conarrayPtr to arrayPtr
    arrayPtr = conarrayPtr;
    
    size = newsize;
    
    Display();
    Minimum();
    Maximum();
}