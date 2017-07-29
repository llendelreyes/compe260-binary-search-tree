//
//  main.cpp
//  Program #5
//
//  Created by Llendel Reyes on 4/23/17.
//  Copyright © 2017 Llendel Reyes. All rights reserved.
//

#include <iostream>
using namespace std;

#include "BST.h"
#include "TreeNode.h"

int main()
{
    
    BST intBST;
    cout << "Constructing empty Binary Search Tree\n";
    cout << "Binary Search Tree " << (intBST.empty() ? "is" : "is not") << " empty\n";
    
    
    cout << "Inorder Traversal of Binary Search Tree: ";
    intBST.inorder(cout);
    cout << endl;
    
    
    cout << "Preorder Traversal of Binary Search Tree: ";
    intBST.preorder(cout);
    cout << endl;
    
    
    cout << "Postorder Traversal of Binary Search Tree: ";
    intBST.postorder(cout);
    cout << endl;
    
    
    cout << "\nNow insert several values to be placed into Binary Search Tree."
    "\n Include both numbers in and out of the Binary Search Tree: \n";
    int number;
    for (;;)
    {
        cout << "Insert value (000 to stop): ";
        cin >> number;
        if (number == 000) break;
        intBST.insert(number);
    }
    
    cout << endl << "Binary Search Tree " << (intBST.empty() ? "is" : "is not") << " empty" << endl;
    cout << "Inorder Traversal of Binary Search Tree: ";
    intBST.inorder(cout);
    cout << endl;
    
    cout << "Preorder Traversal of Binary Search Tree: ";
    intBST.preorder(cout);
    cout << endl;
    
    cout << "Postorder Traversal of Binary Search Tree: ";
    intBST.postorder(cout);
    cout << endl;
    
    
    cout << "\n\n Testing search() operation."
    "\n Include both numbers in and out of Binary Search Tree:\n";
    for (;;)
    {
        cout << "Value to look for (000 to stop): ";
        cin >> number;
        if (number == 000) break;
        cout << (intBST.search(number) ? "Found" : "Not found") << endl;
    }
    
        cout << "\nNow testing the remove() operation."
    "\nTry both items in the BST and some not in it:\n";
    for (;;)
    {
        cout << "Value to remove (000 to stop): ";
        cin >> number;
        if (number == 000) break;
        intBST.remove(number);
    }
    cout << endl << "Inorder Traversal of Binary Search Tree: ";
    intBST.inorder(cout);
    cout << endl;
    
    cout << "Preorder Traversal of Binary Search Tree: ";
    intBST.preorder(cout);
    cout << endl;
    
    cout << "Postorder Traversal of Binary Search Tree: ";
    intBST.postorder(cout);
    cout << endl;
}
