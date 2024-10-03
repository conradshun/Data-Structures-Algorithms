/*
=====================================================================================
FILE        : heapsort.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation of Heap Sort algorithm for sorting
COPYRIGHT   : 03 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "heapsort.h"

/*
============================================================================
FUNCTION    : heapSort
DESCRIPTION : Sorts a list using the Heap Sort algorithm
ARGUMENTS   : LIST *L - Pointer to the linked list to be sorted
              int start - checks start value if list exists or not
RETURNS     : void - none
===========================================================================
*/

void heapSort(LIST *L, int start) {
    NODE *walker = L->head;
    NODE *last, *root;
    int temp, i, j, n = 10;

    for(i = 0; i < n ; i++) {
        reheapUp(L, walker, i, start);
        walker = walker->n;
    }

    j = 0;
    last = L->tail;
    root = L->head;

    while(last != root) {
        temp = last->x;
        last->x = root->x;
        root->x = temp;

        last = last->p;

        reheapDown(L, last, start);
        printf("\nPass %d: ", j++);
        displayList(L);
    }

    printf("\nSorted Data");
    displayList(L);
}

/*
============================================================================
FUNCTION    : reheapUp
DESCRIPTION : Performs the reheap up operation in the heap
ARGUMENTS   : LIST *L - Pointer to the linked list
              NODE* walker - Pointer to the current node being evaluated
              int index - Index of the current node in the heap
              int start - checks start value if list exists or not
RETURNS     : void - none
===========================================================================
*/

void reheapUp(LIST *L, NODE *walker, int index, int start) {
    NODE *parent = walker;
    int temp;

    while(parent && parent->i != (index - 1) / 2) {
        parent = parent->p;
    }

    while(parent && index > 0 && walker->x > parent->x) {
        temp = parent->x;
        parent->x = walker->x;
        walker->x = temp;

        walker = parent;
        index = (index - 1) / 2;

        while(parent && parent->i != (index - 1) / 2) {
            parent = parent->p;
        }
    }
}

/*
============================================================================
FUNCTION    : reheapDown
DESCRIPTION : Performs the reheap down operation in the heap
ARGUMENTS   : LIST *L - Pointer to the linked list
              NODE *last - Pointer to the last node in the heap
              int start - checks start value if list exists or not
RETURNS : void - none
===========================================================================
*/

void reheapDown(LIST *L, NODE *last, int start) {
    NODE *parent = L->head;
    NODE *child = L->head->n;
    int childIndex = 1;
    int temp;

    while(child && child->i <= last->i && (child->x > parent->x || child->n->x > parent->x)) {
        if(child->i < last->i && (child->x < child->n->x)) {
            child = child->n;
            childIndex++;
        }

        if(child->x > parent->x) {
            temp = parent->x;
            parent->x = child->x;
            child->x = temp;
        }

        parent = child;
        childIndex = childIndex * 2 + 1;

        while(child && child->i != childIndex) {
            child = child->n;
        }
    }
}
