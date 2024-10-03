#include <stdio.h>
#include "vending.h"
#include "dispenser.h"
#include "cashregister.h"

void displayMainMenu();
void displayInventory(Product products[4]);

int main()
{
    Product products[4] =
    {
        {"Candy", 10, 100},
        {"Chips", 15, 100},
        {"Cookies", 15, 100},
        {"Soda", 25, 100}
    };

    showQuantity(products);

    char choice;

    do
    {
        displayMainMenu();
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'B':
        case 'b':
            sellProduct(products);
            updateQuantity(products);
            break;

        case 'S':
        case 's':
            displayInventory(products);
            break;

        case 'E':
        case 'e':
            printf("Exiting the program. Thank you!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != 'E' && choice != 'e');

    return 0;
}

void displayMainMenu()
{
    printf("\n=== Main Menu ===\n");
    printf("[B] BUY\n");
    printf("[S] INVENTORY\n");
    printf("[E] EXIT\n");
}

void displayInventory(Product products[4])
{
    printf("\nCurrent Inventory:\n\n");
    printf("Products\tCost\t\tQuantity\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s\t\t[Php %d]\t%d\n", products[i].name, products[i].cost, products[i].pcs);
    }
    printf("\nPlease enter any key to continue ");
    getch();
    system("cls");
}
