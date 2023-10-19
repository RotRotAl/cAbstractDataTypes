#pragma once
#include <stdlib.h>
#include "MathLibrary.h"

#ifndef __DOUBLE_LINEAR_LINKED_LIST_NODE
typedef struct dlllN {
	void* data;
	struct dlllN* next;
	struct dlllN* previous;
}DoubleLinearLinkedListNode, DLLNode;
#define __DOUBLE_LINEAR_LINKED_LIST_NODE
#endif // !__DOUBLE_LINEAR_LINKED_LIST_NODE

//Inserting the first node into the last place(manager)(list len=0)(inits)
void PushDLLNode(DLLNode**, void*);
//Deleting the last Node(list len=1)
void DeleteLastDLLNode(DLLNode**);
//Inert a node after the given node(if its not the manager)(list len>1)
void InsertNextDLLNode(DLLNode*, void*);
//Inert a node Before the given node(list len>1)
void InertPrevDLLNode(DLLNode*, void*);
//Deleting given node(list len>0)(not the manager)
void DeleteDLLNode(DLLNode**);
//Deleting given node(list len>0)(not the manager)
void LengthDLLNode(DLLNode**);