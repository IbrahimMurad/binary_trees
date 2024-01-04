#include "binary_trees.h"

/**
 * is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: the index of the node to check from in the tree
 * @nodes_count: the number of nodes in the whole tree
 *
 * Return: 1 if complete or 0 if not or tree is NULL
*/

int is_complete(const binary_tree_t *tree, int index, int nodes_count)
{
	if (!tree)
		return (1);

	if (index >= nodes_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes_count) *
			is_complete(tree->right, 2 * index + 2, nodes_count));
}

/**
 * count_tree - counts the nodes in a binary tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: the number of nodes in the tree
*/

int count_tree(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_tree(tree->left) + count_tree(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if complete or 0 if not or tree is NULL
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	int nodes_count;

	if (!tree)
		return (0);
	nodes_count = count_tree(tree);
	return (is_complete(tree, index, nodes_count));
}
