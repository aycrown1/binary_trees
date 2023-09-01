#include "binary_trees.h"

/**
 * binary_tree_postorder - prints the data in a binary tree postorder
 * @tree: pointer to the root node of a binary tree
 * @func: function that takes an int
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
