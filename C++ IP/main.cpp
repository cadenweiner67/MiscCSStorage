#include <iostream>
using namespace std; 
#include "functions.h"

#include <stdio.h> 
#include <stdlib.h> 
int main()
{
    int size = 10;
    int arr[size] = {9, 5, 3, 8, 18, 20, -5, -30, 0, 1}; 
    printArray(arr, size); 
    cout << "after sorting" << endl; 
    //selectionSort(arr, size); 
    //bubbleSort(arr, size); 
    //recursiveBubble(arr, size); 
    //insertionSort(arr, size); 
    //insertionSortRecursive(arr, size); 
    //initial left must be 0, initial right is size - 1. 
    //mergeSort(arr,0, size - 1); 
    quickSort(arr, 0, size-1); 

    printArray(arr, size); 

    int foundIndex = 0; 
    foundIndex = binarySearch(arr,3,0,size-1); 
    if (foundIndex == -1)
    {
        cout << "Was not found" << endl; 
    }
    else
    {
        cout << "Was Found at Index: " << foundIndex << "Value: " << arr[foundIndex] << endl; 
    }
    




    cout << "Printing Fibonacci: " << fibonacci(5) << endl; 

    return 0; 
}
 
/*    //practice pointers
    int x = 8; 
    int * n = nullptr; 
    n = &x; 
    cout << "n is: " << *n << endl; 
    x = function(x, n); 
    cout << "New x: " << x << " New n: " << *n << endl; */