/*
Created by yhk on 2024/10/15
Description: Experiment 1.3
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

// Function to reverse the linked list
STATUS ReverseList(headerList& L)
{
    if (L.len <= 1) return OK; // No need to reverse if empty or single element

    Node* prev = NULL;
    Node* curr = L.head->next;
    Node* next = NULL;

    while (curr)
    {
        next = curr->next; // Store next node
        curr->next = prev; // Reverse current node's pointer
        prev = curr;       // Move prev to current
        curr = next;      // Move to next node
    }

    L.head->next = prev; // Update head to point to new first element
    return OK;
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



STATUS PrintList(headerList& L)
{
    Node* p = L.head;
    while (p->next)
    {
        printf("%d\t", p->next->data.data);
        p = p->next;
    }
    return OK;
}

STATUS DestroyList(headerList& L)
{
    if (L.head == NULL) return OK;
    Node* p = L.head;
    while (p)
    {
        Node* q = p;
        p = p->next;
        free(q);
    }
    L.head = NULL;
    L.len = 0;
    free(p);
    return OK;
}


// MAIN FUNCTION
int main() {
    headerList myList;
    InitList(myList);

    //Create a list by inserting elements
    Element e1 = { 1 }, e2 = { 2 }, e3 = { 3 }, e4 = { 4 };
    InsertElem(myList, 0, e1);
    InsertElem(myList, 1, e2);
    InsertElem(myList, 2, e3);
    InsertElem(myList, 3, e4);

    // Print original list
    printf("Original list: ");
    PrintList(myList);
    printf("\n");

    ReverseList(myList);

    // Print reversed list
    printf("Reversed list: ");
    PrintList(myList);
    printf("\n");
    //printf("Destroying the list...\n");
    DestroyList(myList);
    //printf("List destroyed.\n");
    return 0;
}