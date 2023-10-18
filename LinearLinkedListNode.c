#include "LinearLinkedListNode.h"

void InitLinearLinkedListNode(LLLNode** manager) {
	*manager = NULL;
}

void PushLinearLinkedListNode(LLLNode** manager, void* data) {
	LLLNode* newNode = (LLLNode*)malloc(sizeof(LLLNode));
	newNode->data = data;
	newNode->next = *manager;
	*manager = newNode;
}

void* PopLinearLinkedListNode(LLLNode** manager) {
	LLLNode* tmp;
	void* resultPtr = NULL;
	if (manager) {
		tmp = *manager;
		resultPtr = ((*manager)->data);
		*manager = (*manager)->next;
		free(tmp);
	}
	return resultPtr;
}

void InsertLinearLinkedListNode(LLLNode* node, void* data) {
	LLLNode* newNode = (LLLNode*)malloc(sizeof(LLLNode));
	newNode->data = data;
	if (node) {
		newNode->next = node->next;
		node->next = newNode;
	}
	else
	{
		free(newNode);
	}
}

void* RemoveLinearLinkedListNode(LLLNode* node) {
	LLLNode* tmp;
	void* result = NULL;
	if (node) {
		tmp = node->next;
		if (tmp->next) {
			result = tmp->data;
			node->next = node->next->next;
			free(tmp);
		}
	}
	return result;
}

void PrintsLinearLinkedListNode(LLLNode* node,char* (*toString)(void*)) {
	LLLNode* temp = node;
	while (temp)
	{
		printf("%s",(*toString)(temp->data));
		temp = temp->next;
	}
	puts("");
}