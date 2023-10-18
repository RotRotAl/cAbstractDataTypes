#include "Queue.h"

void InitQueue(Queue** manager,void* data) {
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->next = newNode;
	newNode->data = data;
	*manager = newNode;
}

BOOL IsQueueEmpty(Queue* manager) {
	return !manager;
}

void InsertQueue(Queue** manager, void* data) {
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->next = (*manager)->next;
	newNode->data = data;
	(*manager)->next = newNode;
	*manager = newNode;
}

void* RemoveQueue(Queue** manager) {
    void* res = NULL;
    if (*manager) {
        Queue* process = (*manager)->next;
        Queue* temp = *manager;

        if (process != *manager) { 
            while (process->next != *manager)
                process = process->next;
            res = process->next->data;
            process->next = temp->next;
        }
        else {
            res = process->data;
            *manager = NULL;
        }

        free(temp);
    }
    return res;
}

short QueueLen(Queue* manager) {
    short count=0;
    if (manager != NULL) {
        Queue* process = manager->next;
        count = 1;
        while (process != manager)
        {
            process = process->next;
            count++;
        }
    }
    return count;
}