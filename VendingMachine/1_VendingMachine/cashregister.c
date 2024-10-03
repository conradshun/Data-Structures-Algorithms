/*
============================================================================
FILE        : cashregister.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Program that displays the current balance and accepts money
COPYRIGHT   : 02 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/

#include "cashregister.h"
#include "vending.h"
#include "dispenser.h"

/*
============================================================================
FUNCTION    : currentBalance
DESCRIPTION : calculates the amount left needed to be paid
ARGUMENTS   : int balance - remaining amount
			  int payment - amount paid
RETURNS     : int - exit code
============================================================================
*/

int currentBalance(int balance, int payment)
{
    return balance - payment;
}

/*
============================================================================
FUNCTION    : acceptMoney
DESCRIPTION : accepts money from the user and dispenses the product
(and change if payment is higher than cost)
ARGUMENTS   : int choice - chosen product of user
			  int quantity - amount of products chosen by user
			  Product *products - pointer for the structure array
			  int balance - remaining amount
			  int payment - amount paid
RETURNS     : void
============================================================================
*/

void acceptMoney(int selectedProduct, int quantity, Product *products, int balance, int payment)
{
    if (payment > balance)
    {
        for (int i = 0; i < quantity; i++)
        {
            products->pcs--;
        }
        printf("Success!\nYour change is: %d pesos", payment - balance);
        printf("\nPlease claim your item from the dispenser\n\n");
        getch();
        return;
    }
    for (int i = 0; i < quantity; i++)
    {
        products->pcs--;
    }
    printf("Success!");
    printf("\nPlease claim your item from the dispenser\n\n");
    getch();
    return;
}
