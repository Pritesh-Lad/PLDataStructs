//
//  PLBTreeUtil.hpp
//  PLDataStructs
//
//  Created by Pritesh on 01/10/20.
//  Copyright © 2020 pritesh. All rights reserved.
//

#ifndef PLBTreeUtil_h
#define PLBTreeUtil_h

class PLBTreeNode;

int max(int a, int b);
int heightOfNode(PLBTreeNode *tree);
int getBalance(PLBTreeNode *node);
PLBTreeNode * getInorderSuccessor(PLBTreeNode *tree);
void printInOrderTraversal(PLBTreeNode *tree);
void printPreOrderTraversal(PLBTreeNode *tree);
void printPostOrderTraversal(PLBTreeNode *tree);

#endif /* PLBTreeUtil_h */
