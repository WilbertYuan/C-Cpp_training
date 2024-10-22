/*
Created by yhk on 2024/10/15
Description: Experiment 1.1
*/
#include "DataStructure-seqlist.h"

// FUNCTION DEFINITION OF THE SEQUENCE LIST INITIALIZATION AND OPERATIONS AND DESTRUCTION
STATUS InitList(SeqList& L, int ms)
{
	L.first_data_pointer = (Element*)malloc(ms*sizeof(Element));
	if(!L.first_data_pointer) return ERROR;
	L.maxsize = ms;
	L.maxlen = 0;
	return OK;
}
STATUS FindElem(SeqList L, Element e) // O(n)
{
	for(int i=0; i<L.maxlen; i++)
		if(L.first_data_pointer[i].data == e.data) return i;
	return NOTFOUND;
}
STATUS InsertElem(SeqList& L, int i, Element e)  // i refers to the POSITION(count from 0) of the element AFTER its insert.
{
	if(i<0 || i>L.maxlen) return ERROR;
	if(L.maxlen >= L.maxsize) return OVERFLOW;
	for(int j=L.maxlen; j>i; j--)
		L.first_data_pointer[j] = L.first_data_pointer[j-1];
	L.first_data_pointer[i] = e;
	L.maxlen++;
	return OK;
}
STATUS DeleteElem(SeqList& L, int i)
{
	if(i<0 || i>=L.maxlen) return ERROR;
	for(int j=i; j<L.maxlen-1; j++)
		L.first_data_pointer[j] = L.first_data_pointer[j+1];
	L.maxlen--;
	printf("The element %d at the position %d is deleted.\n",L.first_data_pointer[i].data,i);
	return OK;
}
STATUS DestroyList(SeqList& L)
{
	free(L.first_data_pointer);
	L.maxsize = 0;
	L.maxlen = 0;
	return OK;
}
void PrintList(SeqList L)
{
	for(int i=0; i<L.maxlen; i++)
		printf("%d\t", L.first_data_pointer[i].data);
	printf("\n");
}
int main()
{
	seqList L;
	InitList(L, 100);
	Element e,element_to_find;
	e.data = 1;
	element_to_find.data = 24;
	while(InsertElem(L, 0, e) == OK) // Make the Sequence List L with elements from 100 to 1.
	{
		e.data++;
	}
	PrintList(L);
	STATUS find_status = FindElem(L, element_to_find);
	if ( find_status != NOTFOUND)
		printf("The element %d is found at the position %d.\n", element_to_find.data, find_status);
	else
	{
		printf("The element %d is not found.\n", element_to_find.data);
	}
	DeleteElem(L, 29);
	PrintList(L);
	DestroyList(L);
	return 0;
}







