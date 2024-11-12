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

STATUS Search(LGraph* lg, int u, int v)
{
	ENode* p;
	if (u < 0 || v < 0 || u >= lg->n || v >= lg->n || u == v) return ERROR;
	p = lg->a[u];
	while (p && p->adjVex != v)
	{
		p = p->nextArc;
	}
	if (!p) return NOTFOUND;
	return OK;
}

STATUS Remove(LGraph* lg, int u, int v)
{
	ENode* p, * q;
	if (u < 0 || v < 0 || u >= lg->n || v >= lg->n || u == v) return ERROR;
	p = lg->a[u];
	if (!p) return NOTFOUND;
	if (p->adjVex == v)
	{
		lg->a[u] = p->nextArc;
		free(p);
		lg->e--;
		return OK;
	}
	while (p->nextArc && p->nextArc->adjVex != v)
	{
		p = p->nextArc;
	}
	if (!p->nextArc) return NOTFOUND;
	q = p->nextArc;
	p->nextArc = q->nextArc;
	free(q);
	lg->e--;
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


int main()
{
	LGraph lg;
	int i;
	Init(&lg, 12);
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
	Insert(&lg, 5, 11, 1);
	Insert(&lg, 6, 11, 1);
	Insert(&lg, 7, 10, 1);
	Insert(&lg, 8, 11, 1);
	Insert(&lg, 9, 10, 1);
	Insert(&lg, 9, 11, 1);
	Display(&lg);
	Destroy(&lg);
	return 0;
}