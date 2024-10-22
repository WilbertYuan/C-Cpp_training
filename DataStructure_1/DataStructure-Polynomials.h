#include <stdio.h>
#include <stdlib.h>
// STATUS CODE DEFINITION
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define UNDERFLOW -3
#define NOTFOUND -4
#define DUPLICATE -5
typedef int STATUS;

// POLYNOMIAL NODE DEFINITION£¨DATA STRUCTURE£©
typedef struct pNode {
    int coef;
    int exp;
    struct pNode* link;
} PNode;
typedef struct polynominall {
    PNode* head;
} Polynominal;

// FUNCTION DEFINITION
STATUS InitPolynominal(Polynominal* P) {
    P->head = (PNode*)malloc(sizeof(PNode));
    if (!P->head) return ERROR;
    P->head->link = NULL;
    return OK;
}