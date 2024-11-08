#include "sort.h"

/**
 * get_max - gets the maximum int element of an array
 * @array: array to search
 * @size: length of the array
 *
 * Return: int value of maximum element in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * lsd_count_sort - counting sort of array
 * @array: array to sort
 * @size: length of the array to sort
 * @lsd: power of 10 representing the least significant digit
 *
 */
void lsd_count_sort(int *array, size_t size, int lsd)
{
	int *output;
	int count[10] = {0};  /* Initialize counting array at 0 */
	size_t i;
	ssize_t j;

	output = malloc(size * sizeof(int));
	if (!output)
		return;

	/* Store count of occurrences in count[] */
	for (i = 0; i < size; i++)
		count[(array[i] / lsd) % 10]++;

	/* store into count[i] actual position of this digit in output[] */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / lsd) % 10] - 1] = array[j];
		count[(array[j] / lsd) % 10]--;
	}

	/* Copy the now sorted output array to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: the array to sort
 * @size: the length of the given array to sort
 *
 */
void radix_sort(int *array, size_t size)
{
	int lsd;

	if (size < 2)
		return;

	int max = get_max(array, size);

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		lsd_count_sort(array, size, lsd);
	}
}
