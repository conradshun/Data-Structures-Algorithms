/*
============================================================================
 FILE        : main.c
 AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
 DESCRIPTION : Main program for list creation and search operations.
 COPYRIGHT   : 26 February 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "list.h"
#include "search.h"

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Main function to create a list and perform search operations.
 ARGUMENTS   : None
 RETURNS     : 0 for successful execution
===========================================================================
*/

int main()
{
    LIST *data = NULL;
    int choice, key, location;

    do {

        system("cls");

        printf("[1] Create List\n");
        printf("[2] Display List\n");
        printf("[3] Binary Search\n");
        printf("[4] Linear Search\n");
        printf("[5] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                data = createList();
                printf("\nList created\n");
                break;
            case 2:
                displayList(data);
                break;
            case 3:
                if(data == NULL){
                    printf("\nList is empty. Create list first\n");
                } else{
                    printf("Enter number to search: ");
                    scanf("%d", &key);
                    if(binarySearch(data, key, &location)){
                        printf("SEARCH FOUND in location %d\n", location);
                    } else{
                        printf("SEARCH NOT FOUND\n");
                    }
                }
                break;
            case 4:
                if(data == NULL){
                    printf("\nList is empty. Create list first\n");
                } else{
                    printf("Enter number to search: ");
                    scanf("%d", &key);
                    if(linearSearch(data, key, &location)){
                        printf("SEARCH FOUND in location %d\n", location);
                    } else{
                        printf("SEARCH NOT FOUND\n");
                    }
                }
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        if(choice != 5){
            printf("\nPlease enter any key to continue");
            getch();
        }

    } while (choice != 5);

    return 0;
}
