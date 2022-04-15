#include "linkedlist.h"
#include <bits/stdc++.h>
using namespace std; 
LinkedList::LinkedList(Node * newHead)
{
    this->head = newHead;
    cout << "LinkedList Constructor" << endl;
}
// Linked list destructor
LinkedList::~LinkedList()
{
    cout << "LinkedList Destructor" << endl;
    cout << "Deleting List" << endl;
    DeleteList(head);
}

void LinkedList::DeleteList(Node * curr)
{
    Node * temp;
    if (curr->nextNode == nullptr)
    {
        // we will delete the node now, base case
        cout << "Deleting Head" << endl;
        delete curr;
    }
    else
    {
        DeleteList(curr->nextNode);
        delete curr;
    }
}

void LinkedList::AddToEnd(Node *newNode)
{
    Node * temp;
    temp = head; 
    if (head == nullptr)
    {
        this->head = newNode; // new node is the first node
        return;
    }
    while(temp->nextNode != nullptr)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
    return;
}

void LinkedList::AddToBegining(Node *newNode)
{
    Node* temp; 
    temp = head; 
    head = newNode; 
    head->nextNode = temp;
}

void LinkedList::DeleteNode(Node *newNode)
{
    Node* temp; 
    temp = head; // change the address stored in variable; (*temp) // get the value at address ie a node. ->method = (*var).method
    if (head == nullptr)
    {
        return;
    }
    if (temp == newNode)
    {
        // check first node
        head = head->nextNode; // replace head.
        cout << "Deleting First Node" << endl;
        delete newNode; // release memory
        return;
    }

    while (temp->nextNode != nullptr)
    {
        if (temp->nextNode == newNode)
        {
            // we can compare addresses to determine if they are the same node.
            temp->nextNode = temp->nextNode->nextNode; // replaces value of next node
            delete newNode; // release its memory;
            return;
        }
        temp = temp->nextNode;
    }
    return;
}

Node* LinkedList::GetHead()
{
    return this->head;
}

void LinkedList::reverseList() {
        if (this->GetHead() == nullptr)
        {
        return; // no list to reverse. 
        }
        
        Node *curr = this->GetHead()->nextNode; 
        Node * prev = this->GetHead(); 
        Node * tail = this->GetHead(); // the node we will return. Set it equal to tail because that is what it should be if there is no next node. 
        
        while(curr != nullptr)
        {
        Node *next = curr->nextNode; // point at the next node so we don't loose its value. 
        if (next == nullptr)
        {
            tail = curr; // set the tail node to the last node in original list.
        }
            curr->nextNode = prev;  // change currents next value
            prev = curr; // the current node is the new prev node
            curr = next; // the next node is now the current node
        }
        this->GetHead()->nextNode = nullptr; // cut off old head from linked list. 
        this->head = tail;
    }
