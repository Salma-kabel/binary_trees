#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, m;

	if (tree == NULL)
		return (0);
	l = binary_tree_is_full(tree->left);
	m = binary_tree_is_full(tree->right);
	if (l == m)
		return (1);
	else
		return (0);
}
