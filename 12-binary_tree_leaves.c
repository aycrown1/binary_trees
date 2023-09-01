#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the number of leaves in a binary tree
 * @tree: binary tree
 *
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			count++;
		if (tree->left)
			count += binary_tree_leaves(tree->left);
		if (tree->right)
			count += binary_tree_leaves(tree->right);
	}
	return (count);
}
