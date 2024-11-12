#include<stdio.h>
#include<stdlib.h>
// STATUS CODE DEFINITION
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define UNDERFLOW -3
#define NOTFOUND -4
#define DUPLICATE -5

typedef int ElemType, STATUS;

typedef struct mGraph
{
	ElemType** a;
	int n;
	int e;
	ElemType noEdge;
}mGraph;

STATUS Init(mGraph* mg, int nSize, ElemType noEdgeValue)
{
	int i, j;
	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));
	if (!mg->a) return ERROR;
	for (i = 0; i < nSize; i++)
	{
		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
		if (!mg->a[i]) return ERROR;
	}
	mg->n = nSize;
	mg->e = 0;
	mg->noEdge = noEdgeValue;
	for (i = 0; i < mg->n; i++)
	{
		for (j = 0; j < mg->n; j++)
		{
			mg->a[i][j] = mg->noEdge;
		}
	}
	return OK;
}

void Destroy(mGraph* mg)
{
	int i;
	for (i = 0; i < mg->n; i++)
		free(mg->a[i]);
	free(mg->a);
	mg->n = 0;
	mg->e = 0;
	mg->noEdge = 0;
}

STATUS Insert(mGraph* mg, int u, int v, ElemType w)
{
	if (u < 0 || v < 0 || u >= mg->n || v >= mg->n || u == v) return ERROR;
	if (mg->a[u][v] != mg->noEdge) return DUPLICATE;
	mg->a[u][v] = w;
	mg->e++;
	return OK;
}

void Display(mGraph* mg)
{
	int i, j;
	for (i = 0; i < mg->n; i++)
	{
		for (j = 0; j < mg->n; j++)
		{
			if (mg->a[i][j] == mg->noEdge)
				printf("%4d", mg->noEdge);
			else
				printf("%4d", mg->a[i][j]);
		}
		printf("\n\n");
	}
}

void DFS(int i, mGraph* mg, int* visited)
{
	int j;
	visited[i] = 1;
	printf("%d ", i);
	for (j = 0; j < mg->n; j++)
	{
		if (mg->a[i][j] != mg->noEdge && !visited[j])
			DFS(j, mg, visited);
	}
}

void DFSGragh(mGraph* mg)
{
	int i;
	int* visited = (int*)malloc(mg->n * sizeof(int));
	for (i = 0; i < mg->n; i++)
		visited[i] = 0;
	for (i = 0; i < mg->n; i++)
	{
		if (!visited[i])
			DFS(i, mg, visited);
	}
	free(visited);
}

void BFS(int i, mGraph* mg, int* visited)
{
	int j;
	int* queue = (int*)malloc(mg->n * sizeof(int));
	int front = 0, rear = 0;
	printf("%d ", i);
	visited[i] = 1;
	queue[rear++] = i;
	while (front != rear)
	{
		i = queue[front++];
		for (j = 0; j < mg->n; j++)
		{
			if (mg->a[i][j] != mg->noEdge && !visited[j])
			{
				printf("%d ", j);
				visited[j] = 1;
				queue[rear++] = j;
			}
		}
	}
	free(queue);
}

void BFSGragh(mGraph* mg)
{
	int i;
	int* visited = (int*)malloc(mg->n * sizeof(int));
	for (i = 0; i < mg->n; i++)
		visited[i] = 0;
	for (i = 0; i < mg->n; i++)
	{
		if (!visited[i])
			BFS(i, mg, visited);
	}
	free(visited);
}

// test for the dfs&BFS of a 12-node graph
int main()
{
	mGraph mg;
	int i;
	Init(&mg, 12, 0);
	Insert(&mg, 0, 1, 1);
	Insert(&mg, 0, 2, 1);
	Insert(&mg, 1, 3, 1);
	Insert(&mg, 1, 4, 1);
	Insert(&mg, 2, 5, 1);
	Insert(&mg, 2, 6, 1);
	Insert(&mg, 3, 7, 1);
	Insert(&mg, 3, 8, 1);
	Insert(&mg, 4, 9, 1);
	Insert(&mg, 4, 10, 1);
	Insert(&mg, 5, 11, 1);
	Insert(&mg, 6, 11, 1);
	Insert(&mg, 7, 8, 1);
	Insert(&mg, 9, 10, 1);
	Display(&mg);
	printf("for the DFS sequence:");
	DFSGragh(&mg);
	printf("\n\n");
	printf("for the BFS sequence:");
	BFSGragh(&mg);
	printf("\n\n");
	Destroy(&mg);
	return 0;
}
