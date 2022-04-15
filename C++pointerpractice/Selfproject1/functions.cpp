#include "functions.h"



void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " "; 
        }
    cout << endl; 
}

int function(int i, int *z)
{
    i = i + *z; 
    z = &i; //z should be changed as well as i even though its value isn't returned
    
    return i; 
}

int fibonacci(int n)
{
    if (n == 0)
    {
        //cout << "We hit our base case" << endl; 
        return 1; 
    }
    if (n == 1)
    {
        //cout << "We hit our base case" << endl; 
        return 1; 
    }

    return n * fibonacci(n-1); 
}

void swap(int *x, int *y)
{ // swaps the values in two items 
    int t = *x; 
    *x = *y; 
    *y = t; 
}

//O(n^2) // not great time complexity
void selectionSort(int arr[], int size)
{//two loops needed. Go through search for the smallest item in 0-n and place it at the front
    //increment the outer loop 
    //go through and search for the min element 1-n and place it at the front increment again and repeat
    int minIndex = 0;  
    for(int j = 0; j < size -1; j++)
    {
        minIndex = j; 
        for(int i = j + 1; i < size;i++)
        {
            if(arr[i] < arr[minIndex])
            {
                minIndex = i; 
            }
        }
        swap(&arr[j], &arr[minIndex]); 
    }
}

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j ++)
        {
            if(arr[j] > arr[j + 1]) // changing the comparator changes the order of sorting from ascending to decending
            {
                swap(&arr[j], &arr[j + 1]); 
            }
        }
    }
}

void recursiveBubble(int arr[], int size)
{
    if (size == 0)
    {
        return; 
    }
    for(int j = 0; j < size - 1; j++)
    {
        if(arr[j] > arr[j + 1])
        {
            swap(&arr[j], &arr[j + 1]); 
        }
    }
    recursiveBubble(arr, size -1); 
}

void insertionSort(int arr[], int size)
{
    int keyValue = 0; 
    int j = 0; 
    for (int i = 1; i < size; i++)
    {
        keyValue = arr[i]; 

        for(j = i - 1;j >= 0 && arr[j] > keyValue ;j--)
        {
            arr[j + 1] = arr[j]; //
        }
        arr[j + 1] = keyValue;  
    }


}

void insertionSortRecursive(int arr[], int size)
{
    //base case size = 1
    if(size <= 1)
    {
        return; 
    }
    insertionSortRecursive(arr, size - 1); 
    int lastItem = arr[size - 1]; 
    int i = size - 2; 
    while(i >= 0 && arr[i] > lastItem)
    {
        arr[i + 1] = arr[i]; 
        i--; 
    }
    arr[i + 1] = lastItem; 
}

void mergeSort(int arr[], int left, int right)
{
    int middle = 0; 
    if(left < right)
    {
        middle = (left + right) / 2; //this is how to find the middle
        mergeSort(arr, left, middle); //this is the left half of the array
        mergeSort(arr, middle + 1, right); //this is the right half of the array
        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i = 0;  
    int j = 0;  
    int k = 0;
    int nL = middle - left + 1;
    int nR = right - middle;
 
   
    int L[nL], R[nR];//left and right temp arrays
    while(i < nL)
    {
        L[i] = arr[left + i];
        i++; 
    }
    while(j < nR)
    {
        R[j] = arr[middle + 1 + j];
        j++; 
    }

    //merge the temp arrays back 
    i = 0; 
    j = 0; 
    k = left; 
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //copies the remaining items in the arrays
    while (i < nL) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nR) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(int arr[],int left,int right)
{
    int p = 0; 
    if(left < right)
    {
        p = partition(arr, left, right); 
        quickSort(arr, left, p - 1); 
        quickSort(arr, p + 1, right); 
    }

}

int partition(int arr[], int left, int right)
{
    int pivot = 0; 
    int i = 0; 
    pivot = arr[right]; 
    i = left - 1; 
    int j = 0; 
    for(j = left; j <= right - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[j]); 
    return (i + 1); 
}

//the array must be sorted first in order to properly search
int binarySearch(int arr[], int SearchItem, int Left, int Right)
{
    int Middle = 0; 
    Middle = Left + (Right - Left) /2; // formula to find the middle of two values
    //we will return the location in the array and negative 1 if the item is not in the array
    if(Right >=1)
    {
        if(SearchItem == arr[Middle])
        {
            return Middle; 
        }
        if(arr[Middle] < SearchItem)
        {
            return binarySearch(arr, SearchItem, Middle + 1, Right); 
        }
        else //if the value is less than the middle
        {
            return binarySearch(arr, SearchItem, Left, Middle - 1);    
        }
    }
    else
    {
        return -1; 
    }
    
}