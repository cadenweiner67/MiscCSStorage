#ifndef STACK_H
#define STACK_H
#include "node.h"
class Stack
{
public: 
void Peek(); 
void Push(Node* newNode);
Node* Pop();

Node * Top;
};
#endif