#include "binary_trees.h"
/**
* binary_tree_size - Measures the size.
* @tree: A pointer.
* Return: 0 if tree is NULL
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0, right_size = 0, left_size = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left)
	{
		left_size += binary_tree_size(tree->left);
	}
	if (tree->right)
	{
		right_size += binary_tree_size(tree->right);
	}

	tree_size += left_size + right_size + 1;

	return (tree_size);
}

