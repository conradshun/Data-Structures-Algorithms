/*
=====================================================================================
FILE        : list.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation of list operations including display, creation,
              insertion at the end, and destruction
COPYRIGHT   : 03 March 2024
=====================================================================================
*/

#ifndef LIST_H
#define LIST_H

typedef struct node {
    int x;
    int i;
    struct node *n;
    struct node *p;
} NODE;

typedef struct list {
    struct node *head;
    struct node *tail;
    int count;
} LIST;

void displayList(LIST *L);
void createList(LIST *L, int *start);
void insertEnd(LIST *L, int data);
void destroyList(LIST *L);

#endif
