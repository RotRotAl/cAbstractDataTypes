#include "Stack.h"

void InitStack(Stack* manager,int totalSize) {
	((manager)->topOfStack) = 0;
	manager->content = malloc(totalSize);
	manager->totalSize = totalSize;
}

void* PopStack(Stack* manager)
{
	return (manager->content)[--(manager->topOfStack)];
}

void PushStack(Stack* manager, void* item)
{
	(*manager).content[(*manager).topOfStack++] = item;
}

BOOL IsEmptyStack(Stack* manager) {
	return ((manager)->topOfStack) == 0;
}

void StackReverse(Stack* manager) {
	Stack temp;
	Stack temp1;
	BOOL shouldcont = !IsEmptyStack(manager);
	InitStack(&temp,manager->totalSize);
	InitStack(&temp1, manager->totalSize);
	while (shouldcont)
	{
		PushStack(&temp, PopStack(manager));
		shouldcont = !IsEmptyStack(manager);
	}
	shouldcont = !IsEmptyStack(&temp);
	while (shouldcont)
	{
		PushStack(&temp1, PopStack(&temp));
		shouldcont = !IsEmptyStack(&temp);
	}
	shouldcont = !IsEmptyStack(&temp1);
	while (shouldcont)
	{
		PushStack(manager, PopStack(&temp1));
		shouldcont = !IsEmptyStack(&temp1);
	}
}

void CopyStack(Stack* manager, Stack* res) {
	return memcpy(res, manager, manager->totalSize);
}

BOOL IsInStack(Stack manager, void* val, BOOL(*isEql)(void*, void*)) {
	BOOL Found = FALSE;
	BOOL shouldcont = !IsEmptyStack(&manager);
	while (shouldcont)
	{
		Found =(*isEql)( PopStack(&manager) , val);
		shouldcont = !IsEmptyStack(&manager) && !Found;
	}
	return Found;
}

int StackLength(Stack* manager) {
	return manager->topOfStack;
}

void EmpatyStack(Stack* manager) {
	manager->topOfStack = 0;
}

BOOL IsEqualStack(Stack s1, Stack s2, BOOL(*isEql)(void*, void*))
{
	if (StackLength(&s1) == StackLength(&s2))
		while ((*isEql)(PopStack(&s1), PopStack(&s2)));
	return s1.topOfStack <= -1;
}
