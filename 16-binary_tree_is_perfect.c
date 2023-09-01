#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: binary tree
 *
 * Return: 1 if perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree)
	{
		if (binary_tree_balance(tree) == 0)
		{
			left = binary_tree_is_perfect(tree->left);
			right = binary_tree_is_perfect(tree->right);
			if (left == right)
				return (1);
		}
	}
	return (0);
}

/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: binary tree
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = binary_tree_height(tree->left) + 1;
		if (tree->right)
			right = binary_tree_height(tree->right) + 1;
	}
	return (left - right);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: binary tree
 *
 * Return: height of binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree)
	{
		if (tree->left)
		{
			left += binary_tree_height(tree->left);
			left++;
		}
		if (tree->right)
		{
			right += binary_tree_height(tree->right);
			right++;
		}
	}
	return (right < left ? left : right);
}
