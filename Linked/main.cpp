#ifndef MAIN
#define MAIN
#include "linkedlist.h"
#include "Stack.h"
#include "Queue.h"
#include "Sorting.h"
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::map; using std::copy;


// map keywords. 
// map<int, string> map1 = {{1, "Apple",},
//                                 {2, "Banana",},
//                                 {3, "Mango",},
//                                 {4, "Raspberry",},
//                                 {5, "Blackberry",},
//                                 {6, "Cocoa",}};

// map1.find(2)
// map <typename,map<typename,typename>> mp;
// mp[key1].insert(make_pair(key2,value));
//map<int, int> myMap;

// myMap.insert(pair<int, int>(2, 30));
// myMap.insert({3, 70});
// myMap[4] = 20;
// myMap[7] = 50;



// template<typename Map>
// void PrintMap(Map& m)
// {
//     cout << "[ ";
//     for (auto &item : m) {
//         cout << item.first << ":" << item.second << " ";
//     }
//     cout << "]\n";
// }

// int main() {
//     map<int, string> map2;
//     map2[1] = "Banana";
//     map2[2] = "Mango";
//     map2[3] = "Cocoa";
//     map2[4] = "Raspberry";

//     cout << "map2 - ";
//     PrintMap(map2);
//     cout << endl;

//     return EXIT_SUCCESS;
// }










// g++ main.cpp node.cpp node.h LinkedList.cpp LinkedList.h Queue.cpp Queue.h Stack.cpp Stack.h Sorting.cpp Sorting.h
using namespace std; 
void LinkedListDemo();
void QueueDemo();
void StackDemo();
void SwapValues(int *x,int *y);
void SortingDemo();

int main()
{
    // cout << "Linked List Demo" << endl;
    LinkedListDemo(); 


    // cout << "Queue Demo" << endl;
    // QueueDemo();
    // cout << "Stack Demo" << endl;
    // StackDemo();
    // int x = 5; 
    // int y = 10; 
    // cout << to_string(x) << " " << to_string(y) << endl;
    // SwapValues(&x,&y);
    // cout << to_string(x) << " " << to_string(y) << endl;
    // SortingDemo();
    return 0; 
}
void SwapValues(int *x,int *y)
{
    int temp = *y; 
    // cout << to_string(x) << " " << to_string(y) << endl;
    *y = *x; // the variable y's contents are now set to variable x's contents
    *x = temp;
    // int z=20;
    // int * tempP = &z;// * used to get the value at an address. 
    // cout << to_string(*tempP) << endl;
    // use * to get the value stored at an address. 
}

void LinkedListDemo()
{
    Node *node = new Node(1); // assign a value to the pointer
    Node *newNode; 
    Node *deletionNode;
    LinkedList *myList = new LinkedList(node);
    newNode = new Node(2); // assign a new value to a pointer.
    myList->AddToEnd(newNode);
    newNode = new Node(3); // this creates a completely new node and new node now holds its value (the other node created still exisits)
    myList->AddToEnd(newNode);
    newNode = new Node(4);
    myList->AddToEnd(newNode);
    newNode = new Node(5);
    myList->AddToEnd(newNode);
    newNode = new Node(6);
    myList->AddToEnd(newNode);
    newNode = new Node(7);
    myList->AddToEnd(newNode);
    deletionNode = new Node(100);
    myList->AddToBegining(deletionNode);
    newNode = new Node(8);
    myList->AddToEnd(newNode);
    newNode = new Node(9);
    myList->AddToEnd(newNode);
    node->PrintAllNodes();
    newNode = new Node(10);
    myList->AddToBegining(newNode);
    newNode = new Node(11);
    myList->AddToBegining(newNode);
    myList->GetHead()->PrintAllNodes();
    cout << "Reversing List" << endl; 
    myList->reverseList();
    myList->GetHead()->PrintAllNodes();
    // deletion
    myList->DeleteNode(deletionNode); // can delete a middle element
    myList->DeleteNode(newNode); // can delete first node
    myList->GetHead()->PrintAllNodes();



    // deallocate the used memory
    delete myList;
}

void QueueDemo()
{
    Node *newNode; 
    Queue *myQueue = new Queue();
    newNode = new Node(1); // assign a new value to a pointer.
    myQueue->Enqueue(newNode);
    newNode = new Node(2); // assign a new value to a pointer.
    myQueue->Enqueue(newNode);
    newNode = new Node(3); // this creates a completely new node and new node now holds its value (the other node created still exisits)
    myQueue->Enqueue(newNode);
    newNode = new Node(4);
    myQueue->Enqueue(newNode);
    newNode = new Node(5);
    myQueue->Enqueue(newNode);
    newNode = new Node(6);
    myQueue->Enqueue(newNode);
    newNode = new Node(7);
    myQueue->Enqueue(newNode);
    newNode = new Node(8);
    myQueue->Enqueue(newNode);
    newNode = new Node(9);
    myQueue->Enqueue(newNode);
    myQueue->head->PrintAllNodes();
    newNode = new Node(10);
    myQueue->Enqueue(newNode);
    newNode = new Node(11);
    myQueue->Enqueue(newNode);
    myQueue->head->PrintAllNodes();
    // deletion
    myQueue->Dequeue(); 
    myQueue->Dequeue(); 
    myQueue->Dequeue(); 
    myQueue->Dequeue(); 
    myQueue->Peek();
    myQueue->Dequeue(); 
    myQueue->Dequeue(); 
    myQueue->Dequeue(); 
    myQueue->Dequeue(); 
    myQueue->Dequeue(); 
    myQueue->Peek();
    myQueue->Dequeue(); 
    myQueue->Dequeue(); // last
    myQueue->Dequeue(); // when empty
    myQueue->Peek();
    myQueue->head->PrintAllNodes();
    // deallocate the used memory
    delete myQueue;
}

void StackDemo()
{
Node *newNode; 
    Stack *myStack = new Stack();
    newNode = new Node(1); // assign a new value to a pointer.
    myStack->Push(newNode);
    newNode = new Node(2); // assign a new value to a pointer.
    myStack->Push(newNode);
    newNode = new Node(3); // this creates a completely new node and new node now holds its value (the other node created still exisits)
    myStack->Push(newNode);
    newNode = new Node(4);
    myStack->Push(newNode);
    newNode = new Node(5);
    myStack->Push(newNode);
    newNode = new Node(6);
    myStack->Push(newNode);
    newNode = new Node(7);
    myStack->Push(newNode);
    newNode = new Node(8);
    myStack->Push(newNode);
    newNode = new Node(9);
    myStack->Push(newNode);
    myStack->Top->PrintAllNodes();
    newNode = new Node(10);
    myStack->Push(newNode);
    newNode = new Node(11);
    myStack->Push(newNode);
    myStack->Top->PrintAllNodes();
    // deletion
    myStack->Pop(); 
    myStack->Pop(); 
    myStack->Pop(); 
    myStack->Pop(); 
    myStack->Peek();
    myStack->Pop(); 
    myStack->Pop(); 
    myStack->Pop(); 
    myStack->Pop(); 
    myStack->Peek(); 
    myStack->Pop(); 
    myStack->Pop(); 
    myStack->Pop();  // last
    myStack->Pop();  // when empty
    myStack->Peek();
    myStack->Top->PrintAllNodes();
    // deallocate the used memory
    delete myStack;
}
void SortingDemo()
{
    int arr[15] = {20, 10, 20, 3, 4, 5, 67, 8, 1, 2,3 ,7, 13, 15,6};
    Sorting *sort = new Sorting(); 
    sort->PrintList(arr, 15);
    sort->QuickSort(arr, 0, 15);
    sort->PrintList(arr, 15);
    int arr2[15] = {20, 10, 20, 3, 4, 5, 67, 8, 1, 2,3 ,7, 13, 15,6};
    sort->PrintList(arr2, 15);
    sort->MergeSort(arr2, 0, 15);
    sort->PrintList(arr2, 15);
}
#endif 