#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
class Queue
{
    public: 
    Queue();
    ~Queue();
    void DeleteQueue(Node * curr);
    void Enqueue(Node* newNode); 
    Node * Dequeue();
    void Peek();
    Node* tail; 
    Node* head;

};
#endif // QUEUE_H