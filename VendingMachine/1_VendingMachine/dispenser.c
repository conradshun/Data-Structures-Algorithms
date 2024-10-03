/*
=====================================================================================
FILE        : dispenser.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Contains function prototypes declarations for dispenser components
COPYRIGHT   : 02 February 2024
=====================================================================================
*/

#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

/*
============================================================================
FUNCTION : getCount
DESCRIPTION : Checks and verifies the number of items in a dispenser.
ARGUMENTS : int selectedProduct: Input representing the selected product.

Product *products: Pointer to the product structure.
RETURNS : products->pcs: Returns the stock value of a given item.
===========================================================================
*/

int getCount(int selectedProduct, Product *products)
{
    return products->pcs;
}

/*
============================================================================
FUNCTION : getProductCost
DESCRIPTION : Calculates the cost of a purchase.
ARGUMENTS :
int selectedProduct: Input representing the selected product.
int quantity: Amount of the selected product.
Product *products: Pointer to the product structure.
RETURNS : cost: Returns the total cost after multiplying quantity with products[choice].cost.
===========================================================================
*/

int getProductCost(int selectedProduct, int quantity, Product *products)
{
    int cost = quantity * products->cost;
    return cost;
}

/*
============================================================================
FUNCTION : makeSale
DESCRIPTION : Prompts the user to pay the required amount, handles conditions for sufficient or insufficient payments.
ARGUMENTS :
int selectedProduct: Input representing the selected product.
int quantity: Amount of the selected product.
Product *products: Pointer to the product structure.
RETURNS : none - void
===========================================================================
*/

void makeSale(int selectedProduct, int quantity, Product *products)
{
    int totalAmount = getProductCost(selectedProduct, quantity, &products[selectedProduct]);
    int userPayment;

    printf("\nPlease insert %d pesos: ", totalAmount);
    scanf("%d", &userPayment);

    if (userPayment >= totalAmount)
    {
        acceptMoney(selectedProduct, quantity, &products[selectedProduct], totalAmount, userPayment);
        return;
    }
    else if (userPayment < totalAmount)
    {
        int additionalPayment;
        printf("\nThe amount you inserted is insufficient. Please insert more.\n");
        printf("\nInsert the remaining balance of %d pesos: ", currentBalance(totalAmount, userPayment));
        scanf("%d", &additionalPayment);
        userPayment += additionalPayment;

        if (userPayment >= totalAmount)
        {
            acceptMoney(selectedProduct, quantity, &products[selectedProduct], totalAmount, userPayment);
            return;
        }
        else if (userPayment < totalAmount)
        {
            printf("Apologies, the inserted amount is still insufficient after two attempts.\n");
            printf("Transaction Cancelled\n");
            printf("Your payment of %d pesos will be returned\n\n", userPayment);
            getch();
            return;
        }
    }
}

