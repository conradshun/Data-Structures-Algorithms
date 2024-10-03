/*
=====================================================================================
FILE        : linkedlist.h
AUTHOR      : Conrad Nestor Mativo, Justin Catalan, Lorenz Soriano, Jack Pollo
DESCRIPTION : Header file for linked list
COPYRIGHT   : 14 May 2024
=====================================================================================
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};

struct Node *head;

void insertNode(int data);
void deleteNodeFromList(int data);
int searchNode(int data);
void displayList();
void displayDepthFirst();
void displayBreadthFirst();

#endif
