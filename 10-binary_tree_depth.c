#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree node
 * @node: node to measure
 *
 * Return: node depth
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (node)
	{
		for (depth = 0; node->parent; node = node->parent, depth++)
		;
	}
	return (depth);
}
