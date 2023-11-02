#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	static binary_tree_t *node = NULL, *node1;
	static int num;
	int l, r;

	if (node == NULL)
		node = (binary_tree_t *)tree;
	if (node == NULL)
		return (0);
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
