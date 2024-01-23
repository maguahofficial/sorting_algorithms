#include "sort.h"

/**
 * swap_ints - function swaps two ints in an array.
 * @a: (array variable)first integer to swap.
 * @b: (array variable)second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpvrble;

	tmpvrble = *a;
	*a = *b;
	*b = tmpvrble;
}

/**
 * shell_sort - function sorts  arrays of ints in ascending
 *              order using the shell sort algorithm.
 * @array: (array of integers)
 * @size: (variable)size of the array.
 *
 * Description: function sses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gapvrble, ivrble, jvrble;

	if (array == NULL || size < 2)
		return;

	for (gapvrble = 1; gapvrble < (size / 3);)
		gapvrble = gapvrble * 3 + 1;

	for (; gapvrble >= 1; gapvrble /= 3)
	{
		for (ivrble = gapvrble; ivrble < size; ivrble++)
		{
			jvrble = ivrble;
			while (jvrble >= gapvrble && array[jvrble - gapvrble] > array[jvrble])
			{
				swap_ints(array + jvrble, array + (jvrble - gapvrble));
				jvrble -= gapvrble;
			}
		}
		print_array(array, size);
	}
}
