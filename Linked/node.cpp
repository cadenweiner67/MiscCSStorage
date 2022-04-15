#include "node.h"
#include <bits/stdc++.h>
using namespace std;
Node::Node(int value)
{
    cout << "This is the Class Constructor\n";
    this->val = value;
    this->nextNode = nullptr;
}
Node::~Node()
{
    cout << "This is the Class Destructor for " << to_string(this->val)  << endl;
}
// void Node::LinkNode(Node *newNode)
// {
//     Node *temp; 
//     temp = this;

//     while(temp->nextNode != nullptr)
//     {
//         temp = temp->nextNode;
//     }
//     temp->nextNode = newNode;
// } 
// delete a node if we can find it else return zero. 
// int Node::DeleteNode(int value)
// {
//     Node * temp = this; 
//     while(temp->nextNode !=nullptr)
//     {
//         cout << "At " << to_string(temp->nextNode->val) << endl; 
//         if (temp->nextNode->val == value)
//         {
//             cout << "Found Value";
//             // we found the value to delete.
//             if (temp->nextNode->nextNode != nullptr)
//             {
//                 temp->nextNode = temp->nextNode->nextNode;
//             }
//             else
//             {
//                 temp->nextNode = nullptr; // deleting last item
//             }
//         }
//         // temp = temp->nextNode // changes the value stored at temp, doesn't cause any changes to pointer. 
//         // temp->nextNode = randomNode; // changes what cell the node actually points at changes will effect everything. this actually will change a class object
//         temp = temp->nextNode; // move to the next node
//     }
//     cout << endl;

//     return -1; 
// }
// print all the nodes following this one. 
void Node::PrintAllNodes()
{
    Node *temp;
    temp = this;
    while(temp != nullptr)
    {
        cout << to_string((*temp).val) << " ";
        temp = temp->nextNode;
    }
    cout << "\n";
} 
// add node to the end of list
void AddNodeToEnd();