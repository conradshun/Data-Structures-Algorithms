/*
============================================================================
FILE        : cashregister.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Function prototypes of cashregister
COPYRIGHT   : 02 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/

#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include "vending.h"

int currentBalance(int balance, int payment);
void acceptMoney(int selectedProduct, int quantity, Product *products, int balance, int payment);

#endif
