//
//  TreeNode.h
//  Program #5
//
//  Created by Llendel Reyes on 4/23/17.
//  Copyright © 2017 Llendel Reyes. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h


class TreeNode {
    friend class BST;
public:
    TreeNode();  //default constructor
    TreeNode(int node, TreeNode* Left = 0, TreeNode* Right = 0) : nodeValue(node), left(Left), right(Right){};
    int getnodeValue () const; // accessor function
    
private:
    int nodeValue;
    TreeNode *left;
    TreeNode *right;
    
};

TreeNode::TreeNode()
{
    left = right = NULL;
}

int TreeNode::getnodeValue() const
{ return nodeValue;}

#endif /* TreeNode_h */
