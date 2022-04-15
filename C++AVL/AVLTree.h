#include <iostream>
#include "string.h"

//review
/*
Each node contains a left and right child. 
By default they point to the nullptr. 
Each node contains a key(value used for sorting) and a string(the data contained by the node)
*/
struct AVLNode{//a struct is a great way to have the nodes
    public:
    int keyValue; 
    std::string insertionOrder; 
    AVLNode * leftChild; 
    AVLNode * rightChild;
    int nodeHeight; 
}; 
int maxValue(int a, int b); //compairs two values to get the maximum
int getNodeHeight(AVLNode * node);
AVLNode * newNode(int kValue, std::string iOrder);
AVLNode * rotateRight(AVLNode * Y); // x, y, z 
AVLNode * rotateLeft(AVLNode * X); //x, y z
int treeBalance(AVLNode * treeRoot);// checks the trees balance and returns the difference between left and right
AVLNode * insert(AVLNode *node, int kValue, std::string iOrder);
void inorderTraversal(AVLNode* treeRoot); 
void preorderTraversal(AVLNode* treeRoot); 


