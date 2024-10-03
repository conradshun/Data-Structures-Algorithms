/*
=====================================================================================
FILE        : queue.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation file for queue data structure functions.
COPYRIGHT   : 20 March 2024
=====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/*
============================================================================
FUNCTION : initializeQueue
DESCRIPTION : Creates and initializes a new empty queue.
ARGUMENTS : None
RETURNS : -Queue*: Pointer to the newly created queue.
===========================================================================
*/

Queue *initializeQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

/*
============================================================================
FUNCTION : processWord
DESCRIPTION : Reads a word from the user, enqueues its characters, and
              displays information about the string and its corresponding queue.
ARGUMENTS : None
RETURNS : void-none
===========================================================================
*/

void processWord() {
    char str[100];
    printf("Enter a word: ");
    scanf("%s", str);

    Queue *queue = initializeQueue();

    for (int i = 0; i < strlen(str); i++) {
        enqueue(queue, str[i]);
    }

    printf("\nSTRING: %s\n", str);
    printf("QUEUE: | ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%c | ", current->data);
        current = current->next;
    }
    printf("\n");

    if (queue->front != NULL) {
        printf("QUEUE Front: %c\n", queue->front->data);
        printf("QUEUE Rear: %c\n", queue->rear->data);
    }

    int length = getStringLength(queue);
    printf("LENGTH OF STRING: %d\n", length);

    while (queue->front != NULL) {
        dequeue(queue);
    }
    free(queue);
}

/*
============================================================================
FUNCTION : enqueue
DESCRIPTION : Adds a new node with the given data to the rear of the queue.
ARGUMENTS : -Queue *queue: Pointer to the queue.
            -char data: The data to be added to the queue.
RETURNS : void-none
===========================================================================
*/

void enqueue(Queue *queue, char data) {
    Node *newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

/*
============================================================================
FUNCTION : dequeue
DESCRIPTION : Removes and returns the front node's data from the queue.
ARGUMENTS : -Queue *queue: Pointer to the queue.
RETURNS : -data: The data of the dequeued node.
===========================================================================
*/

char dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = queue->front;
    char data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

