#pragma once
#include "stringlibary.h"
#include "LinearLinkedListNode.h"
#ifndef __Vertic
#define __Vertic
typedef struct {
	void* value;
}Vertic;
#endif // !__Vertic
#ifndef __GRAPH
#define __GRAPH
typedef struct
{
	int V;
	int** ArcMat;
	Vertic* Vertices;
} Graph;
#endif // !__GRAPH

//join arc between two vertices
void JoinArc(Graph* g, Vertic a, Vertic b);
//join arc with wight between two vertices
void JoinWightArc(Graph* g, Vertic a, Vertic b, int wight);
//remove arc between two vertices
void RemoveArc(Graph* g, Vertic a, Vertic b);
// retrun true if A as an arc for B
BOOL IsAdjacent(Graph* g, Vertic a, Vertic b);
//retrun all the adjacent of a certin vertic
LinearLinkedListNode* GetAllAdjacent(Graph* g, Vertic a);
