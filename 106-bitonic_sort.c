#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - function sorts  bitonic sequence inside an array of ints.
 * @array: (array of integers)
 * @size: (variable)size of the array.
 * @start: (variable) starting index of the sequence in array to sort.
 * @seq: (variable) size of the sequence to sort.
 * @flow: (variable) direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t ivrble, jumpvrble = seq / 2;

	if (seq > 1)
	{
		for (ivrble = start; ivrble < start + jumpvrble; ivrble++)
		{
			if ((flow == UP && array[ivrble] > array[ivrble + jumpvrble]) ||
			    (flow == DOWN && array[ivrble] < array[ivrble + jumpvrble]))
				swap_ints(array + ivrble, array + ivrble + jumpvrble);
		}
		bitonic_merge(array, size, start, jumpvrble, flow);
		bitonic_merge(array, size, start + jumpvrble, jumpvrble, flow);
	}
}

/**
 * bitonic_seq - function converts an array of ints into a bitonic sequence.
 * @array: (array of ints)
 * @size: (array variable)size of the array.
 * @start: (variable)starting the index of a block of the building bitonic sequence.
 * @seq: (variable) size of a block of building bitonic sequence.
 * @flow: (variable)direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cutvrble = seq / 2;
	char *strvrble = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, strvrble);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cutvrble, UP);
		bitonic_seq(array, size, start + cutvrble, cutvrble, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, strvrble);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - function sorts array of ints in ascending
 *                order using the bitonic sort algorithm.
 * @array: (array of integers)
 * @size: (variable)size of the array.
 *
 * Description: function prints the array after each swap and
 * only works for size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
