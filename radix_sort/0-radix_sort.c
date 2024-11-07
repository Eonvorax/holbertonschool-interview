#include "sort.h"

/**
 *
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
 *
 */
void lsd_count_sort(int *array, size_t size, int lsd)
{
    int output[size];       // Output array
    int count[10] = {0}; // Initialize count array as 0
    size_t i;

    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[(array[i] / lsd) % 10]++;

    // Change count[i] so that count[i] now
    // contains actual position of this digit
    // in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = size; i > 0; i--)
    {
        output[count[(array[i] / lsd) % 10] - 1] = array[i];
        count[(array[i] / lsd) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
}

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: the array to sort
 * @size: the length of the given array to sort
 *
 */
void radix_sort(int *array, size_t size)
{
    size_t lsd;

    if (size < 2)
        return;

    int max = get_max(array, size);

    for (lsd = 1; max / lsd > 0; lsd *= 10)
    {
        lsd_count_sort(array, size, lsd);
    }
}
