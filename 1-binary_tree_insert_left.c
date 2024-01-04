#include "binary_tree.h"

/**
 * binary_tree_insert_left - Inserts left-child node
 * @parent: Pointer to node where insert left-child
 * @value: Value to put in the new node
 * Return: Pointer to the new node else NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *lt_child;

	if (parent == NULL)
		return (NULL);
	lt_child = binary_tree_node(parent, value);
	if (lt_child == NULL)
		return (NULL);
	lt_child->left = parent->left;
	if (lt_child->left != NULL)
		lt_child->left->parent = lt_child;
	parent->left = lt_child;
	return (lt_child);
}

