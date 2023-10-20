#include "GeneralTree.h"

void MakeGenralTree(GeneralTreeNode** root, void* val)
{
	*root = (GeneralTreeNode*)malloc(sizeof(GeneralTreeNode));
	(*root)->data = val;
	(*root)->nextsChildsManager = NULL;
}

void SetLeafI(GeneralTreeNode* node, void* value)
{
	GeneralTreeNode* new = (GeneralTreeNode*)malloc(sizeof(GeneralTreeNode));
	new->data = value;
	new->nextsChildsManager = NULL;
	PushLinearLinkedListNode(&node->nextsChildsManager, new);
}

BOOL IsLeafGeneralTreeNode(GeneralTreeNode* node)
{
	return !node->nextsChildsManager;
}

int HowManyNodesGeneralTreeNode(GeneralTreeNode* node)
{
	if (!node)
		return 0;
	int sum = 0;
	LinearLinkedListNode* prog = node->nextsChildsManager;

	while (prog)
	{
		sum += howManyNodesGeneralTreeNode(prog->data) + 1;
		prog = prog->next;
	}
	return sum;
}

int howManyLeafsGeneralTreeNode(GeneralTreeNode* node)
{
	if (!node)
		return 0;
	int sum = 0;
	LinearLinkedListNode* prog = node->nextsChildsManager;

	while (prog)
	{
		sum += howManyLeafsGeneralTreeNode(prog->data) + isLeafGeneralTreeNode(prog);
		prog = prog->next;
	}
	return sum;
}

GeneralTreeNode* FindNodeGeneralTreeNode(GeneralTreeNode* node,void* data,BOOL(*isEql)(void*,void*))
{
	if (!node)
		return NULL;
	if ((*isEql)(node->data,data))
		return node;
	LinearLinkedListNode* prog = node->nextsChildsManager;
	while (prog)
	{
		FindNodeGeneralTreeNode(prog->data,data,(*isEql));
		prog = prog->next;
	}
}
