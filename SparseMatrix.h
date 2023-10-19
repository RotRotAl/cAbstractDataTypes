#pragma once
#include <stdlib.h>
#include "MathLibrary.h"
#include <stdio.h>

#ifndef __SPAREMATRIX
#define __SPAREMATRIX
typedef struct SM
{
	void* info;
	int row;
	int col;
	struct SM* nextRow;
	struct SM* nextCol;
} SparseMatrix;
#endif //!__SPAREMATRIX

//Retrun true if the cell in [x,y] is empty
BOOL IsEmptyCellSparseMatrix(int, int, SparseMatrix*);
//Retrun the cell above givven
SparseMatrix* FindAboveSparseMatrix(int, int, SparseMatrix*);
//Retrun the cell before givven
SparseMatrix* FindBeforeSparseMatrix(int, int,  SparseMatrix*);
//Insert new cell into the matrix in [x,y]
void InsertAfterSparseMatrix(int, int, SparseMatrix*, void*);
//Delete cell in matrix [x,y]
void DeleteAfterSparseMatrix(int, int, SparseMatrix*);
//Init the matrix
void InitSparseMatrix(int, int, SparseMatrix**);
//Returm true if the matrix empty
BOOL IsEmptySparseMatrix(SparseMatrix*);
//Adds new col to the matrix
void AddColSparseMatrix(SparseMatrix**);
//Adds new row into the matrix
void AddRowSparseMatrix(SparseMatrix**);
//Print the matrix
void PrintSparseMatrixNode(SparseMatrix*);