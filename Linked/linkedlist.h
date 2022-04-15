#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
class LinkedList
{
public: 
// constructor
LinkedList(Node * newHead); 
// Linked list destructor
~LinkedList(); 

void AddToEnd(Node *newNode); 
void AddToBegining(Node *newNode);
void DeleteNode(Node *newNode);
void DeleteList(Node * curr);
Node* GetHead();
void reverseList();

private: 
Node * head;
};
#endif