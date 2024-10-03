/*
=====================================================================================
FILE        : heapsort.h
AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
DESCRIPTION : Implementation of Heap Sort algorithm for sorting
COPYRIGHT   : 03 March 2024
=====================================================================================
*/

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void heapSort(LIST *L, int start);
void reheapUp(LIST *L, NODE *walker, int index, int start);
void reheapDown(LIST *L, NODE *last, int start);

#endif
