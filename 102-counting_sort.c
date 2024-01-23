#include "sort.h"

/**
 * get_max - function Gets the maximum value in an array of integers.
 * @array: (array of integers)
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
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
 * counting_sort - function sorts an array of ints in ascending order
 *                 using the counting sort algorithm.
 * @array: (array of integers)
 * @size: (variable)The size of the array.
 *
 * Description: function prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *countvarble, *sortedvarble, maxvarble, ivarble;

	if (array == NULL || size < 2)
		return;

	sortedvarble = malloc(sizeof(int) * size);
	if (sortedvarble == NULL)
		return;
	maxvarble = get_max(array, size);
	countvarble = malloc(sizeof(int) * (maxvarble + 1));
	if (countvarble == NULL)
	{
		free(sortedvarble);
		return;
	}

	for (ivarble = 0; ivarble < (maxvarble + 1); ivarble++)
		countvarble[ivarble] = 0;
	for (ivarble = 0; ivarble < (int)size; ivarble++)
		countvarble[array[ivarble]] += 1;
	for (ivarble = 0; ivarble < (maxvarble + 1); ivarble++)
		countvarble[ivarble] += countvarble[ivarble - 1];
	print_array(countvarble, maxvarble + 1);

	for (ivarble = 0; ivarble < (int)size; ivarble++)
	{
		sorted[countvarble[array[ivarble]] - 1] = array[ivarble];
		count[array[ivarble]] -= 1;
	}

	for (ivarble = 0; ivarble < (int)size; ivarble++)
		array[ivarble] = sorted[ivarble];

	free(sortedvarble);
	free(countvarble);
}
