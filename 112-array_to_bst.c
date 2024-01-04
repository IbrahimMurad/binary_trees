#include "binary_trees.h"

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
