#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int da_width, left, right, is_left, ind_i;

	if (!tree)
	return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	da_width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + da_width, depth + 1, s);
	for (ind_i = 0; ind_i < da_width; ind_i++)
		s[depth][offset + left + ind_i] = b[ind_i];
	if (depth && is_left)
	{
		for (ind_i = 0; ind_i < da_width + right; ind_i++)
			s[depth - 1][offset + left + da_width / 2 + ind_i] = '-';
		s[depth - 1][offset + left + da_width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (ind_i = 0; ind_i < left + da_width; ind_i++)
			s[depth - 1][offset - da_width / 2 + ind_i] = '-';
		s[depth - 1][offset + left + da_width / 2] = '.';
	}
	return (left + da_width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_lt;
	size_t height_rt;

	height_lt = tree->left ? 1 + _height(tree->left) : 0;
	height_rt = tree->right ? 1 + _height(tree->right) : 0;
	return (height_lt > height_rt ? height_lt : height_rt);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, ind_i, ind_j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (ind_i = 0; ind_i < height + 1; ind_i++)
	{
		s[ind_i] = malloc(sizeof(**s) * 255);
		if (!s[ind_i])
			return;
		memset(s[ind_i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (ind_i = 0; ind_i < height + 1; ind_i++)
	{
		for (ind_j = 254; ind_j > 1; --ind_j)
		{
			if (s[ind_i][ind_j] != ' ')
				break;
			s[ind_i][ind_j] = '\0';
		}
		printf("%s\n", s[ind_i]);
		free(s[ind_i]);
	}
	free(s);
}
	

