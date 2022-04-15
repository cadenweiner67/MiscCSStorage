#ifndef NODE_H
#define NODE_H
class Node
{
public: 
Node(int value);
~Node();
// void LinkNode(Node *newNode); 
// delete a node if we can find it else return zero. 
// int DeleteNode(int value); 
// print all the nodes following this one. 
void PrintAllNodes(); 

Node *nextNode;
int val;
private: 
// need getters and setters not doing this for ease of use. 
};
#endif