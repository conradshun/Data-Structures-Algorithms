/*
============================================================================
FILE        : sLLheader.h
AUTHOR      : Conrad Nestor B. Mativo
DESCRIPTION : A header file that contains the structures and function prototypes
COPYRIGHT   : 05 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/
#ifndef sLLheader_H
#define sLLheader_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    int count;
    struct node *head, *tail;
};

void initializeList(struct list *L);
void insertFront(struct list *L, int new_data);
void insertRear(struct list *L, int new_data);
void insertAt(struct list *L, int new_data, int position);
void deleteFront(struct list *L);
void deleteRear(struct list *L);
void deleteAt(struct list *L, int position);
void displayAll(struct list *L);

#endif // sLLheader_H
