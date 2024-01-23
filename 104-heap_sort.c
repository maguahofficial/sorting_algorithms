#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - function swaps two integers in an array.
 * @a: (int array)first integer to swap.
 * @b: (int array)The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpvrble;

	tmpvrble = *a;
	*a = *b;
	*b = tmpvrble;
}

/**
 * max_heapify - function turns a binary tree into a complete binary heap.
 * @array: (array of integers) representing a binary tree.
 * @size: size of array/tree.
 * @base: index of base row of the tree.
 * @root: root node of binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t leftvrble, rightvrble, largevrble;

	leftvrble = 2 * root + 1;
	rightvrble = 2 * root + 2;
	largevrble = root;

	if (leftvrble < base && array[leftvrble] > array[largevrble])
		largevrble = leftvrble;
	if (rightvrble < base && array[rightvrble] > array[largevrble])
		largevrble = rightvrble;

	if (largevrble != root)
	{
		swap_ints(array + root, array + largevrble);
		print_array(array, size);
		max_heapify(array, size, base, largevrble);
	}
}

/**
 * heap_sort - (function) sorts an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: (array of integers.)
 * @size: size of the array.
 *
 * Description: function implements the sift-down heap sort
 * algorithm. algorithm prints array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int ivrble;

	if (array == NULL || size < 2)
		return;

	for (ivrble = (size / 2) - 1; ivrble >= 0; ivrble--)
		max_heapify(array, size, size, ivrble);

	for (ivrble = size - 1; ivrble > 0; ivrble--)
	{
		swap_ints(array, array + ivrble);
		print_array(array, size);
		max_heapify(array, size, ivrble, 0);
	}
}
