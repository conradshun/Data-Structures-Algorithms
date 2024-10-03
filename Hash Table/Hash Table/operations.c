#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int HSIZE; // Hash table size
LIST *hashTable; // Hash table array

int hashFunction(int key) {
    int index = key % HSIZE;
    int probe = 0;

    // Linear probing
    while (hashTable[index].head != NULL && hashTable[index].head->data != key) {
        index = (index + 1) % HSIZE;
        probe++;
        if (probe >= HSIZE)
            return -1; // Table is full
    }

    return index;
}

void initHashTable() {
    printf("Enter the size of the hash table (1-100): ");
    scanf("%d", &HSIZE);

    if (HSIZE < 1 || HSIZE > MAX_SIZE) {
        printf("Invalid hash table size. Setting default size to 10.\n");
        HSIZE = 10;
    }

    hashTable = (LIST *)malloc(HSIZE * sizeof(LIST));
    for (int i = 0; i < HSIZE; i++) {
        hashTable[i].head = hashTable[i].tail = NULL;
        hashTable[i].count = 0;
    }
}

void insert(int data) {
    int index = hashFunction(data);
    if (index == -1) {
        printf("Hash table is full. Cannot insert %d.\n", data);
        return;
    }

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    if (hashTable[index].head == NULL)
        hashTable[index].head = hashTable[index].tail = newNode;
    else {
        hashTable[index].tail->next = newNode;
        hashTable[index].tail = newNode;
    }

    hashTable[index].count++;
}

void delete(int data) {
    int index = hashFunction(data);
    if (index == -1) {
        printf("%d not found in the hash table.\n", data);
        return;
    }

    NODE *curr = hashTable[index].head;
    NODE *prev = NULL;

    while (curr != NULL) {
        if (curr->data == data) {
            if (prev == NULL)
                hashTable[index].head = curr->next;
            else
                prev->next = curr->next;

            if (curr == hashTable[index].tail)
                hashTable[index].tail = prev;

            free(curr);
            hashTable[index].count--;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("%d not found in the hash table.\n", data);
}

void displayHashTable() {
    for (int i = 0; i < HSIZE; i++) {
        if (hashTable[i].head != NULL) {
            printf("Index %d: ", i);
            NODE *curr = hashTable[i].head;
            while (curr != NULL) {
                printf("%d ", curr->data);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

void destroyHashTable() {
    for (int i = 0; i < HSIZE; i++) {
        NODE *curr = hashTable[i].head;
        while (curr != NULL) {
            NODE *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(hashTable);
}
