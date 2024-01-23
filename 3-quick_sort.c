#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - function swaps two ints in an array.
 * @a: (array variable)first integer to swap.
 * @b: (array variable)The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpvrble;

	tmpvrble = *a;
	*a = *b;
	*b = tmpvrble;
}

/**
 * lomuto_partition - function orders subset of an array of ints according to
 *                    the lomuto partition scheme (the last element as pivot).
 * @array: (array of integers)
 * @size: (variable)size of the array.
 * @left: (int variable)index of the subset to order.
 * @right: (int variable)ending index of the subset to order.
 *
 * Return: returns the final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivotvrble, abovevrble, belowvrble;

	pivotvrble = array + right;
	for (abovevrble = belowvrble = left; belowvrble < right; belowvrble++)
	{
		if (array[belowvrble] < *pivotvrble)
		{
			if (abovevrble < belowvrble)
			{
				swap_ints(array + belowvrble, array + abovevrble);
				print_array(array, size);
			}
			abovevrble++;
		}
	}

	if (array[abovevrble] > *pivotvrble)
	{
		swap_ints(array + abovevrble, pivotvrble);
		print_array(array, size);
	}

	return (abovevrble);
}

/**
 * lomuto_sort - function implements the quicksort
 * algorithm through recursion.
 * @array: (array of integers) to sort.
 * @size: (variable)size of the array.
 * @left: (int variable)starting index of the array partition to order.
 * @right: (int variable)ending index of the array partition to order.
 *
 * Description: this function uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partvrble;

	if (right - left > 0)
	{
		partvrble = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partvrble - 1);
		lomuto_sort(array, size, partvrble + 1, right);
	}
}

/**
 * quick_sort - function sorts an array of ints in ascending
 *              order using the quicksort algorithm.
 * @array: (array of integers)
 * @size: (variable)size of the array.
 *
 * Description: this basicaly uses the Lomuto partition scheme and
 * prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
