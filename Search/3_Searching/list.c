/*
============================================================================
 FILE        : list.c
 AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
 DESCRIPTION : Functions for creating and displaying a sorted list.
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By:            Description:
 09 March 2024       Olmilla        - added doubly linked list
                                    - added bubble sort
============================================================================
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "list.h"


/*
============================================================================
 FUNCTION    : createList
 DESCRIPTION : Create a sorted list of random integers.
 ARGUMENTS   : None
 RETURNS     : Pointer to the created list
===========================================================================
*/

LIST *createList() {
    LIST *data = (LIST *)malloc(sizeof(LIST));
    data->head = NULL;
    data->tail = NULL;


    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        new_node->data = rand() % 101;
        new_node->prev = NULL;
        new_node->next = NULL;


        if (data->tail == NULL) {
            data->head = new_node;
            data->tail = new_node;
        } else {
            data->tail->next = new_node;
            new_node->prev = data->tail;
            data->tail = new_node;
        }
    }


    NODE *temp1;
    int swapped;
    for (int i = 0; i < 9; i++) {
        swapped = 0;
        temp1 = data->head;
        for (int j = 0; j < 9 - i; j++) {
            if (temp1->data > temp1->next->data) {
                int temp_data = temp1->data;
                temp1->data = temp1->next->data;
                temp1->next->data = temp_data;
                swapped = 1;
            }
            temp1 = temp1->next;
        }
        if (!swapped) {
            break;
        }
    }

    return data;
}

/*
============================================================================
 FUNCTION    : displayList
 DESCRIPTION : Display the elements and indices of the list.
 ARGUMENTS   : LIST *data - Pointer to the list
 RETURNS     : None
===========================================================================
*/

void displayList(LIST *data) {
    if(data == NULL){
        printf("\nList is empty. Create list first\n");
    } else{
        NODE *temp = data->head;
        printf("\nLOCATION:\n");
        int index = 0;
        while (temp != NULL) {
            printf("%4d", index);
            temp = temp->next;
            index++;
        }
        printf("\nDATA:\n");
        temp = data->head;
        while (temp != NULL) {
            printf("%4d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

}
