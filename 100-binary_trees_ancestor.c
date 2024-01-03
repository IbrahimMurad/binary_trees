#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node
 * of the two given nodes
 * or NULL if no common ancestor was found
*/

binary_tree_t *binary_trees_ancestor(binary_tree_t *first,
	binary_tree_t *second)
{
	binary_tree_t *slow, *fast;

	if (!first || !second)
		return (NULL);
	slow = first;
	fast = second;
	while (slow)
	{
		while (fast)
		{
			if (slow == fast)
				return (slow);
			fast = fast->parent;
		}
		fast = second;
		slow = slow->parent;
	}
	return (NULL);
}
