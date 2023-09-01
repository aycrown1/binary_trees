#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: binary tree node
 *
 * Return: node uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent)
	{
		return (binary_tree_sibling(node->parent));
	}
	return (NULL);
}

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: binary tree node
 *
 * Return: node sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node->parent->left == node)
			return (node->parent->right);
		else
			return (node->parent->left);
	}
	return (NULL);
}
