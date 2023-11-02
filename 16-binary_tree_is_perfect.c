#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 * Return: 1 if perfect 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;
	static int level = 1, v = 1, depth = 1;

	if (tree == NULL)
		return (0);
	level++;
	l = binary_tree_is_perfect(tree->left);
	r = binary_tree_is_perfect(tree->right);
	level--;
	if ((l == -1 || r == -1) && level + 1 != 0)
		return (-1);
	else if ((l == 0 && r == 0 && v == 1) && level + 1 != 0)
	{
		depth = level - 1;
		level -= 2;
		v = 0;
	}
	else if (l == 0 && r == 0 && v == 0)
	{
		if (level + 1 == depth)
			return (1);
		else
			return (-1);
	}
	else if (l != r && level + 1 != 0)
	{
		return (-1);
	}
	else if ((level + 1 == 0))
	{
		v = 1;
		level = 1;
		if ((l == -1 || r == -1) || (l != r))
			return (0);
		else
			return (1);
	}
	return (1);
}
