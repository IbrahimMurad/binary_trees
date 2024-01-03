#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: the depth of a node in a binary tree
 * and 0 if tree is NULL
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	depth = 0;
	if (!tree)
		return (0);
	if (binary_tree_is_root(tree))
		return (0);
	depth++;
	depth += binary_tree_depth(tree->parent);
	return (depth);
}
