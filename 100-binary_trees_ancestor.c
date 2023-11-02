#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to lowest common ancestor or null
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *fparent, *sparent;

	fparent = (binary_tree_t *)first;
	sparent = (binary_tree_t *)second;
	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second->parent)
		return (fparent);
	if (second == first->parent)
		return (sparent);
	fparent = first->parent;
	sparent = second->parent;
	while (fparent != NULL)
	{
		while (sparent != NULL)
		{
			if (fparent == sparent)
				return (fparent);
			sparent = sparent->parent;
		}
		fparent = fparent->parent;
	}
	return (NULL);
}
