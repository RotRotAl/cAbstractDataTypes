#include "BinaryTreeNode.h"

BinaryTreeNode* FindNode(BinaryTreeNode* bt, void* val)
{
	if (!bt)
		return NULL;
	if (bt->data = val)
		return bt;
	return findNode(bt->right, val) + ((long)findNode(bt->left, val));
}

int FindHeight(BinaryTreeNode* bt)
{
	if (!bt)
		return -1;
	return MAX(findHeight(bt->right), findHeight(bt->right)) + 1;
}

int HowManyLeafsBinaryTreeNode(BinaryTreeNode* node)
{
	if (!node)
		return 0;
	return HowManyLeafsBinaryTreeNode(node->left) +
		HowManyLeafsBinaryTreeNode(node->right) + IsLeafBinaryTreeNode(node);
}

int HowManyNodesBinaryTreeNode(BinaryTreeNode* node)
{
	if (!node)
		return 0;
	return HowManyNodesBinaryTreeNode(node->left) +
		HowManyNodesBinaryTreeNode(node->right) + 1;
}

BOOL IsLeafBinaryTreeNode(BinaryTreeNode* node)
{
	return !node->left && !node->right;
}

void SetRightBinaryTree(BinaryTreeNode* node, void* value)
{
	node->right = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	node->right->data = value;
	node->right->left = NULL;
	node->right->right = NULL;
}

void SetLeftBinaryTreeNode(BinaryTreeNode* node, void* value)
{
	node->left = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	node->left->data = value;
	node->left->left = NULL;
	node->left->right = NULL;
}

void MakeBinaryTree(BinaryTreeNode** root, void* val)
{
	*root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	(*root)->data = val;
	(*root)->left = NULL;
	(*root)->right = NULL;
}