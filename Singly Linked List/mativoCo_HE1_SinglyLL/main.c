/*
============================================================================
FILE        : main.c
AUTHOR      : Conrad Nestor B. Mativo
DESCRIPTION : A program that can insert (front, rear, at) the elements into a singly linked list, delete
(front, rear, at) the elements from that list and display all elements in that list.
COPYRIGHT   : 05 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/
#include <stdio.h>
#include "sllheader.h"
/*
============================================================================
FUNCTION    : int main
DESCRIPTION : Executes the main program
ARGUMENTS   : Void
RETURNS     : int - returns the exit code
============================================================================
*/
int main() {
    struct list *L = (struct list *)malloc(sizeof(struct list));
    initializeList(&L);

    printf("INITIAL DATA= 25, 30, 35\n\n");
    // Initial data in the linked list
    insertRear(&L, 25);
    insertRear(&L, 30);
    insertRear(&L, 35);

    // Execute the sequence of operations
    displayAll(&L); // Display initial data
    insertFront(&L, 2); displayAll(&L);
    insertFront(&L, 1); displayAll(&L);
    insertFront(&L, 0); displayAll(&L);
    insertRear(&L, 3); displayAll(&L);
    insertRear(&L, 5); displayAll(&L);
    insertAt(&L, 4, 4); displayAll(&L);
    deleteFront(&L); displayAll(&L);
    deleteRear(&L); displayAll(&L);
    insertAt(&L, 88, 2); displayAll(&L);
    deleteAt(&L, 2); displayAll(&L);

    return 0;
}
