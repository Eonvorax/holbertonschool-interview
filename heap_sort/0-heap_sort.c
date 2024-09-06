#include <stdio.h>
#include "sort.h"

/**
 * swap - Basic function to swap the values of two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 *
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Recursively calls itself on the array/heap to sort it
 * @array: The array/subarray/heap to sort
 * @size: the size of the subarray
 * @i: the index of the root of the subtree we heapify
 * @full_size: the full size of the array, used to print it entirely
 *
 */
void heapify(int *array, size_t size, size_t i, size_t full_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	/* If left child is larger than root */
	if (left < size && array[left] > array[largest])
		largest = left;

	/* If right child is larger than largest so far */
	if (right < size && array[right] > array[largest])
		largest = right;

	/* If largest element is not the root */
	if (largest != i)
	{
		/* Swap, print the array, then recursively heapify the subtree */
		swap(&array[i], &array[largest]);
		print_array(array, full_size);
		heapify(array, size, largest, full_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: the array of ints to sort
 * @size: the size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	/* Build a max heap */
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Extract elements from the heap one by one */
	for (int i = size - 1; i > 0; i--)
	{
		/* Move current root to the end */
		swap(&array[0], &array[i]);
		print_array(array, size);
		/* Call heapify on the reduced heap*/
		heapify(array, i, 0, size);
	}
}
