/*
=====================================================================================
FILE        : main.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : A program that converts decimal number to hexadecimal number
              using the principle of STACK implementing Linked List.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "convert.h"

/*
============================================================================
FUNCTION : main
DESCRIPTION : Displays a menu for the user to choose between
              converting a decimal number to hexadecimal or
              exiting the program.
ARGUMENTS : None
RETURNS : 0 - on successful execution.
===========================================================================
*/

int main() {
    int choice;
    int decimal;

    do {
        system("cls");
        printf("\nMenu:\n");
        printf("[1] Convert\n");
        printf("[2] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("DECIMAL: %d\n", decimal);
                decToHex(decimal);
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
        if (choice != 2){
            printf("\nPlease enter any key to continue");
            getch();
        }

    } while (choice != 2);

    return 0;
}
