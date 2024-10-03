/*
=====================================================================================
FILE        : list.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation of list operations including display, creation,
              insertion at the end, and destruction
COPYRIGHT   : 03 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

/*
============================================================================
FUNCTION    : displayList
DESCRIPTION : Displays the elements of the list
ARGUMENTS   : LIST *L: Pointer to the linked list to be displayed
RETURNS     : void - none
===========================================================================
*/

void displayList(LIST *L) {
    NODE *walker = L->head;

    if(walker == NULL) {
        printf("\n\nList is empty. Create List first\n");
    } else {
        printf("\n\nList: ");
        while(walker) {
            printf("%4d", walker->x);
            walker = walker->n;
        }
        printf("\n\n");
    }
}

/*
============================================================================
FUNCTION    : createList
DESCRIPTION : Creates a list with random integer data
ARGUMENTS   : LIST *L: Pointer to the linked list to be created
              int start - sets list to 1 when creating list
RETURNS     : void - none
===========================================================================
*/

void createList(LIST *L, int *start) {
    int i, n;

    if((L->count) > 0) {
        destroyList(L);
    }
    *start = 1;

    time_t t;
    srand((unsigned) time(&t));

    for(i = 0; i < 10; i++) {
        n = rand() % 101;
        insertEnd(L, n);
    }
}

void insertEnd(LIST *L, int data) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->i = L->count;
    newNode->x = data;
    newNode->n = NULL;
    newNode->p = NULL;

    if(L->count == 0) {
        L->head = newNode;
        L->tail = L->head;
    } else {
        L->tail->n = newNode;
        newNode->p = L->tail;
        L->tail = newNode;
    }
    (L->count)++;
}

void destroyList(LIST *L) {
    NODE *walker = L->tail;

    while(L->head != L->tail) {
        L->tail = L->tail->p;
        free(walker);
        walker = L->tail;
    }

    free(L->head);
    L->head = NULL;
    L->tail = NULL;
    L->count = 0;
}
