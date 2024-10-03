/*
============================================================================
 FILE        : search.h
 AUTHOR      : Don King Ababa, Conrad Nestor Mativo, Dhan Jacob Olmilla
 DESCRIPTION : Header file for search.c functions.
 COPYRIGHT   : 26 February 2024
============================================================================
*/

#ifndef SEARCH_H
#define SEARCH_H

#include <stdbool.h>
#include "list.h"

bool binarySearch(LIST *data, int key, int *location);
bool linearSearch(LIST *data, int key, int *location);

#endif
