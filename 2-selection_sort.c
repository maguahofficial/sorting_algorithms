#include "sort.h"

/**
 * swap_ints - function swaps two integers in an array.
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
 * selection_sort - function sorts an array of ints in ascending order
 *                  using selection sort algorithm.
 * @array: (array of integers)
 * @size: (variable)size of the array.
 *
 * Description: function prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minvrble;
	size_t ivrble, jvrble;

	if (array == NULL || size < 2)
		return;

	for (ivrble = 0; ivrble < size - 1; ivrble++)
	{
		minvrble = array + ivrble;
		for (jvrble = ivrble + 1; jvrble < size; jvrble++)
			minvrble = (array[jvrble] < *minvrble) ? (array + jvrble) : minvrble;

		if ((array + ivrble) != minvrble)
		{
			swap_ints(array + ivrble, minvrble);
			print_array(array, size);
		}
	}
}
