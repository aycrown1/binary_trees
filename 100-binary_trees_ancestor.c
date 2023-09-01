#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: lowest common ancestor
 */
binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t lowest;

	if (first && second)
	{
		if (first->parent == second)
			return ((binary_tree_t *)second);
		if (second->parent == first)
			return ((binary_tree_t *)first);
		lowest = binary_tree_depth(first);
		return (binary_tree_depth(second) < lowest ? second->parent : first->parent);
	}
	return (NULL);
}

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
