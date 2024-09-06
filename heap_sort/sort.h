#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>


void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void swap(int *a, int *b);
void heapify(int *array, size_t size, size_t i, size_t full_size);

#endif
