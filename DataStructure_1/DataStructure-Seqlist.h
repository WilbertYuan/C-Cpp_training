#include<stdio.h>
#include<stdlib.h>
// STATUS CODE DEFINITION
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define UNDERFLOW -3
#define NOTFOUND -4
#define DUPLICATE -5
typedef int STATUS;

// DATA STRUCTURE DEFINITION
typedef struct Element
{
	int data;
}Element;

typedef struct seqList
{
	int maxsize, maxlen;
	Element* first_data_pointer;
}SeqList;
