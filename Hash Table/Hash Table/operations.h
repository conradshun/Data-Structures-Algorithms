#ifndef OPERATIONS_H
#define OPERATIONS_H

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} NODE;

typedef struct list {
    int count;
    NODE *head, *tail;
} LIST;

void initHashTable();
void insert(int data);
void delete(int data);
void displayHashTable();
void destroyHashTable();

#endif
