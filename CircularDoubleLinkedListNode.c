#include "CircularDoubleLinkedListNode.h"

void InitManager(void** manger)
{
	*manger = NULL;
}

void InsertLastCDLLNode(CDLLNode** manger, TYPE value)
{
	CDLLNode* newCdll = (CDLLNode*)malloc(sizeof(CDLLNode));
	newCdll->info = value;
	newCdll->next = newCdll;
	newCdll->prev = newCdll;
	*manger = newCdll;
}

void DeleteLastCDLLNode(CDLLNode** manger)
{
	free(manger);
	manger = NULL;
}

void InsertEndCDLLNode(CDLLNode** Manger, TYPE value)
{
	CDLLNode* newCdll = (CDLLNode*)(malloc(sizeof(CDLLNode)));
	newCdll->info = value;
	newCdll->next = (*Manger)->next;
	newCdll->prev = *Manger;
	((CDLLNode*)(*Manger)->next)->prev = newCdll;
	(*Manger)->next = newCdll;
	(*Manger) = newCdll;
}

void DeleteEndCDLL(CDLLNode** manger)
{
	CDLLNode* mancgerCopy = *manger;
	((CDLLNode*)(*manger)->prev)->next = mancgerCopy->next;
	*manger = (CDLLNode*)(*manger)->prev;
	((CDLLNode*)(*manger)->next)->prev = *manger;
	free(mancgerCopy);

}
void InsertNextCDLL(CDLLNode* node, TYPE value)
{
	CDLLNode* newCdll = (CDLLNode*)malloc(sizeof(CDLLNode));
	newCdll->info = value;
	newCdll->prev = node;
	newCdll->next = node->next;
	node->next;
}

void InertPrevCDLL(CDLLNode* node, TYPE value)
{
	CDLLNode* newCdll = (CDLLNode*)malloc(sizeof(CDLLNode));
	newCdll->info = value;
	newCdll->prev = node->prev;
	newCdll->next = node;
	node->prev = newCdll;
}

void DeleteCDLL(CDLLNode** node)
{
	CDLLNode* temp = node;
	((CDLLNode*)(*node)->prev)->next = (*node)->next;
	((CDLLNode*)(*node)->next)->prev = (*node)->prev;
	(*node) = (*node)->prev;
	free(temp);
}