#pragma once
#include "MathLibrary.h"
#include "LinearLinkedListNode.h"
#ifndef __Vertic
#define __Vertic
typedef struct {
	int offsetInArr;
	void* value;
}Vertic;
#endif // !__Vertic
#ifndef __GRAPH
#define __GRAPH
typedef struct
{
	int V;
	int** ArcMat;
	Vertic** Vertices;
} Graph;
#endif // !__GRAPH


//Init graph
void InitGraph(Graph**,void**, int);
//join arc between two vertices
void JoinArc(Graph* , Vertic* , Vertic* );
//join arc with weight between two vertices
void JoinWeightArc(Graph* , Vertic* , Vertic* , int );
//remove arc between two vertices
void RemoveArc(Graph* , Vertic*, Vertic*);
// retrun true if A as an arc for B
BOOL IsAdjacent(Graph*, Vertic*, Vertic*);
//retrun all the adjacent of a certin vertic
LinearLinkedListNode* GetAllAdjacent(Graph* g, Vertic* a);
