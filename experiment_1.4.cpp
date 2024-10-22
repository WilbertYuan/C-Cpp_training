/*
Created by yhk on 2024/10/15
Description: Experiment 1.4
*/


// DATA STRUCTURE DEFINITION HEADER
#include "DataStructure-linklist.h"

// FUNCTION DEFINITION

STATUS InitList(headerList* L) {
    L->head = (Node*)malloc(sizeof(Node));
    if (!L->head) return ERROR;
    L->head->next = NULL;
    L->len = 0;
    return OK;
}

STATUS InsertElem(headerList* L, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return ERROR;
    newNode->data.data = data;
    newNode->next = NULL;

    Node* p = L->head;
    while (p->next) {
        p = p->next; // Move to the end of the list
    }
    p->next = newNode; // Insert at the end
    L->len++;
    return OK;
}

STATUS PrintList(headerList L) {
    Node* p = L.head->next; // Start from the first actual element
    while (p) {
        printf("%d\t", p->data.data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

STATUS SortList(headerList* L) {
    if (L->head->next == NULL || L->head->next->next == NULL) {
        return OK; // List is empty or has only one element
    }

    Node* sorted = NULL; // Pointer for sorted part
    Node* current = L->head->next; // Start from the first element

    while (current) {
        Node* next = current->next; // Store next node

        // Insert current into the sorted list
        if (sorted == NULL || sorted->data.data >= current->data.data) {
            current->next = sorted; // Insert at the beginning
            sorted = current; // Move sorted to point to the new head
        }
        else {
            Node* temp = sorted;
            while (temp->next && temp->next->data.data < current->data.data) {
                temp = temp->next; // Find the position to insert
            }
            current->next = temp->next; // Insert current
            temp->next = current;
        }

        current = next; // Move to the next node
    }

    L->head->next = sorted; // Update the head to point to the sorted list
    return OK;
}

STATUS DestroyList(headerList* L) {
    Node* p = L->head->next;
    while (p) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
    free(L->head);
    L->len = 0;
    return OK;
}

int main() {
    headerList myList;
    InitList(&myList);

    InsertElem(&myList, 3);
    InsertElem(&myList, 1);
    InsertElem(&myList, 4);
    InsertElem(&myList, 2);
    InsertElem(&myList, 5);


    printf("Original list: ");
    PrintList(myList);
    SortList(&myList);
    printf("Sorted list: ");
    PrintList(myList);


    DestroyList(&myList);

    return 0;
}