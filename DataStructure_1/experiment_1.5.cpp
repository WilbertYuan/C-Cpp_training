/*
Created by yhk on 2024/10/15
Description: Experiment 1.5 - Operations on polynomials
*/

// DATA STRUCTURE DEFINITION HEADER
#include "DataStructure-Polynomials.h"

STATUS AddTerm(Polynominal* P, int coef, int exp) {
    if (coef == 0) return OK; // Do not add zero terms
    PNode* newNode = (PNode*)malloc(sizeof(PNode));
    if (!newNode) return ERROR;
    newNode->coef = coef;
    newNode->exp = exp;

    PNode* p = P->head;
    while (p->link && p->link->exp > exp) {
        p = p->link; // Find position to insert
    }
    if (p->link && p->link->exp == exp) {
        p->link->coef += coef; // Combine like terms
        free(newNode);
        if (p->link->coef == 0) {
            PNode* temp = p->link;
            p->link = temp->link; // Remove term if coefficient is zero
            free(temp);
        }
    }
    else {
        newNode->link = p->link;
        p->link = newNode; // Insert new term
    }
    return OK;
}

STATUS PrintPolynominal(Polynominal P) {
    PNode* p = P.head->link; // Start from the first term
    if (!p) {
        printf("0\n"); // Print zero if polynomial is empty
        return OK;
    }
    while (p) {
        printf("%dx^%d", p->coef, p->exp);
        p = p->link;
        if (p) printf(" + "); // Print plus sign between terms
    }
    printf("\n");
    return OK;
}

STATUS ClearPolynominal(Polynominal* P) {
    PNode* p = P->head->link;
    while (p) {
        PNode* temp = p;
        p = p->link;
        free(temp); // Free each term
    }
    P->head->link = NULL; // Reset head
    return OK;
}

STATUS AddPolynominals(Polynominal P1, Polynominal P2, Polynominal* result) {
    ClearPolynominal(result); // Clear result polynomial
    PNode* p1 = P1.head->link;
    PNode* p2 = P2.head->link;

    while (p1 || p2) {
        if (p1 && (!p2 || p1->exp > p2->exp)) {
            AddTerm(result, p1->coef, p1->exp);
            p1 = p1->link;
        }
        else if (p2 && (!p1 || p2->exp > p1->exp)) {
            AddTerm(result, p2->coef, p2->exp);
            p2 = p2->link;
        }
        else {
            AddTerm(result, p1->coef + p2->coef, p1->exp);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    return OK;
}

STATUS MultiplyPolynominals(Polynominal P1, Polynominal P2, Polynominal* result) {
    ClearPolynominal(result); // Clear result polynomial
    PNode* p1 = P1.head->link;
    PNode* p2 = P2.head->link;

    while (p1) {
        Polynominal temp;
        InitPolynominal(&temp); // Temporary polynomial for multiplication
        while (p2) {
            AddTerm(&temp, p1->coef * p2->coef, p1->exp + p2->exp); // Multiply and add
            p2 = p2->link;
        }
        AddPolynominals(*result, temp, result); // Add temporary result to final result
        ClearPolynominal(&temp); // Clear temporary polynomial
        p1 = p1->link;
        p2 = P2.head->link; // Reset p2 to the head
    }
    return OK;
}


// MAIN FUNCTION
int main() {
    Polynominal poly1, poly2, result;
    InitPolynominal(&poly1);
    InitPolynominal(&poly2);
    InitPolynominal(&result);

    // Create: 2x^3 + 3x^2 + 4
    AddTerm(&poly1, 2, 3);
    AddTerm(&poly1, 3, 2);
    AddTerm(&poly1, 4, 0);

    // Create: 5x^2 + 6x + 1
    AddTerm(&poly2, 5, 2);
    AddTerm(&poly2, 6, 1);
    AddTerm(&poly2, 1, 0);


    printf("Polynomial 1: ");
    PrintPolynominal(poly1);
    printf("Polynomial 2: ");
    PrintPolynominal(poly2);

    // Add polynomials
    AddPolynominals(poly1, poly2, &result);
    printf("Sum: ");
    PrintPolynominal(result);
    // Multiply polynomials
    MultiplyPolynominals(poly1, poly2, &result);
    printf("Product: ");
    PrintPolynominal(result);


    ClearPolynominal(&poly1);
    ClearPolynominal(&poly2);
    ClearPolynominal(&result);

    return 0;
}
