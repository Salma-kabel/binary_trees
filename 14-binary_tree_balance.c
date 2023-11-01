#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor
 * of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: balance factor of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l, r;
	static int v = 0;

	if (tree == NULL)
		return (0);
	v++;
	l = binary_tree_balance(tree->left);
	r = binary_tree_balance(tree->right);
	if (v > 1)
	{
		v--;
		if (l == 0 && r == 0)
			return (1);
		else if (l >= r)
			return (l + 1);
		else
			return (r + 1);
	}
	v = 0;
	return (l - r);
}
