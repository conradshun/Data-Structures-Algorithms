/*
================================================================================
File        : header.h
Author      : Genesis Polotan
Description : The header file for all the functions
Date made   : February 12 2024
================================================================================
*/
/*
================================================================================
Header Files
================================================================================
*/
#ifndef HEADER_H
#define HEADER_H

/*
================================================================================
Data Structures
================================================================================
*/
typedef struct node{
    int item;
    struct node *prev, *next;
}NODE;

typedef struct statistician{
    int count;
    struct node *head, *tail;
}STATISTICIAN;

/*
================================================================================
Global Variables
================================================================================
*/
int c;

/*
================================================================================
Header Files
================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*


/*
================================================================================
Function Prototypes
================================================================================
*/
void menu();
void newStatistician(STATISTICIAN *S);
void destroyStatistician(STATISTICIAN *S);
void addStatistician(STATISTICIAN *S, int x);
void removeStatistician(STATISTICIAN *S, int p);
void removeFront(STATISTICIAN *S);
void removeRear(STATISTICIAN *S);
void displayData(NODE *h);
int minimum(NODE *h);
int maximum(NODE *h);
int range(NODE *h);
float mean(STATISTICIAN *S);
float mode(STATISTICIAN *S);
float median(STATISTICIAN *S);
float variance(STATISTICIAN *S);
float standardDeviation(STATISTICIAN *S);


#endif
