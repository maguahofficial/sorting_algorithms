#include "sort.h"

/**
 * swap_ints - function swap two int in an array.
 * @a: (variable)first integer to swap.
 * @b: (int variable)second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpvrble;

	tmpvrble = *a;
	*a = *b;
	*b = tmpvrble;
}

/**
 * bubble_sort - function sorts an array of integers in ascending order.
 * @array: (int array variable) to sort.
 * @size: (varaible)The size of the array.
 *
 * Description: function prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t ivrble, lenvrble = size;
	bool bubblyvrble = false;

	if (array == NULL || size < 2)
		return;

	while (bubblyvrble == false)
	{
		bubblyvrble = true;
		for (ivrble = 0; ivrble < lenvrble - 1; ivrble++)
		{
			if (array[ivrble] > array[ivrble + 1])
			{
				swap_ints(array + ivrble, array + ivrble + 1);
				print_array(array, size);
				bubblyvrble = false;
			}
		}
		lenvrble--;
	}
}
