/*
================================================================================
File        : main.c
Author      : Genesis Polotan
Description : It's the main file that outputs the functions used
Date made   : February 12 2024

Team Members:
Genesis Polotan
Conrad Nestor Basas
Vaun Michael Cantos
Neil Allen Diago Bentula
================================================================================
*/

#include "header.h"

/*
================================================================================
FUNCTION    : main
DESCRIPTION : Executes the main program
================================================================================
*/

int main()
{

	int x;
	int p;
	int choice;
    int validInput = 0; // Flag to track if valid input was received

	STATISTICIAN *S = (STATISTICIAN*)malloc(sizeof(STATISTICIAN));

    while(1)
    {
        printf("\n");printf("\t\t\t");
        printf("Main Menu\n");
        printf("\n");printf("\t\t\t");
        printf("[1]Create new Statisitician");
        printf("\n");printf("\t\t\t");
        printf("[2]Destroy Statisitician");
        printf("\n");printf("\t\t\t");
        printf("[3]Add data");
        printf("\n");printf("\t\t\t");
        printf("[4]Remove data");
        printf("\n");printf("\t\t\t");
        printf("[5]Display data");
        printf("\n");printf("\t\t\t");
        printf("[6]Exit\n\n");
        printf("\t\t\t");
        printf("Enter your choice :  ");
        // Use fgets to read input as a string and check for digits
        char inputStr[10];
        if (fgets(inputStr, sizeof(inputStr), stdin) == NULL)
        {
            system("cls");
            printf("\n");printf("\t\t\t");
            printf("Error reading input.\n");
            system("cls");
            continue;
        }

        // Remove trailing newline from inputStr
        inputStr[strcspn(inputStr, "\n")] = '\0';

        // Check if inputStr contains only digits
        validInput = 1; // Assume valid input initially
        for (int i = 0; inputStr[i] != '\0'; i++)
        {
            if (!isdigit(inputStr[i]))
            {
                validInput = 0;
                break;
            }
        }

        // If input is valid, convert it to integer and proceed
        if (validInput)
        {
            choice = atoi(inputStr); // Convert string to integer
        } else
        {
            system("cls");
            printf("\n");printf("\t\t\t");
            printf("Invalid input. Please enter a number.\n");
            fflush(stdout);  // Ensure message is displayed immediately
            sleep(1);
            system("cls");
            continue; // Go back to the beginning of the loop
        }
        system("cls");

        switch(choice)
    {
        case 1:
            newStatistician(S);
            break;
        case 2:
            destroyStatistician(S);
            break;
        case 3:
            if(c != 0)
            {
                printf("\n");printf("\t\t\t");
                printf("Current data: ");
                displayData(S->head);
                printf("\n\n");printf("\t\t\t");
                printf("Enter data: ");
                scanf("%d", &x);
                addStatistician(S, x);
                system("cls");
            }

            else
            {
                printf("\n");printf("\t\t\t");
                printf("There is no list.\n");
                printf("\n");
                printf("\t\t\t");printf("Please Wait...\n");
                fflush(stdout);  // Ensure message is displayed immediately
                sleep(1);
                system("cls");
            }
            break;
        case 4:
            if(c != 0)
            {
                printf("\n");printf("\t\t\t");
                printf("Current data: ");
                displayData(S->head);
                printf("\n");printf("\t\t\t");
                printf("Enter position: ");
                scanf("%d", &p);
                removeStatistician(S, p);
                system("cls");
            }

            else
            {
                printf("\t\t\t");
                printf("There is no list.\n");
                printf("\n");
                printf("\t\t\t");printf("Please Wait...\n");
                fflush(stdout);  // Ensure message is displayed immediately
                sleep(1);
                system("cls");
            }
            break;
        case 5:
            if(c != 0)
            {
                printf("\n");printf("\t\t\t");
                printf("List: ");
                displayData(S->head);
                minimum(S->head);
                maximum(S->head);
                range(S->head);
                mean(S);
                median(S);
                mode(S);
                variance(S);
                standardDeviation(S);
            }

            else
            {
                printf("\t\t\t");
                printf("There is no list.\n");
                printf("\n");printf("\t\t\t");
                printf("Please Wait...\n");
                fflush(stdout);  // Ensure message is displayed immediately
                sleep(1);
                system("cls");
            }
            break;
        case 6:
            printf("\n\n");printf("\t\t\t");
            printf(" Goodbye \n\n\n");
            exit(0);
        }
    }
	return 0;
}

