/*
=====================================================================================
FILE        : stack.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Header file for stack data structure.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int data);
struct Node *push(struct Node *top, int data);
struct Node *pop(struct Node *top, int *popped);

#endif // STACK_H

