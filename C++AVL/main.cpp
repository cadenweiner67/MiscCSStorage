#include "AVLTree.h"
int main(void)
{
    AVLNode * treeRoot = NULL; 
    std::cout << "Starting" << std::endl; 
    treeRoot = insert(treeRoot, 10, "First"); 
    treeRoot = insert(treeRoot, 20, "Second");
    treeRoot = insert(treeRoot, 30, "Third");  
    treeRoot = insert(treeRoot, 40, "Fourth");
    treeRoot = insert(treeRoot, 50, "Fifth");  
    treeRoot = insert(treeRoot, 60, "Sixth");
    treeRoot = insert(treeRoot, 70, "Seventh");
    inorderTraversal(treeRoot); 
    preorderTraversal(treeRoot); 
    //first test just numbers in order, would be O(N) in a regular BST

    //Testing Left Left Rotation
    AVLNode * treeRootLL = NULL; 
    std::cout << "Starting Left Left" << std::endl; 
    treeRootLL = insert(treeRootLL, 50, "First"); 
    treeRootLL = insert(treeRootLL, 40, "Second");
    treeRootLL = insert(treeRootLL, 60, "Third");  
    treeRootLL = insert(treeRootLL, 30, "Fourth");
    treeRootLL = insert(treeRootLL, 50, "Fifth");  
    treeRootLL = insert(treeRootLL, 45, "Sixth");
    treeRootLL = insert(treeRootLL, 35, "Seventh");
    inorderTraversal(treeRootLL); 
    preorderTraversal(treeRootLL); 

    //Testing Left Right Rotation
    AVLNode * treeRootLR = NULL; 
    std::cout << "Starting Left Right" << std::endl; 
    treeRootLR = insert(treeRootLR, 50, "First"); 
    treeRootLR = insert(treeRootLR, 70, "Second");
    treeRootLR = insert(treeRootLR, 40, "Third");  
    treeRootLR = insert(treeRootLR, 35, "Fourth");
    treeRootLR = insert(treeRootLR, 45, "Fifth");  
    treeRootLR = insert(treeRootLR, 47, "Sixth");
    inorderTraversal(treeRootLR); 
    preorderTraversal(treeRootLR); 

    //Testing Right Left Rotation
    AVLNode * treeRootRL = NULL; 
    std::cout << "Starting Right Left" << std::endl; 
    treeRootRL = insert(treeRootRL, 50, "First"); 
    treeRootRL = insert(treeRootRL, 40, "Second");
    treeRootRL = insert(treeRootRL, 70, "Third");  
    treeRootRL = insert(treeRootRL, 60, "Fourth");
    treeRootRL = insert(treeRootRL, 75, "Fifth");  
    treeRootRL = insert(treeRootRL, 65, "Sixth");
    inorderTraversal(treeRootRL); 
    preorderTraversal(treeRootRL); 

    //Testing Right Right Rotation
    AVLNode * treeRootRR = NULL; 
    std::cout << "Starting Right Right" << std::endl; 
    treeRootRR = insert(treeRootRR, 50, "First"); 
    treeRootRR = insert(treeRootRR, 10, "Second");
    treeRootRR = insert(treeRootRR, 60, "Third");  
    treeRootRR = insert(treeRootRR, 55, "Fourth");
    treeRootRR = insert(treeRootRR, 70, "Fifth");  
    treeRootRR = insert(treeRootRR, 65, "Sixth");
    treeRootRR = insert(treeRootRR, 75, "Seventh");
    inorderTraversal(treeRootRR); 
    preorderTraversal(treeRootRR); 




    return 0; 
}