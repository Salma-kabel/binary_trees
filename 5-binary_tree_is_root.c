#include "binary_trees.h"

/**
 * binary_tree_is_root - Function that checks if a node is in root
 * @node: Node.
 * Return: 0 if is not a root 1 if in root
 */

int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL || node->parent != NULL)
return (0);

return (1);
}

