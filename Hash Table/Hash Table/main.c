#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main() {
    int choice, data;
    initHashTable();

    while (1) {
        printf("\nLinear Probing Closed Hashing Operations:\n");
        printf("1. Insert data\n");
        printf("2. Delete data\n");
        printf("3. Display hash table\n");
        printf("4. Destroy hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                displayHashTable();
                break;
            case 4:
                destroyHashTable();
                printf("Hash table destroyed.\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
