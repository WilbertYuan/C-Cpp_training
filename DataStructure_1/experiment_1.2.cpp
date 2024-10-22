/*
Created by yhk on 2024/10/15
Description: Experiment 1.2
*/

// DATA STRUCTURE DEFINITION HEADER
#include "DataStructure-linklist.h"

// FUNCTION DEFINITION OF THE HEADER LINKLIST INITIALIZATION AND OPERATIONS AND DESTRUCTION
STATUS InitList(headerList& L)
{
    L.head = (Node*)malloc(sizeof(Node));
    if (!L.head) return ERROR;
    L.head->next = NULL;
    L.len = 0;
    return OK;
}

STATUS FindElem(headerList L, Element e)
{
    Node* p = L.head->next;
    int i = 0;
    while (p)
    {
        if (p->data.data == e.data) return i;
        p = p->next;
        i++;
    }
    return NOTFOUND;
}

STATUS InsertElem(headerList& L, int i, Element e) // i refers to the same meaning as in the sequence list (Experiment 1.1).
{
    if (i < 0 || i > L.len) return ERROR;
    Node* p = L.head;
    for (int j = 0; j < i; j++)
        p = p->next;
    Node* q = (Node*)malloc(sizeof(Node));
    if (!q) return ERROR;
    q->data = e;
    q->next = p->next;
    p->next = q;
    L.len++;
    return OK;
}

STATUS DeleteElem(headerList& L, int i)
{
    if (i < 0 || i >= L.len) return ERROR;
    Node* p = L.head;
    for (int j = 0; j < i; j++)
        p = p->next;
    Node* q = p->next;
    p->next = q->next;
    free(q);
    L.len--;
    return OK;
}

STATUS PrintList(headerList& L)
{
    Node* p = L.head->next; // Start from the first actual element
    while (p)
    {
        printf("%d\t", p->data.data);
        p = p->next;
    }
    return OK;
}

STATUS DestroyList(headerList& L)
{
    if (L.head == NULL) return OK; // If the list is already empty, return
    Node* p = L.head;
    while (p)
    {
        Node* q = p;
        p = p->next;
        free(q); // Free current node
    }
    L.head = NULL; // Prevent dangling pointer
    L.len = 0; // Reset length
    return OK;
}

int main() {
    headerList myList;
    InitList(myList); // Initialize list

    // Create a list by inserting elements
    Element e1 = { 1 }, e2 = { 2 }, e3 = { 3 }, e4 = { 4 };
    InsertElem(myList, 0, e1);
    InsertElem(myList, 1, e2);
    InsertElem(myList, 2, e3);
    InsertElem(myList, 3, e4);


    printf("list: ");
    PrintList(myList);
    printf("\n");

    // Destroy the list
    DestroyList(myList);

    return 0;
}
