#include "binary_trees.h"

/**
 * binary_tree_preorder - Pre-order traversal mode.
 * @tree: Pointer to the root
 * @func: Pointer to call function for each node
 * the value of the node must be passed as a param to this function
 * if tree or func is NULL do nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

