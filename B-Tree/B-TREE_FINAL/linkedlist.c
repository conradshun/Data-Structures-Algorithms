/*
=====================================================================================
FILE        : linkedlist.c
AUTHOR      : Conrad Nestor Mativo, Justin Catalan, Lorenz Soriano, Jack Pollo
DESCRIPTION : Implementation file for the linkedlist
COPYRIGHT   : 15 May 2024
=====================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node *head = NULL;

void insertNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNodeFromList(int data) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int searchNode(int data) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayDepthFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Depth-First Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            temp = temp->next;
        } else {
            while (temp->next == NULL) {
                temp = temp->next;
                if (temp == NULL)
                    break;
            }
        }
    }
    printf("\n");
}

void displayBreadthFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Breadth-First Traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) {
            temp = temp->next;
        } else {
            while (temp->next == NULL) {
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
            }
        }
    }
    printf("\n");
}
