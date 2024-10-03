/*
============================================================================
FILE        : mativoCo_HE4_ExpTree.c
AUTHOR      : Conrad Nestor B. Mativo
DESCRIPTION : A program that implement an Expression Tree from Infix expression and Display Prefix and Postfix evaluation expression.
COPYRIGHT   : 2 April 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MOVE_UP(x) printf("\e[%dA", x)
#define MOVE_DOWN(x) printf("\e[%dB", x)

/*
============================================================================
FUNCTION    : expTree
DESCRIPTION : function to create tree node
ARGUMENTS   : none
RETURNS     : none
============================================================================
*/
struct exptree {
    char data;
    struct exptree *left;
    struct exptree *right;
};

/*
============================================================================
FUNCTION    : expTree
DESCRIPTION : function to create new node
ARGUMENTS   : char data - new  data
RETURNS     : int temp - returns temporary data
============================================================================
*/
struct exptree *getnode(char data) {
    struct exptree *temp = (struct exptree *)malloc(sizeof(struct exptree));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

/*
============================================================================
FUNCTION    : isOperator
DESCRIPTION : check if it is an operator
ARGUMENTS   : char c - c to be compared
RETURNS     : int - (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
============================================================================
*/
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
/*
============================================================================
FUNCTION    : precedence
DESCRIPTION : check if op is equal to any operator
ARGUMENTS   : char op - operations to be compared
RETURNS     : int - (op == '^'), (op == '*' || op == '/'), (op == '+' || op == '-')
============================================================================
*/
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
/*
============================================================================
FUNCTION    : exptree *createExpTree
DESCRIPTION : to construct expression tree from infix expression
ARGUMENTS   : char exp[20] -
RETURNS     : int treest - makes an expression tree
============================================================================
*/
struct exptree *createExpTree(char exp[20]) {
    struct exptree *operst[10], *treest[10];
    int top1 = -1, top2 = -1;
    struct exptree *temp, *t1, *t2, *t3;
    char symbol;
    int i;
    for (i = 0; i < strlen(exp); i++) {
        symbol = exp[i];
        if (isalnum(symbol)) {
            temp = getnode(symbol);
            treest[++top2] = temp;
        } else {
            temp = getnode(symbol);
            if (symbol == '(') {
                operst[++top1] = temp;
            } else if (top1 == -1 || precedence(operst[top1]->data) < precedence(symbol)) {
                operst[++top1] = temp;
            } else if (symbol == ')') {
                while (operst[top1]->data != '(' && top1 != -1 && top2 != -1 && precedence(operst[top1]->data) >= precedence(symbol)) {
                    t3 = operst[top1--];
                    t1 = treest[top2--];
                    t2 = treest[top2--];
                    t3->right = t1;
                    t3->left = t2;
                    treest[++top2] = t3;
                }
                if (operst[top1]->data == '(')
                    top1--;
            } else {
                while (top1 != -1 && top2 != -1 && precedence(operst[top1]->data) >= precedence(symbol)) {
                    t3 = operst[top1--];
                    t1 = treest[top2--];
                    t2 = treest[top2--];
                    t3->right = t1;
                    t3->left = t2;
                    treest[++top2] = t3;
                }
                operst[++top1] = temp;
            }
        }
    }
    while (top1 != -1) {
        t3 = operst[top1--];
        t1 = treest[top2--];
        t2 = treest[top2--];
        t3->right = t1;
        t3->left = t2;
        treest[++top2] = t3;
    }
    return treest[top2];
}

/*
============================================================================
FUNCTION    : NODE
DESCRIPTION : structure for node in expression tree
ARGUMENTS   : none
RETURNS     : none
============================================================================
*/
struct NODE {
    char x;
    struct NODE *left, *right;
};
/*
============================================================================
FUNCTION    : NODE* createNode
DESCRIPTION : Function to create a new node
ARGUMENTS   : char x - data
RETURNS     : temp - temporary data
============================================================================
*/

struct NODE* createNode(char x) {
    struct NODE* temp = (struct NODE*)malloc(sizeof(struct NODE));
    temp->x = x;
    temp->left = temp->right = NULL;
    return temp;
}
/*
============================================================================
FUNCTION    : treeDepth
DESCRIPTION : Function to calculate the depth of the expression tree
ARGUMENTS   : struct exptree* root, int depth
RETURNS     : int - (dLeft > dRight) ? dLeft : dRight
============================================================================
*/
int treeDepth(struct exptree* root, int depth) {
    if (!root) return depth - 1;

    int dLeft = treeDepth(root->left, depth + 1);
    int dRight = treeDepth(root->right, depth + 1);

    return (dLeft > dRight) ? dLeft : dRight;
}
/*
============================================================================
FUNCTION    : treeDisplay
DESCRIPTION : Function to display the expression tree
ARGUMENTS   : struct exptree* root, int depth
RETURNS     : void - none
============================================================================
*/
void treeDisplay(struct exptree* root, int depth) {
    if (!root) return;

    treeDisplay(root->left, depth + 1);
    MOVE_DOWN(depth);
    printf("[%3c],%d", root->data, depth);
    MOVE_UP(depth);
    treeDisplay(root->right, depth + 1);
}
/*
============================================================================
FUNCTION    : treeMode
DESCRIPTION : Function to print the expression tree horizontally
ARGUMENTS   : struct exptree* root
RETURNS     : void - none
============================================================================
*/
void treeMode(struct exptree* root) {
    if (!root) return;

    int maxDepth = treeDepth(root, 1);

    for (int i = 0; i < maxDepth; i++) printf("\n");
    MOVE_UP(maxDepth);
    treeDisplay(root, 1);
    MOVE_DOWN(maxDepth);
    printf("\n");

}
/*
============================================================================
FUNCTION    : breadthFirstTraversal
DESCRIPTION : Function to perform breadth-first traversal
ARGUMENTS   : struct exptree* root
RETURNS     : void - none
============================================================================
*/
void breadthFirstTraversal(struct exptree* root) {
    if (root == NULL)
        return;

    struct exptree* queue[100]; // Assuming a maximum of 100 nodes for simplicity
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct exptree* current = queue[front++];
        printf("%c ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}
/*
============================================================================
FUNCTION    : inorderTraversal
DESCRIPTION : Function to traverse the binary tree in Inorder
ARGUMENTS   : struct exptree* root
RETURNS     : void - none
============================================================================
*/
void inorderTraversal(struct exptree* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}
/*
============================================================================
FUNCTION    : preorderTraversal
DESCRIPTION : Function to traverse the binary tree in Preorder
ARGUMENTS   : struct exptree* root
RETURNS     : void - none
============================================================================
*/
void preorderTraversal(struct exptree* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
/*
============================================================================
FUNCTION    : postorderTraversal
DESCRIPTION : Function to traverse the binary tree in Postorder
ARGUMENTS   : struct exptree* root
RETURNS     : void - none
============================================================================
*/
void postorderTraversal(struct exptree* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c ", root->data);
    }
}
/*
============================================================================
FUNCTION    : int main
DESCRIPTION : Executes the main program
ARGUMENTS   : Void
RETURNS     : int - returns the exit code
============================================================================
*/
int main() {
    char expression[20];
    printf("Enter the infix expression: ");
    scanf("%[^\n]", expression); // Read the whole line including spaces

    // Construct expression tree
    struct exptree* root = createExpTree(expression);

    printf("Expression Tree (Horizontally):\n\n");
    treeMode(root);

    printf("\n=== TRAVERSE TREE ===\n");
                printf("Breadth-first: ");
                breadthFirstTraversal(root);
                printf("\nInorder Traversal: ");
                inorderTraversal(root);
                printf("\nPreorder Traversal: ");
                preorderTraversal(root);
                printf("\nPostorder Traversal: ");
                postorderTraversal(root);
    return 0;
}
