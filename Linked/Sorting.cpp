#include "Sorting.h"
#include <bits/stdc++.h>
using namespace std;
void Sorting::QuickSort(int arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(arr, low, high); 
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

int Sorting::Partition(int arr[], int low, int high)
{
    // where the actual sorting and partitioning takes place.
    int pivot = arr[high]; // the value we will partition based on
    int i = low - 1; // starting index.
    int temp = 0;
    for (int j = low; j <= high -1; j++)
    {
        if (arr[j] < pivot)
        {
            // swap it with element at i
            // i ++ do not swap i anymore. 
            i++; // we can't start at -1 for indexes
            temp = arr[j]; 
            arr[j] = arr[i];
            arr[i] = temp;

        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp; // put pivot in the middle where it should be. We know remaining element is >= pivot so it can be put to right side.
    return i + 1;
}
void Sorting::PrintList(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}
void Sorting::MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2; 
        MergeSort(arr, left, middle); 
        MergeSort(arr, middle+1, right); 
        Merge(arr, left, middle, right);
    }

}
void Sorting::Merge(int arr[], int left, int middle, int right)
{
    // create two sub arrays
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int leftArr[leftSize];
    int rightArr[rightSize];

    // create sub arr
    for(int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < leftSize; i++)
    {
        rightArr[i] = arr[middle + 1 + i];
    }


    int i = 0; // left tracker
    int j = 0; // right tracker
    int k = left; // arr index tracker
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++; 
        }
        k++;
    }

    // one of these two will be true
    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        i++; 
        j++; 
    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j]; 
        j++; 
        k++; 
    }



}
void Sorting::BubbleSort(int arr[], int n)
{

}
void Sorting::RecBubbleSort(int arr[], int n)
{

}
void Sorting::SelectionSort(int arr[], int n)
{

}