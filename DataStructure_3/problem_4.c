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

typedef struct eNode {
	int adjVex;
	ElemType w;
	struct eNode* nextArc;
}ENode;
typedef struct lGraph {
	int n;
	int e;
	ENode** a;
}LGraph;

STATUS Init(LGraph* lg, int nSize)
{
	int i;
	lg->a = (ENode**)malloc(nSize * sizeof(ENode*));
	if (!lg->a) return ERROR;
	for (i = 0; i < nSize; i++)
	{
		lg->a[i] = NULL;
	}
	lg->n = nSize;
	lg->e = 0;
	return OK;
}

void Destroy(LGraph* lg)
{
	int i;
	ENode* p, * q;
	for (i = 0; i < lg->n; i++)
	{
		p = lg->a[i];
		while (p)
		{
			q = p;
			p = p->nextArc;
			free(q);
		}
	}
	free(lg->a);
	lg->n = 0;
	lg->e = 0;
}

STATUS Insert(LGraph* lg, int u, int v, ElemType w)
{
	ENode* p, * q;
	if (u < 0 || v < 0 || u >= lg->n || v >= lg->n || u == v) return ERROR;
	p = lg->a[u];
	while (p && p->adjVex != v)
	{
		p = p->nextArc;
	}
	if (p) return DUPLICATE;
	p = (ENode*)malloc(sizeof(ENode));
	if (!p) return OVERFLOW;
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];
	lg->a[u] = p;
	lg->e++;
	return OK;
}

void Display(LGraph* lg)
{
	int i;
	ENode* p;
	for (i = 0; i < lg->n; i++)
	{
		p = lg->a[i];
		printf("%d", i);
		while (p)
		{
			printf(" -> %d(%d) ", p->adjVex, p->w);
			p = p->nextArc;
		}
		printf("\n");
	}
}

void DFS(int i, LGraph* lg, int* visited)
{
	ENode* p;
	visited[i] = 1;
	printf("%d ", i);
	p = lg->a[i];
	while (p)
	{
		if (!visited[p->adjVex])
			DFS(p->adjVex, lg, visited);
		p = p->nextArc;
	}
}

void DFSGragh(LGraph* lg)
{
	int i;
	int* visited = (int*)malloc(lg->n * sizeof(int));
	for (i = 0; i < lg->n; i++)
		if(visited != NULL)
			visited[i] = 0;
	for (i = 0; i < lg->n; i++)
	{
		if (visited != NULL && !visited[i])
			DFS(i, lg, visited);
	}
	free(visited);
}


void BFS(int i, LGraph* lg, int* visited)
{
	int j;
	int* queue = (int*)malloc(lg->n * sizeof(int));
	int front = 0, rear = 0;
	ENode* p;
	printf("%d ", i);
	visited[i] = 1;
	if(queue != NULL) queue[rear++] = i;
	while (front != rear)
	{
		i = queue[front++];
		p = lg->a[i];
		while (p)
		{
			if (!visited[p->adjVex])
			{
				printf("%d ", p->adjVex);
				visited[p->adjVex] = 1;
				queue[rear++] = p->adjVex;
			}
			p = p->nextArc;
		}
	}
	free(queue);
}

void BFSGragh(LGraph* lg)
{
	int i, j;
	int* visited = (int*)malloc(lg->n * sizeof(int));
	ENode* p;
	if (visited == NULL) return;
	for (i = 0; i < lg->n; i++)
		visited[i] = 0;
	for (i = 0; i < lg->n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%d ", i);
			for (j = 0; j < lg->n; j++)
			{
				p = lg->a[i];
				while (p)
				{
					if (!visited[p->adjVex])
					{
						visited[p->adjVex] = 1;
						printf("%d ", p->adjVex);
					}
					p = p->nextArc;
				}
			}
		}
	}
	free(visited);
}

//TEST FOR A 16-NODE GRAPH
int main()
{
	LGraph lg;
	int i;
	Init(&lg, 16);
	Insert(&lg, 0, 1, 1);
	Insert(&lg, 0, 2, 1);
	Insert(&lg, 0, 3, 1);
	Insert(&lg, 1, 4, 1);
	Insert(&lg, 1, 5, 1);
	Insert(&lg, 2, 6, 1);
	Insert(&lg, 2, 7, 1);
	Insert(&lg, 3, 8, 1);
	Insert(&lg, 3, 9, 1);
	Insert(&lg, 4, 10, 1);
	Insert(&lg, 4, 11, 1);
	Insert(&lg, 5, 12, 1);
	Insert(&lg, 5, 13, 1);
	Insert(&lg, 6, 14, 1);
	Insert(&lg, 6, 15, 1);
	/*Insert(&lg, 0, 1, 1);
	Insert(&lg, 0, 2, 1);
	Insert(&lg, 0, 3, 1);
	Insert(&lg, 1, 4, 1);
	Insert(&lg, 1, 5, 1);
	Insert(&lg, 2, 6, 1);
	Insert(&lg, 2, 7, 1);
	Insert(&lg, 3, 8, 1);
	Insert(&lg, 3, 9, 1);
	Insert(&lg, 4, 10, 1);
	Insert(&lg, 5, 11, 1);
	Insert(&lg, 6, 11, 1);
	Insert(&lg, 7, 10, 1);
	Insert(&lg, 8, 11, 1);
	Insert(&lg, 9, 10, 1);
	Insert(&lg, 9, 11, 1);*/
	Display(&lg);
	printf("\n\n");
	printf("for the DFS sequence:");
	DFSGragh(&lg);
	printf("\n\n");
	printf("for the BFS sequence:");
	BFSGragh(&lg);
	printf("\n\n");
	Destroy(&lg);
	return 0;
}
