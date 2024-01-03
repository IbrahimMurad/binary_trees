#include "binary_trees.h"


/**
 * push - pushes a vl_node to the linked list
 * @head: a pointer to a pointer to the head of the list
 * @val: the value of teh new node
 * @lv: the level of the new node
 *
 * Return: a pointer to the new node
*/

vl_node *push(vl_node *head, int val, int lv)
{
	vl_node *new_node;

	new_node = (vl_node *) malloc(sizeof(vl_node));
	if (!new_node)
		return (NULL);
	new_node->value = val;
	new_node->level = lv;
	new_node->next = head;
	head = new_node;
	return (new_node);
}

/**
 * tree_to_list - saves a binary tree to a vl-node linked list
 * @tree: a pointer to the root node of the tree
 * @head: a pointer to the head node of the linked list
 * @level: the level of the node in the tree
 *
 * Return: a pointer to the head node of the linked list
*/

vl_node *tree_to_list(const binary_tree_t *tree, vl_node *head, int level)
{
	if (!tree)
		return (head);
	head = push(head, tree->n, level);
	head = tree_to_list(tree->right, head, level + 1);
	head = tree_to_list(tree->left, head, level + 1);
	return (head);
}

/**
 * free_list - frees vl_node linked list
 * @head: a pointer to the head node of the list
 *
 * Return: Nothing
*/

void free_list(vl_node *head)
{
	vl_node *temp = head;

	while (temp)
	{
		head = temp->next;
		free(temp);
		temp = head;
	}
}

/**
 * my_height2 - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree or 0 if tree is NULL
*/

int my_height2(const binary_tree_t *tree)
{
	int height, left_height, right_height;

	height = 0;
	left_height = 0;
	right_height = 0;
	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + my_height2(tree->left);
	else
		left_height = 0;

	if (tree->right)
		right_height = 1 + my_height2(tree->right);
	else
		right_height = 0;

	if (left_height > right_height)
		height = left_height;
	else
		height += right_height;
	return (height);
}


/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: Nothing
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	vl_node *head = NULL, *temp;
	int tree_height, i;

	if (!tree || !func)
		return;

	tree_height = my_height2(tree);
	head = tree_to_list(tree, head, 0);
	temp = head;
	for (i = 0; i <= tree_height; i++)
	{
		while (temp)
		{
			if (temp->level == i)
				func(temp->value);
			temp = temp->next;
		}
		temp = head;
	}
	free_list(head);
}
