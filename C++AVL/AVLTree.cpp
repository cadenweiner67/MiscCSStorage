#include "AVLTree.h"
/*working*/
int maxValue(int a, int b)
{
    if (a > b)
    {
        return a; 
    }
    else 
    {
        return b; 
    }
}
/*working*/
int getNodeHeight(AVLNode * node)
{
    if(node == NULL)
    {
        return 0; 
    }
    else 
    {
        return node->nodeHeight; 
    }
}
/*working*/    
AVLNode * newNode(int kValue, std::string iOrder)
{
    //creates memory for a new node, sets the values
    //returns the created node
    //the left and right childs of the node are set to 
    //null by default. 
    AVLNode *newNode = new AVLNode(); //allocates memory for the node
    newNode->keyValue = kValue; 
    newNode->insertionOrder = iOrder; 
    newNode->leftChild = NULL;
    newNode->rightChild = NULL; 
    newNode->nodeHeight = 1; //initially a leaf so height 1 when added
    return(newNode); 
}
/*working*/    
AVLNode * rotateRight(AVLNode * Y) //Y is the parent of x
{
    //Using Rotation Diagram
    AVLNode * X = Y->leftChild; 
    AVLNode *Xrc = X->rightChild; 

    X->rightChild = Y; // set X's right child to Y
    Y->leftChild = Xrc; //first step set Y's new left child to C's right child

    // now that it has been rotated we must adjust the heights of X and Y

    Y->nodeHeight = maxValue(getNodeHeight(Y->leftChild), getNodeHeight(Y->rightChild)) + 1; 
    //the new node height of X and Y are based off of the max height of their childs and then one is added since the new height is one higher than the max. 
    X->nodeHeight = maxValue(getNodeHeight(X->leftChild), getNodeHeight(X->rightChild)) + 1; 

    return X;   //this is the new root value
}
/*working*/    
AVLNode * rotateLeft(AVLNode * X)
{
    //Using Rotation Diagram
    AVLNode *Y = X->rightChild; 
    AVLNode *Ylc = Y->leftChild; 

    Y->leftChild = X;  // set Y's left child to X
    X->rightChild = Ylc; //set X's right child to Y's left child; 

    Y->nodeHeight = maxValue(getNodeHeight(Y->leftChild), getNodeHeight(Y->rightChild)) + 1; 
    //the new node height of X and Y are based off of the max height of their childs and then one is added since the new height is one higher than the max. 
    X->nodeHeight = maxValue(getNodeHeight(X->leftChild), getNodeHeight(X->rightChild)) + 1;
    return Y;  

}
/*working*/    
int treeBalance(AVLNode * treeRoot)
{
    if(treeRoot == NULL)//tree is empty so height is zero
    {
        return 0; 
    }
    else
    {//returns the difference between the left and right childreb, this difference determines if there is a rotation and which type of rotation occurs
        return getNodeHeight(treeRoot->leftChild) - getNodeHeight(treeRoot->rightChild); 
    }
    
} 
/**/    
AVLNode * insert(AVLNode *node, int kValue, std::string iOrder)
{
    //case 1 tree is empty, we must insert a new node
    if(node == NULL)//base condition for insertion of a node
    {
        std::cout << "Inserting a Node" << std::endl; 
        return newNode(kValue, iOrder); 
    }
    //if the value is less insert to the left
    if (kValue < node->keyValue)
    {
        //std::cout << "Left Insertion Move" << std::endl; 
        node->leftChild = insert(node->leftChild, kValue, iOrder); 
    }
    else if(kValue > node->keyValue)//if the value is more insert to the right
    {
        //std::cout << "Right Insertion Move" << std::endl; 
        node->rightChild = insert(node->rightChild, kValue, iOrder); 
    }
    else //kValue == node->keyValue , rejected by all bst no equal nodes
    {
        std::cout << "Node == kValue || rejected" << std::endl; 
        return node; 
    }

    //must update the height of the node
    node->nodeHeight = 1 + maxValue(getNodeHeight(node->leftChild), getNodeHeight(node->rightChild)); 
    //a nodes height is determined by the longest path down so we must add 1 + the max hieght of its subtrees

    int balance = treeBalance(node);//gets the balance 
    //std::cout << balance << std::endl;
    //adjustment cases 
    //if right is bigger than left, the balance is negative
    //if left is bigger than right, the balance is postive
    //we only adjust if the balance difference is greater than 1
    //we balance differently based off where the new node is inserted
    
    //cannot access node value before balance in the if statement so it must be second. 
    //There is a change that the child does not exist depending on the balance
    //doing it this way, it immediately breaks if the balance is wrong 
    //and it doesn't check the key value of a null ptr
    //could make a slightly more complex if statement so that the order doesn't matter, 
    //or do it like this and rely on the way that the compiler handels and statements
    //1. left left
    if (balance > 1 && kValue < node->leftChild->keyValue) // inserted to the left subtree's left subtree
    {
        std::cout << "Left Left" << std::endl; 
        //in order to do a left left rotation we only need to rotate right
        return rotateRight(node); 
    }
    //2. right right
    if (balance < -1 && kValue > node->rightChild->keyValue) // inserted into the right subtree's right subtree
    {
        std::cout << "Right Right" << std::endl; 
        //in order to do a Right Right rotation we only need to rotate left
        return rotateLeft(node); 
    }
    //3. left right 
    if (balance > 1 && kValue > node->leftChild->keyValue)
    {
        std::cout << "Left Right" << std::endl; 
        //we must rotate the nodes left child left first and then set the nodes left child to the result
        node->leftChild = rotateLeft(node->leftChild); 
        return rotateRight(node); 
    }    
    //4. right left
    if(balance < -1 && kValue < node->rightChild->keyValue)
    {
        std::cout << "Right Left" << std::endl; 
        node->rightChild = rotateRight(node->rightChild); 
        //we must rotate the nodes right child to the right and set the nodes right child to the result
        return rotateLeft(node); 
    }
    std::cout << "No Changes, End of Insertion Call" << std::endl; 
    return node; //no changes needed to be made
}
void inorderTraversal(AVLNode* treeRoot)
{
    if(treeRoot != NULL)
    {
        inorderTraversal(treeRoot->leftChild); 
        std::cout << treeRoot->keyValue << " and " << treeRoot->insertionOrder << std::endl; 
        inorderTraversal(treeRoot->rightChild); 
    }
}
void preorderTraversal(AVLNode* treeRoot)
{
    if(treeRoot != NULL)
    {
        std::cout << treeRoot->keyValue << " and " << treeRoot->insertionOrder << std::endl; 
        preorderTraversal(treeRoot->leftChild); 
        preorderTraversal(treeRoot->rightChild); 
    }
}