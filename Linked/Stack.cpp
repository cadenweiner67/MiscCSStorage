#include "Stack.h"
#include <bits/stdc++.h>
using namespace std; 

void Stack::Peek()
{
    if (this->Top != nullptr)
    {
        cout << "Peeking at " << to_string(this->Top->val) << endl;
    }
    else
    {
        cout << "Nothing to peek at" << endl; 
    }
}
void Stack::Push(Node* newNode)
{
    // add to front

    Node* temp; 
    temp = Top; 
    Top = newNode; 
    newNode->nextNode = temp; 
}
Node* Stack::Pop()
{
    if (Top == nullptr)
    {
        return Top;
    }
    Node * temp; 
    temp = Top; 
    Top = Top->nextNode;
    return temp;
}
