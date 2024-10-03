/*
================================================================================
File        : operations.c
Author      : Rodjean Gere, Paolo Enrera, Paul Corsino, Genesis Polotan
Description : Contains the functions that has all the menu operations
Date made   : March 3 2022
================================================================================
*/
/*
================================================================================
Header Files
================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "header.h"

/*
================================================================================
FUNCTION    : newStatistician
DESCRIPTION : Creates the list
================================================================================
*/
void newStatistician(STATISTICIAN *S)
{
    if(c != 1)
    {
        S->head = NULL;
	    S->tail = NULL;
	    S->count = 0;

	    printf("\n");printf("\t\t\t");
        printf("Creating, Please Wait...");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        printf("\n\n");printf("\t\t\t");
	    printf("Creation of new statistician is done.\n");
	    c = 1;

	    printf("\n");
	    printf("\t\t\t");printf("Going back to Main Menu...\n");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");
    }
    else
    {
        system("cls");
        printf("\t\t\t");printf("Statistician is already created.\n");
        printf("\t\t\t");printf("Going back to Main Menu...\n");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");
    }
}

/*
================================================================================
FUNCTION    : destroyStatistician
DESCRIPTION : Destroys the list
================================================================================
*/
void destroyStatistician(STATISTICIAN *S)
{
    NODE *temp;
    temp = S->head;
    int d = 0;

    if(c != 1)
    {
        printf("\n");printf("\t\t\t");
        printf("There is no list.\n");
        printf("\n");printf("\t\t\t");
        printf("Going back to Main Menu...");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");
    }
    else if(S->count == 0)
    {

    S->head = NULL;
    S->tail = NULL;
    S->count = 0;
    printf("\n");printf("\t\t\t");
    printf("Destroying, Please Wait...");
    fflush(stdout);  // Ensure message is displayed immediately
    sleep(1);
    printf("\n");printf("\t\t\t");
    printf("List is destroyed.\n");
    c = 0;
    fflush(stdout);  // Ensure message is displayed immediately
    sleep(1);
    system("cls");
    }
    else
    {
        while(d == 0)
        {
            S->tail = temp->next;
            temp->next->prev = S->head;
            S->head = NULL;
            free(temp);
            temp = NULL;
            d++;
        }
        printf("\n");printf("\t\t\t");
        printf("Destroying, Please Wait...");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        printf("\n");printf("\t\t\t");
        printf("List is destroyed.\n");
        c = 0;
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");
    }
}

/*
================================================================================
FUNCTION    : addStatistician
DESCRIPTION : Adds a node/value/element to the list
================================================================================
*/
void addStatistician(STATISTICIAN *S, int x)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));

        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->item = x;

        if(S->count == 0)
        {

            S->head = newNode;
            S->tail = newNode;
            S->count++;
        }

        else
        {

            newNode->prev = S->tail;
            S->tail->next = newNode;
            S->tail = newNode;
            S->count++;
        }

        NODE *ptr = S->head;
            while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        S->tail = ptr;
}

/*
================================================================================
FUNCTION    : removeStatistician
DESCRIPTION : Removes a node/value/element at a given position in the list
================================================================================
*/
void removeStatistician(STATISTICIAN *S, int p)
{
    int i = 1;

    NODE *temp;

    temp = S->head;

    if(p < 0 || p > S->count)
    {
        printf("\n");printf("\t\t\t");
        printf("Invalid Position\n");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");

    }
        else if(p == 0 && p == S->count)
        {

            S->head = NULL;
            S->tail = NULL;
            S->count = 1;
            c = 1;
        }
        else if(p == 1)
        {

            removeFront(S);
        }
        else if(p == S->count)
        {

            removeRear(S);
        }
        else{

            while(i < p)
            {
                temp = temp->next;
                i++;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            S->count--;
        }
}

/*
================================================================================
FUNCTION    : removeFront
DESCRIPTION : Removes the node/value/element at the front of the list
================================================================================
*/
void removeFront(STATISTICIAN *S)
{

	NODE *ptr = S->head;
	S->head = ptr->next;
	free(ptr);
	S->head->prev = NULL;
	S->count--;

}

/*
================================================================================
FUNCTION    : removeRear
DESCRIPTION : Removes the node/value/element at the back of the list
================================================================================
*/
void removeRear(STATISTICIAN *S)
{

	NODE *ptr = S->tail;
	S->tail = ptr->prev;
	free(ptr);
	S->tail->next = NULL;
	S->count--;

}

/*
================================================================================
FUNCTION    : displayData
DESCRIPTION : Displays the list
================================================================================
*/
void displayData(NODE *h)
{

		while(h != NULL)
		{
			printf("%d ",h->item);
			h = h->next;
		}

	printf("\n");
}
