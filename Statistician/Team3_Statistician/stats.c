/*
================================================================================
File        : stats.c
Author      : Genesis Polotan
Description : Contains all the functions that calculate the statistics
Date made   : February 12 2024
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
FUNCTION    : minimum
DESCRIPTION : Identifies and prints the minimum node/value/element in the list
================================================================================
*/

int minimum(NODE *h)
{

    NODE *current = h;
    int min;

    if(h == NULL)
    {

        return 0;
    }
    else {

        min = h->item;

        while(current != NULL)
        {

            if(min > current->item)
                min = current->item;
                current = current->next;
        }
        printf("\n");printf("\t\t\t");
        printf("Minimum: %d", min);
    }
}

/*
================================================================================
FUNCTION    : maximum
DESCRIPTION : Identifies and prints the maximum node/value/element in the list
================================================================================
*/
int maximum(NODE *h)
{

    NODE *current = h;
    int max;

    if(h == NULL)
    {

        return 0;
    }
    else {

        max = h->item;

        while(current != NULL)
        {

            if(current->item > max)
                max = current->item;
            current = current->next;
        }
        printf("\n");printf("\t\t\t");
        printf("Maximum: %d", max);
    }
}

/*
================================================================================
FUNCTION    : range
DESCRIPTION : Calculates and prints the range of the list
================================================================================
*/
int range(NODE *h)
{
	int min,max, range;

	NODE *minNum = h;
	NODE *maxNum = h;

    if(h == NULL)
    {
        printf("\n");printf("\t\t\t");
        printf("List is empty\n");
        printf("\n");printf("\t\t\t");
        printf("Please Wait...\n");
        fflush(stdout);  // Ensure message is displayed immediately
        sleep(1);
        system("cls");
        return 0;
    }
    else {
        min = h->item;
        max = h->item;
        while(minNum != NULL)
        {

            if(min > minNum->item)
            min = minNum->item;
            minNum = minNum->next;
        }
        while(maxNum != NULL)
        {

            if(maxNum->item>max)
            max = maxNum->item;
            maxNum = maxNum->next;
        }
	range = max-min;
	printf("\n");printf("\t\t\t");
	printf("Range: %d",range);
    }
}

/*
================================================================================
FUNCTION    : mean
DESCRIPTION : Calculates and prints the mean of the list
================================================================================
*/
float mean(STATISTICIAN *S)
{

	NODE *ptr= S->head;
	float sum=0,count=0;

	if(ptr == NULL)
    {

        return 0;
    }
    else
    {

        while(ptr!=NULL)
        {
            sum+=ptr->item;
            count++;
            ptr=ptr->next;
        }
    }
    printf("\n");printf("\t\t\t");
	printf("Mean: %.2f",sum/count);
}

/*
================================================================================
FUNCTION    : median
DESCRIPTION : Calculates and prints the median of the list
================================================================================
*/
float median(STATISTICIAN *S)
{
	NODE* ptr1 = S->head;
    NODE* ptr2 = S->head;
    NODE* prevPtr1 = S->head;

	float median = 0;

	if(ptr1 == NULL)
    {

        return 0;
    }

    if (S != NULL)
        {
        while (ptr2 != NULL && ptr2->next != NULL)
        {

            ptr2 = ptr2->next->next;
            prevPtr1 = ptr1;
            ptr1 = ptr1->next;
        }

        if (ptr2 != NULL)
        {

            median = ptr1->item;
            printf("\n");printf("\t\t\t");
            printf("Median: %.f", median);
        }

        else
        {

            median = ptr1->item+prevPtr1->item;
            printf("\n");printf("\t\t\t");
            printf("Median: %.2f",median/2);
        }
    }
}

/*
================================================================================
FUNCTION    : mode
DESCRIPTION : Identifies and prints the mode of the list
================================================================================
*/
float mode(STATISTICIAN *S)
{
    NODE* ptr = S->head;
    NODE* ptr1 = S->head;
    int i, j, n = 0;
	int count = 0, maxCount = 0, maxVal = 0;

	if(ptr == NULL)
	{

        return 0;
    }
    else
    {
        do
        {
        	n++;
        	ptr = ptr -> next;
            }while(ptr != NULL);
            int arr[n];

            for(i=0;i < n; i++)
            {
                arr[i] = ptr1 -> item;
                ptr1 = ptr1 -> next;
            }

            for(i=0;i<n;i++)
            {
                count = 0;
                for(j=0;j<n;j++)
                {
                    if(arr[i] == arr[j])
                    {
                        count++;
                    }
                }
                if (count > maxCount)
                {
                    maxCount = count;
                    maxVal = arr[i];
                }
            }

    }
    if(maxCount == 1)
    {
        printf("\n");printf("\t\t\t");
        printf("Mode: All the elements appeared exactly once");
    }
    else
    {
        printf("\n");printf("\t\t\t");
        printf("Mode: %d, appeared %d times", maxVal, count);
    }

}

/*
================================================================================
FUNCTION    : variance
DESCRIPTION : Calculates and prints the variance of the list
================================================================================
*/
float variance(STATISTICIAN *S)
{
    NODE *ptr = S->head;
    NODE *ptr1 = ptr;
	float sum = 0 ;
	float count = 0;
	float mean = 0;
	double var = 0;
	float sum1 = 0;

	if(ptr == NULL)
	{
        return 0;
    }

    else
    {
    	do
    	{
    	    sum+=ptr->item;
            count++;
    		mean = sum/count;
    		ptr=ptr->next;
    	}while(ptr != NULL);

        do
    	{
            sum1 = sum1 + pow((ptr1 -> item - mean), 2);
    		ptr1=ptr1->next;
    	}while(ptr1 != NULL);

     	var = sum1/(count- 1);
     	printf("\n");printf("\t\t\t");
    	printf("Variance: %.2f",var);
    }
}

/*
================================================================================
FUNCTION    : standardDeviation
DESCRIPTION : Calculates and prints the standard deviation of the list
================================================================================
*/
float standardDeviation(STATISTICIAN *S)
{
    NODE *ptr = S->head;
    NODE *ptr1 = ptr;
	float sum = 0 ;
	float count = 0;
	float mean = 0;
	double dev = 0;
	float sum1 = 0;

	if(ptr == NULL)
	{
        return 0;
    }

    else
    {
    	do
    	{
    	    sum+=ptr->item;
            count++;
    		mean = sum/count;
    		ptr=ptr->next;
    	}while(ptr != NULL);

        do
    	{
            sum1 = sum1 + pow((ptr1 -> item - mean), 2);
    		ptr1=ptr1->next;
    	}while(ptr1 != NULL);

     	dev = sqrt(sum1/(count- 1));
     	printf("\n");printf("\t\t\t");
    	printf("Standard Deviation: %.2f",dev);
    	printf("\n\n");printf("\t\t\t");
    	printf("Press any key to go back...");
    	getch();
    	system("cls");
    }
}
