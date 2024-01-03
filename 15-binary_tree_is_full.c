#include "binary_trees.h"


/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if full or 0 if not or NULL
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_left_full, is_right_full;

	if (!tree)
		return (0);

	if (tree->left && tree->right)
	{
		is_left_full = binary_tree_is_full(tree->left);
		is_right_full = binary_tree_is_full(tree->right);
		return (is_left_full * is_right_full);
	}
	else if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (0);
}
