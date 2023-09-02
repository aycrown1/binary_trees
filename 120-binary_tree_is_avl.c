#include "binary_trees.h"
#include "limits.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_AVL - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @small: The value of the smallest node visited thus far.
 * @large: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_AVL(const binary_tree_t *tree, int small, int large)
{
	size_t left, right, diff;

	if (tree != NULL)
	{
		if (tree->n < small || tree->n > large)
			return (0);
		left = height(tree->left);
		right = height(tree->right);
		diff = left > right ? left - right : right - left;
		if (diff > 1)
			return (0);
		return (is_AVL(tree->left, small, tree->n - 1) &&
				is_AVL(tree->right, tree->n + 1, large));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_AVL(tree, INT_MIN, INT_MAX));
}

