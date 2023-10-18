#include "CircularLinkedListNode.h"

void CLLLNodePush(CLLNode** manager, void* data) {
	InitQueue(manager, data);
}

short CLLLNodeLen(CLLNode** manager) {
	return QueueLen(manager);
}

void CLLLNodeEndDelete(CLLNode** manager) {
	RemoveQueue(manager);
}

void CLLLNodeEndInsert(CLLNode** manager, void* data) {
	InsertQueue(manager, data);
}

void CLLLNodeAfterInsert(CLLNode* manager, void* data) {
	CLLNode* newCLL = (CLLNode*)malloc(sizeof(CLLNode));
	newCLL->next = manager->next;
	newCLL->data = data;
	manager->next = newCLL;
}

void CLLLNodeAfterDelete(CLLNode* manger) {
	CLLNode* temp = manger->next;
	manger->next = temp->next;
	free(temp);
}

void CLLLNodePop(CLLNode** manager) {
	free(*manager);
	*manager = NULL;
}

void IsCLLLNodeEmpty(CLLNode** manager) {
	IsQueueEmpty(manager);
}