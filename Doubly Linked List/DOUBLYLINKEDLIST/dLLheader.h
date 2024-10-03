/*
============================================================================
FILE        : dLLheader.h
AUTHOR      : Conrad Nestor B. Mativo
DESCRIPTION : A header file that contains the structures and function prototypes
COPYRIGHT   : 05 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/
#ifndef dLLheader_HH
#define dLLheader_HH

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct list {
    int count;
};
//Function prototypes
struct node* createNode(int data);
void insertFront(int data);
void insertRear(int data);
void insertAt(int data, int position);
void removeFront();
void removeRear();
void removeAt(int position);
void printList();
void printMirror();

#endif // dLLheader_H
