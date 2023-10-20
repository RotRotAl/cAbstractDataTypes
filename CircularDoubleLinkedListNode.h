#pragma once
#include <stdlib.h>
#ifndef TYPE
#define TYPE int 
#endif // !TYPE

#ifndef __DLL
#define __DLL
typedef struct CircularDoubleLinkedListNode
{
	TYPE info;
	void* next;
	void* prev;
}CircularDoubleLinkedListNode, CDLLNode;
#endif // !__DLL
#ifndef __CDLL
#define __CDLL
typedef CircularDoubleLinkedListNode CDLLNode;
#endif // !__CDLL

//Initing any kind of manger
void InitManager(void**);
//Inserting the first node into the last place(Manger)(n=0)
void InsertLastCDLLNode(CDLLNode**, TYPE);
//Removing the last Node(n=1)
void DeleteLastCDLLNode(CDLLNode**);
//Insertig into the manger (n>1)
void InsertEndCDLLNode(CDLLNode**, TYPE);
//Delete the current manger (n>1)
void DeleteEndCDLLNode(CDLLNode**);
//Inert a node after the given node(if its not the manger)(n>1)
void InsertNextCDLLNode(CDLLNode*, TYPE);
//Inert a node Before the given node(n>1)
void InertPrevCDLLNode(CDLLNode*, TYPE);
//Delete given node(n>=1)(not the manger)
void DeleteCDLLNode(CDLLNode**);