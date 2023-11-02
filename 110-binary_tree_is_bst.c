#include "binary_trees.h"



int binary_tree_is_bst(const binary_tree_t *tree)
{
	static binary_tree_t *node = NULL, *node1;
	static int num;
	int l, r;

	if (node == NULL)
		node = (binary_tree_t *)tree;
	if (tree == NULL)
		return (1);
	if (node == tree)
	{
		num = tree->n;
		node1 = tree->left;
		l = binary_tree_is_bst(tree->left);
	}
	if (node != tree && node1 == node->left)
	{
		l = binary_tree_is_bst(tree->left);
		r = binary_tree_is_bst(tree->right);
		if (tree->n < num)
			return (l * r);
		else
			return (0);
	}
	else if (node != tree && node1 == node->right)
	{
		l = binary_tree_is_bst(tree->left);
		r = binary_tree_is_bst(tree->right);
		if (tree->n < num)
			return (0);
		else
			return (l * r);
	}
	node1 = tree->right;
	r = binary_tree_is_bst(tree->right);
	node = NULL;
	return (l * r);
}
