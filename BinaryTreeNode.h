#pragma once
#include "MathLibrary.h"
#include <stdlib.h>

#ifndef __BinaryTreeNode
#define __BinaryTreeNode
typedef struct BinaryTreeNode
{
	void* data;
	struct BinaryTreeNode* right;
	struct BinaryTreeNode* left;
}BinaryTreeNode;
#endif // !__BinaryTreeNode

//Init the root of binary tree node
void MakeBinaryTree(BinaryTreeNode**, void*);
//Creates right node
void SetRightBinaryTree(BinaryTreeNode*, void*);
//Creates left node
void SetLeftBinaryTreeNode(BinaryTreeNode*, void*);
//Retruns true if givven node leaf(no childs)
BOOL IsLeafBinaryTreeNode(BinaryTreeNode*);
//Recursive method that counts amount of nodes in tree
int HowManyNodesBinaryTreeNode(BinaryTreeNode*);
//Recursive method that counts amount of leaf nodes in tree
int HowManyLeafsBinaryTreeNode(BinaryTreeNode*);
//Recursive method that returns the node with givven value
BinaryTreeNode* FindNode(BinaryTreeNode*, void*);
// Returns tree height
int FindHeight(BinaryTreeNode*);