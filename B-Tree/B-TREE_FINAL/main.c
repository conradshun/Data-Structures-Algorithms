/*
=====================================================================================
FILE        : main.c
AUTHOR      : Conrad Nestor Mativo, Justin Catalan, Lorenz Soriano, Jack Pollo
DESCRIPTION : A self-balancing tree program that maintains sorted data and allows searches, sequential access, insertions,
COPYRIGHT   : 14 May 2024
=====================================================================================
*/
#include <stdio.h>
#include "b-tree.h"
#include "linkedlist.h"

int main() {
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("[1] Insert Node (Data)\n");
        printf("[2] Delete Node\n");
        printf("[3] Search Node\n");
        printf("[4] Display List\n");
        printf("[5] Display Depth-First Traversal\n");
        printf("[6] Display Breadth-First Traversal\n");
        printf("[7] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNodeFromList(data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchNode(data))
                    printf("Node found\n");
                else
                    printf("Node not found\n");
                break;
            case 4:
                displayList();
                break;
            case 5:
                displayDepthFirst();
                break;
            case 6:
                displayBreadthFirst();
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
