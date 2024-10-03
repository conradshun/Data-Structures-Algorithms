/*
=====================================================================================
FILE        : main.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : This program demonstrates the use of a heap sort algorithm
COPYRIGHT   : 03 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "list.h"
#include "heapsort.h"

/*
============================================================================
FUNCTION    : main
DESCRIPTION : Entry point of the program. Allows users to create a list, display the list,
              perform heap sort on the list, or exit the program
ARGUMENTS   : none
RETURNS     : 0
===========================================================================
*/

int main()
{
    int choice;
    int start = 0;

    LIST *L = (LIST*)malloc(sizeof(LIST));
    L->head = NULL;
    L->tail = NULL;

    do {
        system("cls");

        printf("\n[1] Create List");
        printf("\n[2] Display List");
        printf("\n[3] Heap Sort");
        printf("\n[4] Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                createList(L, &start);
                printf("\nList Created");
                displayList(L);
                break;
            case 2:
                displayList(L);
                break;
            case 3:
                if(start == 1) {
                    heapSort(L, start);
                } else {
                    printf("\nList is empty. Create List first\n");
                }
                break;
            case 4:
                printf("Exiting program");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if(choice != 4) {
            printf("\nPlease enter any key to continue");
            getch();
        }

    } while(choice != 4);

    // Free memory before exiting
    destroyList(L);
    free(L);

    return 0;
}
