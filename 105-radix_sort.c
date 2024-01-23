#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - function Get the maximum value in an array of integers.
 * @array: (array of integers)
 * @size: (variable)The size of the array.
 *
 * Return: retuns maximum ints in the array.
 */
int get_max(int *array, int size)
{
	int maxvarble, ivarble;

	for (maxvarble = array[0], ivarble = 1; ivarble < size; ivarble++)
	{
		if (array[ivarble] > maxvarble)
			maxvarble = array[ivarble];
	}

	return (maxvarble);
}

/**
 * radix_counting_sort - function sorts significant digits of an array of ints
 *                       in ascending order using the counting sort algorithm.
 * @array: (array of integers).
 * @size: (variable)size of the array.
 * @sig: (int varible)significant digit to sort on.
 * @buff: (int array) buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int countvarble[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t ivarble;

	for (ivarble = 0; ivarble < size; ivarble++)
		countvarble[(array[ivarble] / sig) % 10] += 1;

	for (ivarble = 0; ivarble < 10; ivarble++)
		countvarble[ivarble] += countvarble[ivarble - 1];

	for (ivarble = size - 1; (int)ivarble >= 0; ivarble--)
	{
		buff[countvarble[(array[ivarble] / sig) % 10] - 1] = array[ivarble];
		countvarble[(array[ivarble] / sig) % 10] -= 1;
	}

	for (ivarble = 0; ivarble < size; ivarble++)
		array[ivarble] = buff[ivarble];
}

/**
 * radix_sort - function sorts arrays of ints in ascending
 *              order using the radix sort algorithm.
 * @array: (array of integers)
 * @size: (variable)size of the array.
 *
 * Description: function implements the LSD radix sort algorithm
 * and prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maxvarble, sigvarble, *buffvarble;

	if (array == NULL || size < 2)
		return;

	buffvarble = malloc(sizeof(int) * size);
	if (buffvarble == NULL)
		return;

	maxvarble = get_max(array, size);
	for (sigvarble = 1; maxvarble / sigvarble > 0; sigvarble *= 10)
	{
		radix_counting_sort(array, size, sigvarble, buffvarble);
		print_array(array, size);
	}

	free(buffvarble);
}
