#include "binary_trees.h"


/**
 * sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node
 * or NULL if node is NULL or the parent is NULL
 * or node has no siblings.
*/

binary_tree_t *sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);

	if (node->parent->left == node)
	{
		return (node->parent->right);
	}
	else
	{
		return (node->parent->left);
	}
}


/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node or NULL
 * if node is NULL or has no uncle
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	return (sibling(node->parent));
}
