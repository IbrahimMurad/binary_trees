#include "binary_trees.h"

/**
 * max_val - finds the maximum value n a binary tree
 * @tree: a pointer ot the root node of the tree
 *
 * Return: the maximum value in the tree
*/

int max_val(const binary_tree_t *tree)
{
	int max, max_left, max_right;

	max = tree->n;
	if (tree->left)
	{
		max_left = max_val(tree->left);
		if (max_left > max)
			max = max_left;
	}
	if (tree->right)
	{
		max_right = max_val(tree->right);
		if (max_right > max)
			max = max_right;
	}
	return (max);
}

/**
 * min_val - finds the minimum value n a binary tree
 * @tree: a pointer ot the root node of the tree
 *
 * Return: the minimum value in the tree
*/


int min_val(const binary_tree_t *tree)
{
	int min, min_left, min_right;

	min = tree->n;
	if (tree->left)
	{
		min_left = min_val(tree->left);
		if (min_left < min)
			min = min_left;
	}
	if (tree->right)
	{
		min_right = min_val(tree->right);
		if (min_right < min)
			min = min_right;
	}
	return (min);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise or tree is NULL
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_left_bst = 1, is_right_bst = 1;

	if (!tree)
		return (0);

	if (tree->left)
	{
		if (tree->n > max_val(tree->left))
			is_left_bst = binary_tree_is_bst(tree->left);
		else
			return (0);
	}
	if (tree->right)
	{
		if (tree->n < min_val(tree->right))
			is_right_bst = binary_tree_is_bst(tree->right);
		else
			return (0);
	}
	return (is_left_bst * is_right_bst);
}
