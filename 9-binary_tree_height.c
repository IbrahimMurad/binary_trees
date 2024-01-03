#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree or 0 if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height, left_height, right_height;

	height = 0;
	left_height = 0;
	right_height = 0;
	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	else
		left_height = 0;

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	else
		right_height = 0;

	if (left_height > right_height)
		height = left_height;
	else
		height += right_height;
	return (height);
}