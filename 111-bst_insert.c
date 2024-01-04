#include "binary_trees.h"


/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (!(*tree))
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	else if ((*tree)->left == NULL && (*tree)->n > value)
	{
		(*tree)->left = binary_tree_node(*tree, value);
		return ((*tree)->left);
	}
	else if ((*tree)->right == NULL && (*tree)->n < value)
	{
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}
	else
	{
		if (value == (*tree)->n)
			return (NULL);
		else if (value < (*tree)->n)
		{
			return (bst_insert(&((*tree)->left), value));
		}
		else
		{
			return (bst_insert(&((*tree)->right), value));
		}
	}
}
