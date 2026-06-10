
// COS30008, Tutorial 12, 2026

#include <iostream>

#include "BTree.h"
#include "Visitors.h"

#define P1
#define P2

#if defined(P1)

void testP1()
{
    std::cout << "Test BTree functionality."  << std::endl;
    
    using BSTree = BTree<size_t>;
    using BSTreeNode = typename BSTree::node;

    BSTreeNode n25 = BSTree::makeNode(25);
    BSTreeNode n10 = BSTree::makeNode(10);
    BSTreeNode n15 = BSTree::makeNode(15);
    BSTreeNode n37 = BSTree::makeNode(37);
    BSTreeNode n30 = BSTree::makeNode(30);
    BSTreeNode n65 = BSTree::makeNode(65);

    n37->attachLeft(n30);
    n37->attachRight(n65);
    n10->attachRight(n15);
    n25->attachLeft(n10);
    n25->attachRight(n37);

    std::cout << "Height of n25: " << n25->height() << std::endl;
    std::cout << "Min of n25: " << n25->findMin() << std::endl;
    std::cout << "Max of n25: " << n25->findMax() << std::endl;

    std::cout << "Max of left of n25: " << n25->left().findMax() << std::endl;
    std::cout << "Min of right of n25: " << n25->right().findMin() << std::endl;

    const BSTreeNode& aBTree = n25;
    
    
    std::cout << "Pre-Order Traversal: ";
    
    aBTree->doDepthFirstSearch(PreOrderVisitor<size_t>());
    
    std::cout << std::endl;

    std::cout << "In-Order Traversal: ";
    
    aBTree->doDepthFirstSearch(InOrderVisitor<size_t>());
    
    std::cout << std::endl;
    
    std::cout << "Post-Order Traversal: ";
    
    aBTree->doDepthFirstSearch(PostOrderVisitor<size_t>());
    
    std::cout << std::endl;
    
    std::cout << "Test BTree functionality complete."  << std::endl;
}

#endif

#if defined(P2)

#include "TreeDecorator.h"

void testP2()
{
    std::cout << "Test TreeDecorator functionality."  << std::endl;
    
    using BSTree = BTree<size_t>;
    using BSTreeNode = typename BSTree::node;

    BSTreeNode n25 = BSTree::makeNode(25);
    BSTreeNode n10 = BSTree::makeNode(10);
    BSTreeNode n15 = BSTree::makeNode(15);
    BSTreeNode n37 = BSTree::makeNode(37);
    BSTreeNode n30 = BSTree::makeNode(30);
    BSTreeNode n65 = BSTree::makeNode(65);

    n37->attachLeft(n30);
    n37->attachRight(n65);
    n10->attachRight(n15);
    n25->attachLeft(n10);
    n25->attachRight(n37);

    const BSTreeNode& aBTree = n25;
    
    aBTree->doDepthFirstSearch(TreeDecorator<size_t>());
    
    std::cout << std::endl;
    
    std::cout << "Test TreeDecorator functionality complete."  << std::endl;
}

#endif


int main()
{
#if defined(P1)

    testP1();
    
#endif

#if defined(P2)
    
    testP2();
    
#endif

    return 0;
}
