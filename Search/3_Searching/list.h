/*
============================================================================
 FILE        : list.h
 AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
 DESCRIPTION : Header file for list.c functions and structures.
 COPYRIGHT   : 26 February 2024
============================================================================
*/

#ifndef LIST_H
#define LIST_H

typedef struct node {
    int data;
    struct node *prev, *next;
} NODE;

typedef struct {
    NODE *head, *tail;
} LIST;

LIST *createList();
void displayList(LIST *data);

#endif
