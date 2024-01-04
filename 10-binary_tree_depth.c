#include "binary_trees.h"
/**
 * binary_tree_depth - Find depth of a binary tree
 * @tree: Pointer to root node of tree
 * Return: If tree is NULL return 0 else depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
		return ((binary_tree_depth(tree->parent)) + 1);
	}
	return (0);
}

