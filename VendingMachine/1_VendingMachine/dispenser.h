/*
============================================================================
FILE        : dispenser.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Function prototypes of dispenser
COPYRIGHT   : 02 February 2024
REVISION HISTORY
Date: 			By: 		Description:
============================================================================
*/

#ifndef VENDING_H
#define VENDING_H

#include "dispenser.h"
#include "cashregister.h"

int getCount(int selectedProduct, Product *products);
int getProductCost(int selectedProduct, int quantity, Product *products);
void makeSale(int selectedProduct, int quantity, Product *products);


#endif

