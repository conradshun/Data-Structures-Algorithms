/*
=====================================================================================
FILE        : convert.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation file for decimal to hexadecimal conversion.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#include <stdio.h>
#include "convert.h"
#include "stack.h"

/*
============================================================================
FUNCTION : decToHex
DESCRIPTION : Converts a decimal number to its hexadecimal equivalent.
ARGUMENTS : -int decimal: The decimal number to be converted.
RETURNS : void - none
===========================================================================
*/

void decToHex(int decimal) {
    struct Node *stack = NULL;
    int temp = decimal;

    while (temp != 0) {
        int remainder = temp % 16;
        stack = push(stack, remainder);
        temp /= 16;
    }

    printf("STACK\n");
    struct Node *current = stack;
    while (current != NULL) {
        printf("|%4d |\n", current->data);
        current = current->next;
    }

    current = stack;
    printf("STACK TOP: %d\n", current->data);
    printf("HEXADECIMAL: ");
    while (current != NULL) {
        int hexDigit;
        current = pop(current, &hexDigit);
        if (hexDigit < 10)
            printf("%d", hexDigit);
        else
            printf("%c", 'A' + (hexDigit - 10));
    }
    printf("\n");
}

