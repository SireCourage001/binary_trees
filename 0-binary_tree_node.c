#include "binary_trees.h"

/**
 * binary_tree_node - Fxn to create a binary tree node.
 * @parent: Parent of the node to create.
 * @value: Value to store in the new node.
 * Return: Pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	return (new_node);
}