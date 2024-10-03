/*
=====================================================================================
FILE        : queue.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Header file for queue data structure.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#ifndef QUEUE_H
#define QUEUE_H
#include "singly.h"

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue *initializeQueue();
void enqueue(Queue *queue, char data);
char dequeue(Queue *queue);

#endif // QUEUE_H

