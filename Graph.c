#include "graph.h"

void JoinArc(Graph* g, Vertic* a, Vertic* b){
	JoinWeightArc(g, a, b, 1);
}

int OffsetOfVerticInArr(Vertic* val, Vertic arr[], int len){
	int counter;
	BOOL flag = 0;
	for (counter = 0; counter < len & !flag; counter++)
	{
		flag = val == &(arr[counter]);
	}
	return (flag) ? counter : -1;
}

void JoinWeightArc(Graph* g, Vertic* a, Vertic* b, int wight){
	int aOffset = OffsetOfVerticInArr(&a, g->Vertices, g->V);
	int bOffset = OffsetOfVerticInArr(&b, g->Vertices, g->V);
	g->ArcMat[aOffset][bOffset] = wight;

}

void RemoveArc(Graph* g, Vertic* a, Vertic* b){
	JoinWeightArc(g, a, b, -1);
}

BOOL IsAdjacent(Graph* g, Vertic* a, Vertic* b){
	int aOffset = OffsetOfVerticInArr(&a, g->Vertices, g->V);
	int bOffset = OffsetOfVerticInArr(&b, g->Vertices, g->V);
	return g->ArcMat[aOffset][bOffset];
}

LinearLinkedListNode* GetAllAdjacent(Graph* g, Vertic* a){
	int aOffset = OffsetOfVerticInArr(&a, g->Vertices, g->V);
	int counter;
	LinearLinkedListNode* manger = NULL;
	for (counter = 0; counter < g->V; counter++)
	{
		if (g->ArcMat[aOffset][counter]>-1)
			PushLinearLinkedListNode(&manger, &g->Vertices[counter]);
	}
	return manger;
}
