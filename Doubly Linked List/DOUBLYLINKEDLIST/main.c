/*
============================================================================
FILE        : main.c
AUTHOR      : Conrad Nestor B. Mativo
DESCRIPTION : A program that  insert (front, rear, at) the elements in to a doubly linked list, delete (front, rear, at)
the elements from that list and display (from front, from rear) all elements in that list.
COPYRIGHT   : 11 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "dLLheader.h"
/*
============================================================================
FUNCTION    : int main
DESCRIPTION : Executes the main program
ARGUMENTS   : Void
RETURNS     : int - returns the exit code
============================================================================
*/
int main() {

    insertFront(3);
    printList();

    insertFront(2);
    printList();

    insertFront(1);
    printList();

    insertRear(5);
    printList();

    insertAt(0, 0);
    printList();

    removeFront();
    printList();

    removeRear();
    printList();

    removeRear();
    printList();

    insertRear(6);
    printList();

    insertAt(4, 3);
    printList();

    insertAt(7, 6);
    printList();

    insertAt(8, 2);
    printList();

    removeAt(2);
    printList();

    return 0;
}
