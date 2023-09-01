#include "binary_trees.h"

/**
 * binary_tree_preorder - prints the data in a binary tree
 * @tree: pointer to the root node of a binary tree
 * @func: function that takes an int
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
