/*
=====================================================================================
FILE        : stack.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation file for stack operations.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
============================================================================
FUNCTION : newNode
DESCRIPTION : Creates a new node with the provided data.
ARGUMENTS : - int data: The data to be stored in the new node.
RETURNS : - struct Node*: A pointer to the newly created node.
===========================================================================
*/

struct Node *newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/*
============================================================================
FUNCTION : push
DESCRIPTION : Pushes a new node with the given data onto the top of the stack.
ARGUMENTS : - struct Node *top: Pointer to the top of the stack.
            - int data: The data to be pushed onto the stack.
RETURNS : - struct Node*: Pointer to the new top of the stack.
===========================================================================
*/

struct Node *push(struct Node *top, int data) {
    struct Node *node = newNode(data);
    node->next = top;
    return node;
}

/*
============================================================================
FUNCTION : pop
DESCRIPTION : Pops the top element from the stack.
ARGUMENTS : - struct Node *top: Pointer to the top of the stack.
            - int *popped: Pointer to store the popped value.
RETURNS : -top: Pointer to the new top of the stack after popping.
===========================================================================
*/

struct Node *pop(struct Node *top, int *popped) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node *temp = top;
    *popped = temp->data;
    top = top->next;
    free(temp);
    return top;
}

