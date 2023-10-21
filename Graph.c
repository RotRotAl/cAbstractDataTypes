#include "graph.h"

void JoinArc(Graph* g, Vertic* a, Vertic* b){
	JoinWeightArc(g, a, b, 1);
}

void JoinWeightArc(Graph* g, Vertic* a, Vertic* b, int weight){
	int aOffset = a->offsetInArr;
	int bOffset = b->offsetInArr;
	g->ArcMat[aOffset][bOffset] = weight;

}

void RemoveArc(Graph* g, Vertic* a, Vertic* b){
	JoinWeightArc(g, a, b, -1);
}

BOOL IsAdjacent(Graph* g, Vertic* a, Vertic* b){
	int aOffset = a->offsetInArr;
	int bOffset = b->offsetInArr;
	return g->ArcMat[aOffset][bOffset];
}

LinearLinkedListNode* GetAllAdjacent(Graph* g, Vertic* a){
	int aOffset = a->offsetInArr;
	int counter;
	LinearLinkedListNode* manger = NULL;
	for (counter = 0; counter < g->V; counter++)
	{
		if (g->ArcMat[aOffset][counter]>-1)
			PushLinearLinkedListNode(&manger, &g->Vertices[counter]);
	}
	return manger;
}

void InitGraph(Graph** graph,void** data, int v) {
	int count = 0;
	graph = (Graph*) malloc(sizeof(Graph*));
	(*graph)->V = v;
	(*graph)->Vertices = malloc(sizeof(Vertic*) * v);
	for (; count < v; count++)
	{
		(*graph)->Vertices[count]->value = data[count];
		(*graph)->Vertices[count]->offsetInArr = count;
	}
}