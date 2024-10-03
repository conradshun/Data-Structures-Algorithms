/*
=====================================================================================
FILE        : singly.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation file for singly linked list functions.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "singly.h"
#include "queue.h"

/*
============================================================================
FUNCTION : createNode
DESCRIPTION : Creates a new node with the provided data.
ARGUMENTS : -char data: The data to be stored in the new node.
RETURNS : -Node*: A pointer to the newly created node.
===========================================================================
*/

Node *createNode(char data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

/*
============================================================================
FUNCTION : getStringLength
DESCRIPTION : Calculates the length of a string stored in a queue.
ARGUMENTS : -Queue* queue: Pointer to the queue containing the string.
RETURNS : -length: The length of the string.
===========================================================================
*/

int getStringLength(Queue* queue) {
    int length = 0;
    while (queue->front != NULL) {
        dequeue(queue);
        length++;
    }
    return length;
}
