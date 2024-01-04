#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *new_root, *old_root;

	if (!tree || !(tree->right))
		return (tree);
	old_root = tree;
	new_root = tree->right;

	if (tree->right->left)
	{
		temp = tree->right->left;
		temp->parent = tree;
		old_root->right = temp;
	}
	else
		old_root->right = NULL;

	old_root->parent = new_root;
	new_root->parent = tree->parent;

	new_root->left = tree;

	return (new_root);
}
