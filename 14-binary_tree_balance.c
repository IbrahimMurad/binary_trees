#include "binary_trees.h"


/**
 * my_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree or 0 if tree is NULL
*/

int my_height(const binary_tree_t *tree)
{
	int height, left_height, right_height;

	height = 0;
	left_height = 0;
	right_height = 0;
	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + my_height(tree->left);
	else
		left_height = 1;

	if (tree->right)
		right_height = 1 + my_height(tree->right);
	else
		right_height = 1;

	if (left_height > right_height)
		height = left_height;
	else
		height += right_height;
	return (height);
}



/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree
 * to measure the balance factor
 *
 * Return: he balance factor of a binary tree
 * and 0 if tree is NULL
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = my_height(tree->left);
	right_height = my_height(tree->right);
	return (left_height - right_height);
}
