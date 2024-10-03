/*
=====================================================================================
FILE        : singly.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Header file for singly linked list and queue data structures.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#ifndef SINGLY_H
#define SINGLY_H

typedef struct Queue Queue;

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *createNode(char data);
int getStringLength(Queue *queue);

#endif // SINGLY_H
