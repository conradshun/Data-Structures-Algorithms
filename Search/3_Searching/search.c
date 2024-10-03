/*
============================================================================
 FILE        : search.c
 AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
 DESCRIPTION : Functions for binary and linear search in a list.
 COPYRIGHT   : 26 February 2024
 REVISION HISTORY
 Date:               By:            Description:
 09 March 2024       Olmilla        - fixed the binary search
============================================================================
*/

#include <stddef.h>
#include "search.h"
#include "list.h"


/*
============================================================================
 FUNCTION    : binarySearch
 DESCRIPTION : Perform binary search on a sorted list.
 ARGUMENTS   : LIST *data - Pointer to the list
               int key - Element to search
               int *location - Pointer to store the location of the element
 RETURNS     : true if the element is found, false otherwise
===========================================================================
*/

bool binarySearch(LIST *data, int key, int *location) {
    if (data->head == NULL) {
        *location = -1;
        return false;
    }

    NODE *temp = data->head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            *location = index;
            return true;
        } else if (key < temp->data) {
            if (temp->prev == NULL) {
                *location = index;
                return false;
            }
            temp = temp->prev;
        } else {
            if (temp->next == NULL || key < temp->next->data) {
                *location = index + 1;
                return false;
            }
            temp = temp->next;
        }
        index++;
    }

    *location = -1;
    return false;
}


/*
============================================================================
 FUNCTION    : linearSearch
 DESCRIPTION : Perform linear search on a list.
 ARGUMENTS   : LIST *data - Pointer to the list
               int key - Element to search
               int *location - Pointer to store the location of the element
 RETURNS     : true if the element is found, false otherwise
===========================================================================
*/

bool linearSearch(LIST *data, int key, int *location) {
    NODE *temp = data->head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            *location = index;
            return true;
        }
        temp = temp->next;
        index++;
    }
    return false;
}
