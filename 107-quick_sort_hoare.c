#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - fuction swaps two integers in an array.
 * @a: (int array)first integer to swap.
 * @b: (int array)second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpvrble;

	tmpvrble = *a;
	*a = *b;
	*b = tmpvrble;
}

/**
 * hoare_partition - function orders a subset of an array of ints
 *                   according to the hoare partition scheme.
 * @array: (array of integers.)
 * @size: (variable)size of the array.
 * @left: (int variable)starting index of the subset to order.
 * @right: (int variable)ending index of the subset to order.
 *
 * Return: this will return final partition index.
 *
 * Description: function uses the last element of the partition as the pivot.
 * and prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivotvarble, abovevarble, belowvarble;

	pivotvarble = array[right];
	for (abovevarble = left - 1, belowvarble = right + 1; abovevarble < belowvarble;)
	{
		do {
			abovevarble++;
		} while (array[abovevarble] < pivotvarble);
		do {
			belowvarble--;
		} while (array[belowvarble] > pivotvarble);

		if (abovevarble < belowvarble)
		{
			swap_ints(array + abovevarble, array + belowvarble);
			print_array(array, size);
		}
	}

	return (abovevarble);
}

/**
 * hoare_sort - function implements the quicksort algorithm through recursion.
 * @array: (array of integers) to sort.
 * @size: (variable)size of the array.
 * @left: (int variable)starting index of the array partition to order.
 * @right: (int variable)ending index of the array partition to order.
 *
 * Description: function uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partvarble;

	if (right - left > 0)
	{
		partvarble = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partvarble - 1);
		hoare_sort(array, size, partvarble, right);
	}
}

/**
 * quick_sort_hoare - function sort an (array of integers) in ascending
 *                    order using the quicksort algorithm.
 * @array: (An array of integers.)
 * @size: (variable)The size of the array.
 *
 * Description: function uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
