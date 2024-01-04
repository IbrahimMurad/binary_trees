#include "binary_trees.h"

/**
 * swap - swaps two integers
 * @a: a pointer to the first integer
 * @b: a pointer to the second integer
 *
 * Return: Nothing
*/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * remove_doublicate - removes doublicated values from an array of int
 * by putting them at teh end of the array
 * and returning a new size that does not include them
 * @array: a pointer to the first element of the array
 * @size: the number of elements in the array
 *
 * Return: the new size of the array
*/

size_t remove_doublicate(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
			{
				swap(array + j, array + size - 1);
				size--;
			}
		}
	}
	return (size);
}

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created BST, or NULL on failure
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL, *node;
	size_t i;

	for (i = 0; i < size; i++)
	{
		node = bst_insert(&tree, array[i]);
		if (!node)
			return (NULL);
	}
	return (tree);
}
