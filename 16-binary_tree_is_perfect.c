#include "binary_trees.h"



/**
 * my_height1 - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree or 0 if tree is NULL
*/

int my_height1(const binary_tree_t *tree)
{
	int height, left_height, right_height;

	height = 0;
	left_height = 0;
	right_height = 0;
	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + my_height1(tree->left);
	else
		left_height = 1;

	if (tree->right)
		right_height = 1 + my_height1(tree->right);
	else
		right_height = 1;

	if (left_height > right_height)
		height = left_height;
	else
		height += right_height;
	return (height);
}



/**
 * is_balanced - checks if the tree is balanced
 * @tree: a pointer to the root node of the tree
 * to check for its balance
 *
 * Return: 1 if balanced or 0 if not
*/

int is_balanced(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = my_height1(tree->left);
	right_height = my_height1(tree->right);
	if (left_height == right_height)
		return (1);
	else
		return (0);
}


/**
 * is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if full or 0 if not or NULL
*/

int is_full(const binary_tree_t *tree)
{
	int is_left_full, is_right_full;

	if (!tree)
		return (0);

	if (tree->left && tree->right)
	{
		is_left_full = is_full(tree->left);
		is_right_full = is_full(tree->right);
		return (is_left_full * is_right_full);
	}
	else if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (0);
}



/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if perfect or 0 if not or NULL
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (is_full(tree) && is_balanced(tree))
		return (1);
	else
		return (0);
}
