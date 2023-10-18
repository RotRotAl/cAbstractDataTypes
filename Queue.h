#pragma once
#include "LinearLinkedListNode.h"

#ifndef __QUEUE
#define Queue LLLNode
#define __QUEUE
#endif // !__QUEUE

//Init the q for first used and pushes the first value
void InitQueue(Queue**, void*);
//Retruns true if the queue empaty
BOOL IsQueueEmpty(Queue*);
//Insert one value into q
void InsertQueue(Queue**, void*);
//Remove the value that got into queue first
void* RemoveQueue(Queue**);
//Get queue len
short QueueLen(Queue*);