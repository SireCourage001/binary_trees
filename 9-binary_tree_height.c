#include "binary_trees.h"
/**
 * binary_tree_height - Finds height of binary tree
 * @tree: Pointer to root node of tree
 * Return: If tree is NULL return 0 else Height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree)
	{
		left_height  = tree->left ? binary_tree_height(tree->left) + 1 : 0;
		right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

