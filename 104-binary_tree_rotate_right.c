#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp, *new_root, *old_root;

	if (!tree || !(tree->left))
		return (tree);
	old_root = tree;
	new_root = tree->left;

	if (tree->left->right)
	{
		temp = tree->left->right;
		temp->parent = tree;
		old_root->left = temp;
	}
	else
		old_root->left = NULL;

	old_root->parent = new_root;
	new_root->parent = tree->parent;

	new_root->right = tree;

	return (new_root);
}
