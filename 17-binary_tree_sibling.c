#include "binary_trees.h"

/**
 * binary_tree_sibling - unction that finds the
 * sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to sibling node or null if no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
