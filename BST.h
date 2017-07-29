//
//  BST.h
//  Program #5
//
//  Created by Llendel Reyes on 4/23/17.
//  Copyright © 2017 Llendel Reyes. All rights reserved.
//
#include <iostream>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "TreeNode.h"

class BST
{
public:
    
    BST();
    
    bool empty() const;
    
    bool search(const int & item) const;
    
    void insert(const int & item);
    
    void remove(const int & item);
    
    void inorder(std::ostream & out) const;
    
    void preorder(std::ostream & out) const;
    
    void postorder(std::ostream & out) const;
    
private:
    
    typedef TreeNode * BinNodePointer;
    
    void search2(const int & item, bool & found,
    BinNodePointer & locateptr, BinNodePointer & parentNode) const;
    
    void inorderTrav(std::ostream & out, BST::BinNodePointer subtreePtr) const;
    
    void preorderTrav(std::ostream & out, BST::BinNodePointer subtreePtr) const;
    
    
    void postorderTrav(std::ostream & out, BST::BinNodePointer subtreePtr) const;
    
    
    BinNodePointer rootNode;
    
};

inline BST::BST()
: rootNode(0)
{}

inline bool BST::empty() const
{ return rootNode == 0; }


bool BST::search(const int & item) const
{
    BST::BinNodePointer locateptr = rootNode;
    bool found = false;
    while (!found && locateptr != 0)
    {
        if (item < locateptr->nodeValue )
            locateptr = locateptr->left;
        else if (locateptr->nodeValue  < item)
            locateptr = locateptr->right;
        else
            found = true;
    }
    return found;
}


inline void BST::insert(const int & item)
{
    BST::BinNodePointer
    locateptr = rootNode,
    parentNode = 0;
    bool found = false;
    while (!found && locateptr != 0)
    {
        parentNode = locateptr;
        if (item < locateptr->nodeValue )
            locateptr = locateptr->left;
        else if (locateptr->nodeValue  < item)
            locateptr = locateptr->right;
        else
            found = true;
    }
    if (!found)
    {
        locateptr = new TreeNode(item);
        if (parentNode == 0)
            rootNode = locateptr;
        else if (item < parentNode->nodeValue  )
            parentNode->left = locateptr;
        else
            parentNode->right = locateptr;
    }
    else
        std::cout << "Item already in the tree\n";
}

void BST::remove(const int & item)
{
    bool found;
    BST::BinNodePointer
    x,
    parentNode;
    search2(item, found, x, parentNode);
    
    if (!found)
    {
        std::cout << "Item not in  Binary Tree\n";
        return;
    }
    //else
    if (x->left != 0 && x->right != 0)
    {
        
        BST::BinNodePointer xSucc = x->right;
        parentNode = x;
        while (xSucc->left != 0)
        {
            parentNode = xSucc;
            xSucc = xSucc->left;
        }
        
                x->nodeValue  = xSucc->nodeValue ;
        x = xSucc;
    }
        BST::BinNodePointer
    subtree = x->left;
    if (subtree == 0)
        subtree = x->right;
    if (parentNode == 0)
        rootNode = subtree;
    else if (parentNode->left == x)
        parentNode->left = subtree;
    else
        parentNode->right = subtree;
    delete x;
}

inline void BST::inorder(ostream & out) const
{
    inorderTrav(out, rootNode);
}


inline void BST::preorder(ostream & out) const
{
    preorderTrav (out, rootNode);
}


inline void BST::postorder(ostream & out) const
{
    postorderTrav(out, rootNode);
}


void BST::search2(const int & item, bool & found,
                  BST::BinNodePointer & locateptr,
                  BST::BinNodePointer & parentNode) const
{
    locateptr = rootNode;
    parentNode = 0;
    found = false;
    while (!found && locateptr != 0)
    {
        if (item < locateptr->nodeValue )
        {
            parentNode = locateptr;
            locateptr = locateptr->left;
        }
        else if (locateptr->nodeValue  < item)
        {
            parentNode = locateptr;
            locateptr = locateptr->right;
        }
        else
            found = true;
    }
}


void BST::inorderTrav(ostream & out,
                     BST::BinNodePointer subtreeNode) const
{
    if (subtreeNode != 0)
    {
        inorderTrav(out, subtreeNode->left);
        out << subtreeNode->nodeValue  << "  ";
        inorderTrav(out, subtreeNode->right);
    }
}

void BST::preorderTrav (ostream & out,
                      BST::BinNodePointer subtreeNode) const
{
    if (subtreeNode != 0)
    {
        out << subtreeNode->nodeValue  << "  ";
        preorderTrav (out, subtreeNode->left);
        preorderTrav (out, subtreeNode->right);
    }
}

void BST::postorderTrav(ostream & out,
                       BST::BinNodePointer subtreeNode) const
{
    if (subtreeNode != 0)
    {
        inorderTrav(out, subtreeNode->left);
        inorderTrav(out, subtreeNode->right);
        out << subtreeNode->nodeValue  << "  ";      
    }
}

#endif
