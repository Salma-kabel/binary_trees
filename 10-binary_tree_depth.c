#include "binary_trees.h"
/**
* binary_tree_depth - Measures the depth of a node.
* @tree: A pointer of the node
* Return: if NULL, return 0
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
	{
		return (0);
	}

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}

