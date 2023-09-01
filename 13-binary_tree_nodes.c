#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least one child
 * @tree: binary tree
 * Return: count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			count++;
		if (tree->left)
			count += binary_tree_nodes(tree->left);
		if (tree->right)
			count += binary_tree_nodes(tree->right);
	}
	return (count);
}
