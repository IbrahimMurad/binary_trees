#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    binary_tree_print(root);
    binary_tree_preorder(root, &print_num);
    binary_tree_insert_right(root, 12);
    binary_tree_insert_right(root, 13);
    binary_tree_insert_right(root, 14);
    binary_tree_insert_right(root, 15);
    binary_tree_insert_right(root, 16);
    binary_tree_insert_right(root, 17);

    binary_tree_print(root);
    binary_tree_preorder(root, &print_num);
    return (0);
}