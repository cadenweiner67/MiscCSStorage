#ifndef SORTING_H
#define SORTING_H
class Sorting
{
public: 
void QuickSort(int arr[], int low, int high); // an array and a length
int Partition(int arr[], int low, int high); // should be private
void MergeSort(int arr[], int low, int high); // an array and a length
void Merge(int arr[], int low, int middle, int high);
void BubbleSort(int arr[], int n); // an array and a length
void RecBubbleSort(int arr[], int n); // an array and a length
void SelectionSort(int arr[], int n); // an array and a length
void PrintList(int arr[], int n);

};

#endif