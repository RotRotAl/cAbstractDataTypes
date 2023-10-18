#pragma once
#include "MathLibrary.h";
#include <stdlib.h>
#include <string.h>

#ifndef __STACK
typedef struct
{
	int totalSize;
	int topOfStack;
	void** content;
}Stack;
#define __STACK
#endif // !__STACK

//init the stack manager ptr
void InitStack(Stack*,int);
//retruninig and remoaving last inserted value
void* PopStack(Stack*);
//inserting value to last place
void PushStack(Stack*, void*);
//retruninig true if stack is empty
BOOL IsEmptyStack(Stack*);
//makes the stack up side down
void StackReverse(Stack*);
//copys all val in stack to a new one
void CopyStack(Stack*, Stack*);
//retruns true if giving val in stack
//requires a content compring method
BOOL IsInStack(Stack, void*, BOOL(*isEql)(void*, void*));
//return stack length
int StackLength(Stack*);
//empty all vals in stack
void EmpatyStack(Stack*);
//retruns true if equal
//requires a content compring method
BOOL IsEqualStack(Stack, Stack, BOOL (*isEql)(void*,void*));
