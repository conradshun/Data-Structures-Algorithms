/*
=====================================================================================
FILE        : b-tree.h
AUTHOR      : Conrad Nestor Mativo, Justin Catalan, Lorenz Soriano, Jack Pollo
DESCRIPTION : Header file for b-tree
COPYRIGHT   : 14 May 2024
=====================================================================================
*/
#ifndef B-TREE_H
#define B-TREE_H

#define MAX 3
#define MIN 2

struct BTreeNode {
    int item[MAX + 1], count;
    struct BTreeNode *linker[MAX + 1];
};

struct BTreeNode *root;

void printMenu();
struct BTreeNode *createNode(int item, struct BTreeNode *child);
void addValToNode(int item, int pos, struct BTreeNode *node, struct BTreeNode *child);
void splitNode(int item, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode);
int setValueInNode(int item, int *pval, struct BTreeNode *node, struct BTreeNode **child);
void insertion(int item);
void copySuccessor(struct BTreeNode *n, int pos);
void removeVal(struct BTreeNode *n, int pos);
void rightShift(struct BTreeNode *n, int pos);
void leftShift(struct BTreeNode *n, int pos);
void mergeNodes(struct BTreeNode *n, int pos);
void adjustNode(struct BTreeNode *n, int pos);
int delValFromNode(int item, struct BTreeNode *n);
void deleteNode(int item, struct BTreeNode *n);
void searching(int item, int *pos, struct BTreeNode *n);
void inorderTraversal(struct BTreeNode *node);
void display();

#endif
