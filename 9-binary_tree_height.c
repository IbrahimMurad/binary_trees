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
	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (0);
	height++;
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height > right_height)
		height += left_height;
	else
		height += right_height;
	return (height);
}