#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * 
 * Return: number of non-leaf nodes
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t non_leaf;

	non_leaf = 0;
	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (0);
	non_leaf++;
	non_leaf += binary_tree_nodes(tree->left);
	non_leaf += binary_tree_nodes(tree->right);
	return (non_leaf);
}