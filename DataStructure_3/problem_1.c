#include<stdio.h>
#include<stdlib.h>
// STATUS CODE DEFINITION
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define UNDERFLOW -3
#define NOTFOUND -4
#define DUPLICATE -5

typedef int ElemType,STATUS;

typedef struct mGraph
{
	ElemType** a;
	int n;
	int e;
	ElemType noEdge;
}mGraph;

STATUS Init(mGraph*mg,int nSize,ElemType noEdgeValue)
{
	int i,j;
	mg->a=(ElemType**)malloc(nSize*sizeof(ElemType*));
	if(!mg->a) return ERROR;
	for(i=0;i<nSize;i++)
	{
		mg->a[i]=(ElemType*)malloc(nSize*sizeof(ElemType));
		if(!mg->a[i]) return ERROR;
	}
	mg->n=nSize;
	mg->e=0;
	mg->noEdge=noEdgeValue;
	for(i=0;i<mg->n;i++)
	{
		for(j=0;j<mg->n;j++)
		{
			mg->a[i][j]=mg->noEdge;
		}
	}
	return OK;
}

void Destroy(mGraph*mg)
{
	int i;
	for(i=0;i<mg->n;i++)
		free(mg->a[i]);
	free(mg->a);
	mg->n=0;
	mg->e=0;
	mg->noEdge=0;
}

STATUS Insert(mGraph*mg,int u,int v,ElemType w)
{
	if(u<0||v<0||u>=mg->n||v>=mg->n||u==v) return ERROR;
	if(mg->a[u][v]!=mg->noEdge) return DUPLICATE;
	mg->a[u][v]=w;
	mg->e++;
	return OK;
}

STATUS Search(mGraph* mg, int u, int v)
{
	if(u<0||v<0||u>=mg->n||v>=mg->n||u==v) return ERROR;
	if(mg->a[u][v]==mg->noEdge) return NOTFOUND;
	return OK;
}

STATUS Remove(mGraph* mg, int u, int v)
{
	if(u<0||v<0||u>=mg->n||v>=mg->n||u==v) return ERROR;
	if(mg->a[u][v]==mg->noEdge) return NOTFOUND;
	mg->a[u][v]=mg->noEdge;
	mg->e--;
	return OK;
}

void Display(mGraph* mg)
{
	int i,j;
	for(i=0;i<mg->n;i++)
	{
		for(j=0;j<mg->n;j++)
		{
			if(mg->a[i][j]==mg->noEdge)
				printf("%4d",mg->noEdge);
			else
				printf("%4d",mg->a[i][j]);
		}
		printf("\n\n");
	}
}

int main() //example for a 7-node graph
{
	mGraph mg;
	int i;
	Init(&mg,7,0);
	Insert(&mg,0,1,1);
	Insert(&mg,3,1,9);
	Insert(&mg,0,3,32);
	Insert(&mg,1,4,4);
	Insert(&mg,2,4,15);
	Insert(&mg,6,3,2);
	Insert(&mg,4,6,78);
	Insert(&mg,5,6,9);
	Display(&mg);
	if (Search(&mg, 0, 1)) printf("Edge <0,1> found\n\n");
	else printf("Edge <0,1> not found\n\n");
	printf("Removing edge <0,1>\n\n");
	Remove(&mg,0,1);
	printf("After removing edge <0,1>:\n\n");
	Display(&mg);
	//Display(&mg);
	Destroy(&mg);
	return 0;}

