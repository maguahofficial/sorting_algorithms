#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - function sorts a subarray of ints.
 * @subarr: (array variable)an array of integers to sort.
 * @buff: (array variable)to store the sorted subarray.
 * @front: (variable)front index of the array.
 * @mid: (variable)The middle index of the array.
 * @back: (variable)The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t ivrble, jvrble, kvrble = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (ivrble = front, jvrble = mid; ivrble < mid && jvrble < back; kvrble++)
		buff[kvrble] = (subarr[ivrble] < subarr[jvrble]) ? subarr[ivrble++] : subarr[jvrble++];
	for (; ivrble < mid; ivrble++)
		buff[kvrble++] = subarr[ivrble];
	for (; jvrble < back; jvrble++)
		buff[kvrble++] = subarr[jvrble];
	for (ivrble = front, kvrble = 0; ivrble < back; ivrble++)
		subarr[ivrble] = buff[kvrble++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - function implements the merge sort algorithm
 * through recursion.
 * @subarr: (array variable) of integers to sort.
 * @buff: (int array variable) to store the sorted result.
 * @front: (variable)The front index of the subarray.
 * @back: (bariable)back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t midvrble;

	if (back - front > 1)
	{
		midvrble = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, midvrble);
		merge_sort_recursive(subarr, buff, midvrble, back);
		merge_subarr(subarr, buff, front, midvrble, back);
	}
}

/**
 * merge_sort - function sorts arrays of ints in ascending
 *              order using the merge sort algorithm.
 * @array: (array of integers)
 * @size: (variable)size of the array
 *
 * Description: function implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffvrble;

	if (array == NULL || size < 2)
		return;

	buffvrble = malloc(sizeof(int) * size);
	if (buffvrble == NULL)
		return;

	merge_sort_recursive(array, buffvrble, 0, size);

	free(buffvrble);
}
