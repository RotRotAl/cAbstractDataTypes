#include "DoubleLinearLinkedListNode.h"


void PushDLLNode(DLLNode** manager, void* value)
{
	DLLNode* newCdll = (DLLNode*)malloc(sizeof(DLLNode));
	newCdll->data = value;
	newCdll->next = *manager;
	newCdll->previous = NULL;
	if (*manager)
		(*manager)->previous = newCdll;
	*manager = newCdll;
}

void DeleteLastDLLNode(DLLNode** manager)
{
	free(manager);
	manager = NULL;
}


void InsertNextDLLNode(DLLNode* node, void* value)
{
	DLLNode* newCdll = (DLLNode*)malloc(sizeof(DLLNode));
	newCdll->data = value;
	newCdll->previous = node;
	newCdll->next = node->next;
	node->next = newCdll;
}

void InertPrevDLLNode(DLLNode* node, void* value)
{
	DLLNode* newCdll = (DLLNode*)malloc(sizeof(DLLNode));
	newCdll->data = value;
	newCdll->previous = node->previous;
	newCdll->next = node;
	node->previous = newCdll;
}


void DeleteDLLNode(DLLNode** node)
{
	DLLNode* temp = node;
	if (temp)
	{
		if (temp->previous)
			((DLLNode*)temp->previous)->next = (*node)->next;
		if (temp->next)
			((DLLNode*)temp->next)->previous = (*node)->previous;
		(*node) = (*node)->previous;
		free(temp);
	}
}

short LengthDLLNode(DLLNode* manager) {
	short count = 0;
	if (manager) {
		while (manager)
		{
			count++;
			manager = manager->next;
		}
	}
	return count;
}