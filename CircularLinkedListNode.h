#pragma once
#include "Queue.h"

#ifndef __CIRCULAR_LINKED_LIST_NODE
#define CircularLinkedListNode Queue
#define CLLNode Queue
#define __CIRCULAR_LINKED_LIST_NODE
#endif // !__CIRCULAR_LINKED_LIST_NODE

//Insert node after givven node
//should be used when CLL len>2
void CLLLNodeAfterInsert(CLLNode*, void*);
//Delete node after givven node
//should be used when CLL len>2
void CLLLNodeAfterDelete(CLLNode*);
//Delete last node
void CLLLNodeEndDelete(CLLNode**);
//Insert node to end of givven list
//should be used when CLL len>0
void CLLLNodeEndInsert(CLLNode** , void* );
//Adds node
//Should be used only to insert to crate first
void CLLLNodePush(CLLNode**, void*);
//Removes the last node
//shoud be used only when there is only one node
void CLLLNodePop(CLLNode**);
//prints the CLLNode
short CLLLNodeLen(CLLNode**);
//retruns true if empty
void IsCLLLNodeEmpty(CLLNode**);