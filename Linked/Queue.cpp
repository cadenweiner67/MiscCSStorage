#include "Queue.h"
#include <bits/stdc++.h>
using namespace std; 
Queue::Queue()
{
    this->head = nullptr; 
    this->tail = nullptr;
}

Queue::~Queue()
{
    cout << "Deleting Queue from Destructor" << endl;
    if (head !=nullptr && tail != nullptr)
    {
        DeleteQueue(head); 
    }
    // this->head = nullptr; 
    // this->tail = nullptr;
}

void Queue::DeleteQueue(Node * curr)
{
    Node * temp;
    if (curr->nextNode == nullptr)
    {
        // we will delete the node now, base case
        cout << "Deleting Head" << endl;
        delete curr;
        head = nullptr;
    }
    else
    {
        cout << "Rec" << endl;
        temp = curr; 
        DeleteQueue(curr->nextNode);
        delete temp;
    }
}

void Queue::Enqueue(Node* newNode)
{
    if (this->head == nullptr)
    {
        // first node in queue
        this->head = newNode; 
        this->tail = newNode;
    }
    else
    {
        // valid head
        // Node * temp;
        // temp = this->tail;
        // temp->nextNode = newNode;
        // this.tail = temp;
        this->tail->nextNode = newNode; 
        this->tail = newNode;
    }






}
Node * Queue::Dequeue()
{
    if(this->head == nullptr)
    {
        this->tail = nullptr; // tail and head must be same
        cout << "Cannot Dequeue an empty node" << endl;
        return nullptr;     
    }
    Node * temp;
    temp = head;
    head = head->nextNode;
    cout << "Dequeueing" << endl;
    if (head == nullptr)
    {
        // removing last item from queue
        this->tail = nullptr; 
        cout << "Dequeueing last element" << endl;
    }

    return temp; 
}

void Queue::Peek()
{
    if (this->head != nullptr)
    {
        cout << "Peeking at " << to_string(this->head->val) << endl;
    }
    else
    {
        cout << "Nothing to peek at" << endl; 
    }
}