#pragma once
#include "LinearLinkedListNode.h"

#ifndef __GENERAL_TREENODE
typedef struct GeneralTreeNode
{
	void* data;
	LinearLinkedListNode* nextsChildsManager;
}GeneralTreeNode;
#define __GENERAL_TREENODE
#endif // !__GENERAL_TREENODE

//Init the tree
void MakeGenralTree(GeneralTreeNode** , void*);
//Creats leaf number i
void SetLeafI(GeneralTreeNode*, void*);
//Cheacks if givven node is a leaf(dont have childs)
BOOL IsLeafGeneralTreeNode(GeneralTreeNode*);
//Recursive methoods that retruns the amount of nodes in whole tree
int HowManyNodesGeneralTreeNode(GeneralTreeNode*);
//Recursive methoods that retruns the amount of leafs in whole tree
int howManyLeafsGeneralTreeNode(GeneralTreeNode*);
//Recursive method to find node with givven val
GeneralTreeNode* FindNodeGeneralTreeNode(GeneralTreeNode*, void*, BOOL(*isEql)(void*));
