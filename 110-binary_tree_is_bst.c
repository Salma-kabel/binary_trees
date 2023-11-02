#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	static binary_tree_t *node = NULL, *nd;
	int l, r;

	if (node == NULL)
		node = (binary_tree_t *)tree;
	if (node == NULL)
		return (0);
	if (tree == NULL)
		return (1);
	if (node == tree)
		nd = tree->left;
	l = binary_tree_is_bst(tree->left);
	if (node == tree)
		nd = tree->right;
	r = binary_tree_is_bst(tree->right);
	if (node == tree)
	{
		node = NULL;
		return (l * r);
	}
	else if (tree->parent->left == tree)
	{
		if (!((nd == node->left && tree->n < node->n) ||
				(nd == node->right && tree->n > node->n)))
			return (0);
		if (tree->n < tree->parent->n)
			return (l * r);
		else
			return (0);
	}
	else
	{
		if (!((nd == node->left && tree->n < node->n) ||
					(nd == node->right && tree->n > node->n)))
			return (0);
		if (tree->n < tree->parent->n && tree->n < node->n)
			return (0);
		else
			return (l * r);
	}
}
