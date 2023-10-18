#pragma once
#include <stdlib.h>
#include "MathLibrary.h"
#include <stdio.h>

#ifndef __LINEAR_LINKED_LIST_NODE
typedef struct lllN {
	void* data;
	struct lllN* next;
}LinearLinkedListNode,LLLNode;
#define __LINEAR_LINKED_LIST_NODE
#endif // !__LINEAR_LINKED_LIST_NODE

//Inits the manager
void InitLinearLinkedListNode(LLLNode**);
//Pushes (insert) a node into list first place
void PushLinearLinkedListNode(LLLNode**, void*);
//Pops node from list (retruninig and remoaving first value)
void* PopLinearLinkedListNode(LLLNode**);
//Insert after the givven node (the passed LinearLinkedListNode 
//can be manager but not required to be)
void InsertLinearLinkedListNode(LLLNode*, void*);
//Removes the node  after the givven node (the passed LinearLinkedListNode 
//can be manager but not required to be)
void* RemoveLinearLinkedListNode(LLLNode*);
//Ptints givven list
void PrintsLinearLinkedListNode(LLLNode*,char*(*toString)(void*));