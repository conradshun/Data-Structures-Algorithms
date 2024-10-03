/*
============================================================================
FILE        : vending.c
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Program that displays the items and make a selection and sells products
COPYRIGHT   : 02 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/

#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

/*
============================================================================
FUNCTION    : showSelection
DESCRIPTION : Displays the selection of products
ARGUMENTS   : Produtc products [4] - The four products offered in the vending machine
RETURNS     : void - none
============================================================================
*/

void showSelection(Product products[4])
{
    printf("\n*** Welcome to Snack Shop ***\n");
    printf("To select an item, enter\n\n");
    printf("Products\tCost\t\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d for %s\t[Php %d]\n", i + 1, products[i].name, products[i].cost);
    }
    printf("5 to Exit\n");
    return;
}

/*
============================================================================
FUNCTION    : sellProduct
DESCRIPTION : Sells the products to the user and allows them to select the quantity, choice and compare the quantity bought if stock is still available
ARGUMENTS   : Product products [4] - The four products offered in the vending machine
RETURNS     : void - none
============================================================================
*/

void sellProduct(Product products[4])
{
    int selectedProduct, quantity, checkStock;
    showSelection(products);
    do
    {
        printf("\nPlease select an option: ");
        scanf("%d", &selectedProduct);
        if(selectedProduct == 5)
        {
            printf("Thank you for checking out!");
            getch();
            exit(0);
        }
        if(selectedProduct > 5)
        {
            printf("Invalid choice, please try again\n\n");
            getch();
            return;
        }
    }while(selectedProduct > 5);
    selectedProduct = selectedProduct - 1;
    checkStock = getCount(selectedProduct, &products[selectedProduct]);
    if(checkStock == 0)
    {
        printf("Sorry, there is not enough stock of this product\n\n");
        getch();
        system("cls");
    }
    printf("\nHow many?: ");
    scanf("%d", &quantity);
    int count = getCount(selectedProduct, &products[selectedProduct]);
    if(quantity <= count)
    {
        makeSale(selectedProduct, quantity, products);
    }
    else if(quantity > count)

    {
        printf("Sorry, there is not enough stock of this product\n\n");
        getch();
        system("cls");
    }
    getch();
    system("cls");
}

/*
============================================================================
FUNCTION    : showQuantity
DESCRIPTION : Displays the quantity of stock stored in Quantity.txt and reads it
ARGUMENTS   : Product products [4] - The four products offered in the vending machine
RETURNS     : void - none
============================================================================
*/

void showQuantity(Product products[4])
{
    FILE *fp = fopen("Quantity.txt", "r+");

    for(int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d %d\n", products[i].name, &products[i].cost, &products[i].pcs);
    }
    fclose(fp);
    return;
}

/*
============================================================================
FUNCTION    : updateQuantity
DESCRIPTION : Displays the quantity of stock stored in Quantity.txt and reads it
ARGUMENTS   : Product products [4] - The four products offered in the vending machine
RETURNS     : void - none
============================================================================
*/

void updateQuantity(Product products[4])
{
    FILE *fp = fopen("Quantity.txt", "w+");

    for(int i = 0; i < 4; i++)
    {
        fprintf(fp, "%s %d %d\n", products[i].name, products[i].cost, products[i].pcs);
    }
    fclose(fp);
    return;
}


