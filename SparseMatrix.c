#include "SparseMatrix.h"

SparseMatrix* FindAboveSparseMatrix(int row, int col, SparseMatrix* node)
{
	SparseMatrix* current = node->nextRow;
	while (current->col != col && current != node)
	{
		current = current->nextRow;
	}
	if (current->col == col)
		if (current->row != current->nextRow->row)
			while (current->row != row && current != node)
			{
				current = current->nextCol;
			}
		else {
			current == NULL;
		}
	return  current;
}

SparseMatrix* FindBeforeSparseMatrix(int row, int col,SparseMatrix* node)
{
	SparseMatrix* current = node->nextCol;
	while (current->row != row && current != node)
	{
		current = current->nextCol;
	}
	if(current->row == row);
	if (current->col != current->nextCol->col)
		while (current->col != col && current != node)
		{
			current = current->nextRow;
		}
	else
	{
		current = NULL;
	}
	return  current;
}

void InsertAfterSparseMatrix(int row, int col, SparseMatrix* node, void* value)
{

	BOOL isValid = IsEmptyCellSparseMatrix(row, col, node);
	SparseMatrix* above = FindAboveSparseMatrix(row, col, node);
	SparseMatrix* before = find_before_sparse_matrix(row, col, node);
	SparseMatrix* newNode = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	if (above && before && isValid) {
		newNode->info = value;
		newNode->row = row;
		newNode->col = col;
		newNode->nextRow = above->nextRow;
		newNode->nextCol = before->nextCol;
		before->nextRow = newNode;
		above->nextCol = newNode;
	}
}

BOOL IsEmptyCellSparseMatrix(int row, int col, SparseMatrix* node)
{
	SparseMatrix* current = FindBeforeSparseMatrix(row, col, node);
	return node == NULL || !current || current->nextCol->row != row || current->nextCol->col != col;
}
void DeleteAfterSparseMatrix(int row, int col, SparseMatrix* node)
{
	BOOL isValid = !IsEmptyCellSparseMatrix(row, col, node);
	SparseMatrix* above = FindAboveSparseMatrix(row, col, node);
	SparseMatrix* before = FindBeforeSparseMatrix(row, col, node);
	SparseMatrix* toDelete = before->nextCol;
	if (above && before && isValid) {
		before->nextCol = toDelete->nextCol;
		above->nextRow = toDelete->nextRow;
		free(toDelete);
	}
}

void InitSparseMatrix(int row, int col, SparseMatrix** manger)
{
	if (row > 1 && col > 1) {
		int count;
		SparseMatrix* current;
		SparseMatrix* next;
		SparseMatrix* RowAndColManger = (SparseMatrix*)malloc(sizeof(SparseMatrix));
		*manger = RowAndColManger;
		RowAndColManger->info = '\0';
		RowAndColManger->col = 0;
		RowAndColManger->row = 0;

		RowAndColManger->nextCol = (SparseMatrix*)malloc(sizeof(SparseMatrix));
		(RowAndColManger->nextCol)->col = 0;
		(RowAndColManger->nextCol)->row = 1;
		(RowAndColManger->nextCol)->info = '\0';

		RowAndColManger->nextRow = (SparseMatrix*)malloc(sizeof(SparseMatrix));
		(RowAndColManger->nextRow)->col = 1;
		(RowAndColManger->nextRow)->row = 0;
		(RowAndColManger->nextRow)->info = '\0';

		current = RowAndColManger->nextCol;
		for (count = 0; count < row - 1; count++)
		{
			next = (SparseMatrix*)malloc(sizeof(SparseMatrix));
			next->info = '\0';
			next->row = count + 2;
			next->col = 0;
			current->nextCol = next;
			current->nextRow = current;
			current = next;
		}
		current->nextCol = RowAndColManger;
		current->nextRow = current;

		current = RowAndColManger->nextRow;
		for (count = 0; count < col - 1; count++)
		{
			next = (SparseMatrix*)malloc(sizeof(SparseMatrix));
			next->info = '\0';
			next->col = count + 2;
			next->row = 0;
			current->nextRow = next;
			current->nextCol = current;
			current = next;
		}
		current->nextRow = RowAndColManger;
		current->nextCol = current;
	}
}

BOOL IsEmptySparseMatrix(SparseMatrix* manger)
{
	BOOL res = (!manger) || ((SparseMatrix*)manger)->nextCol != manger ||
		(( SparseMatrix*)manger)->nextRow != manger;
	 SparseMatrix* prog = ((SparseMatrix*)manger)->nextCol;
	while (!res && prog != manger)
	{
		res = prog->nextRow != prog;
		prog = prog->nextCol;
	}
	prog = ((SparseMatrix*)manger)->nextRow;
	while (!res && prog != manger)
	{
		res = prog->nextCol != prog;
		prog = prog->nextRow;
	}
	return !res;
}
void AddColSparseMatrix(SparseMatrix** manger) {
	SparseMatrix* current = *manger;
	SparseMatrix* next;
	SparseMatrix* col_head = current->nextCol;
	int col_num = current->nextCol->col; // The current number of columns

	// Iterate to the last column
	while (current->nextCol != col_head) {
		current = current->nextCol;
	}
	next = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	next->info = '\0';
	next->col = col_num + 1;
	next->row = 0;
	current->nextCol = next;
	next->nextCol = col_head;

	// Add the new column to the rows
	current = col_head;
	while (current->nextRow != current) {
		next = (SparseMatrix*)malloc(sizeof(SparseMatrix));
		next->info = '\0';
		next->col = col_num + 1;
		next->row = current->nextRow->row;
		current->nextRow->nextCol = next;
		next->nextCol = current->nextRow;
		current = current->nextRow;
	}
}
void AddRowSparseMatrix(SparseMatrix** manager)
{
	int row = (*manager)->nextCol->row;
	int col = (*manager)->nextRow->col;
	SparseMatrix* current = (*manager)->nextCol;

	while (current->nextCol != *manager)
	{
		current = current->nextCol;
	}

	SparseMatrix* newRowStart = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	newRowStart->row = row;
	newRowStart->col = 0;
	newRowStart->nextRow = newRowStart;
	newRowStart->nextCol = *manager;

	current->nextCol = newRowStart;

	SparseMatrix* currentCol = (*manager)->nextRow;
	SparseMatrix* currentRow = newRowStart;

	for (int i = 0; i < col; i++)
	{
		SparseMatrix* newNode = (SparseMatrix*)malloc(sizeof(SparseMatrix));
		newNode->row = row;
		newNode->col = i + 1;
		newNode->info = '\0';

		currentCol->nextRow = newNode;
		currentRow->nextCol = newNode;

		currentCol = currentCol->nextCol;
		currentRow = newNode;
	}
	currentRow->nextCol = newRowStart;
	currentCol->nextRow = currentRow;
}

void PrintSparseMatrixNode(SparseMatrix* node)
{
	BOOL res = IsEmptySparseMatrix(node);
	if (!res) {
		SparseMatrix* ptr = node->nextCol;
		SparseMatrix* temp;
		while (ptr->row)
		{
			temp = ptr->nextRow;
			while (temp->col)
			{
				printf("( %d ) ", temp->info);
				temp = temp->nextRow;
			}

			printf("\n");
			ptr = ptr->nextCol;
		}
	}
}
