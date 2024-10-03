/*
=====================================================================================
FILE        : main.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : A program that determines the length of the string using the
              principle of QUEUE implementing Linked List
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "queue.h"

void processWord();

/*
============================================================================
FUNCTION : main
DESCRIPTION : Main function for a word processing program using a queue.
              Displays a menu for users to enter words or exit the program.
ARGUMENTS : None
RETURNS : returns 0 on successful execution
===========================================================================
*/

int main() {
    int choice;
    do {
        system("cls");
        printf("\n[1] Enter a word\n");
        printf("[2] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                processWord();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if(choice != 2){
            printf("\nPlease enter any key to continue");
            getch();
        }

    } while (choice != 2);

    return 0;
}
