/*
================================================================================
FILE        : HE3_Recursion.c
AUTHOR      : Conrad Nestor B. Mativo
DESCRIPTION : A file that stores the functions
COPYRIGHT   : 19 February 2023
REVISION HISTORY
Date: 				By: 		Description:
================================================================================
*/
#include <stdio.h>

//function prototypes
int factorial_non_recursive(int n);
int factorial_recursive(int n);
int fibonacci_non_recursive(int n);
int fibonacci_recursive(int n);
int sum_non_recursive(int n);
int sum_recursive(int n);
/*
================================================================================
FUNCTION    : factorial_non_recursive
DESCRIPTION : function that calculates the factorial in non-recursive
ARGUMENTS   : int n - number inputted
RETURNS     : product - product of the factorial
================================================================================
*/
int factorial_non_recursive(int n) {
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1;
    }

    int product = 1;
    printf("   ");
    for (int i = 1; i <= n; i++) {
        printf("%-5d", i);
        product *= i;
        if (i < n) {
            printf(" * ");
        } else {
            printf(" = ");
        }
    }
    printf("%d\n", product);
    return product;
}
/*
================================================================================
FUNCTION    : factorial_recursive
DESCRIPTION : function that calculates the factorial in recursive
ARGUMENTS   : int n - number inputted
RETURNS     : result - result of the factorial
================================================================================
*/
int factorial_recursive(int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1;
    } else {
        int result = factorial_recursive(n - 1) * n;
        printf("   %-5d * %d = %d\n", n, n - 1, result);
        return result;
    }
}
/*
================================================================================
FUNCTION    : fibonacci_non_recursive
DESCRIPTION : function that calculates the fibonacci sequence in non-recursive
ARGUMENTS   : int n - number inputted
RETURNS     : c - the fibonacci sequence
================================================================================
*/
int fibonacci_non_recursive(int n) {
    if (n < 0) {
        printf("Error: Fibonacci sequence is not defined for negative numbers.\n");
        return -1;
    }

    int a = 0, b = 1, c;
    printf("   ");
    for (int i = 1; i <= n; i++) {
        c = a + b;
        printf("%-5d", c);
        a = b;
        b = c;
        if (i < n) {
            printf(", ");
        }
    }
    printf("\n");
    return c;
}
/*
================================================================================
FUNCTION    : fibonacci_recursive
DESCRIPTION : function that calculates the fibonacci sequence in recursive
ARGUMENTS   : int n - number inputted
RETURNS     : result - the fibonacci sequence
================================================================================
*/
int fibonacci_recursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int first = fibonacci_recursive(n - 1);
        int second = fibonacci_recursive(n - 2);
        int result = first + second;
        printf("   %-5d + %-5d = %-5d\n", first, second, result);
        return result;
    }
}
/*
================================================================================
FUNCTION    : sum_non_recursive
DESCRIPTION : function that calculates sum in non-recursive
ARGUMENTS   : int n - number inputted
RETURNS     : sum - summation of numbers
================================================================================
*/
int sum_non_recursive(int n) {
    if (n < 0) {
        printf("Error: Summation is not defined for negative numbers.\n");
        return -1;
    }

    int sum = 0;
    printf("   ");
    for (int i = 1; i <= n; i++) {
        sum += i;
        printf("%-5d", i);
        if (i < n) {
            printf(" + ");
        } else {
            printf(" = ");
        }
    }
    printf("%d\n", sum);
    return sum;
}
/*
================================================================================
FUNCTION    : sum_recursive
DESCRIPTION : function that calculates the calculates sum in non-recursive
ARGUMENTS   : int n - number inputted
RETURNS     : result - summation of the numbers
================================================================================
*/
int sum_recursive(int n) {
    if (n == 0) {
        return 0;
    } else {
        int result = sum_recursive(n - 1) + n;
        printf("   %-5d + %d = %d\n", n - 1, n, result);
        return result;
    }
}
