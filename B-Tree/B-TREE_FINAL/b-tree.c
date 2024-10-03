/*
=====================================================================================
FILE        : btree.c
AUTHOR      : Conrad Nestor Mativo, Lorenz Soriano, Justine Catalan, Jack Pollo
DESCRIPTION : Implementation file for decimal to hexadecimal conversion.
COPYRIGHT   : 14 May 2024
=====================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "b-tree.h"

struct BTreeNode *root;

void printMenu() {
    printf("[1] Add nodes\n");
    printf("[2] Delete\n");
    printf("[3] Search\n");
    printf("[4] Exit\n");
}


void inorderTraversal(struct BTreeNode *node) {
    if (node) {
        for (int i = 0; i < node->count; i++) {
            inorderTraversal(node->linker[i]);
            printf("%d ", node->item[i + 1]);
        }
        inorderTraversal(node->linker[node->count]);
    }
}

void display() {
    if (root) {
        printf("B-Tree: ");
        inorderTraversal(root);
        printf("\n");
    } else {
        printf("B-Tree is empty\n");
    }
}
