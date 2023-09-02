#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_heap_recursive - Helper function to check heap property recursively.
 * @tree: Pointer to the current node.
 * @max_value: The maximum value encountered so far.
 * Return: 1 if the heap property is satisfied, 0 otherwise.
 */
int binary_tree_is_heap_recursive(const binary_tree_t *tree, int max_value)
{
	if (tree == NULL)
		return (1);

	if (tree->n > max_value)
		return (0);

	return (binary_tree_is_heap_recursive(tree->left, tree->n) &&
		   binary_tree_is_heap_recursive(tree->right, tree->n));
}

/**
 * binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if it's a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t height = binary_tree_height(tree);
	int max_value = tree->n;

	return (binary_tree_is_heap_recursive(tree, max_value) &&
		   height == binary_tree_height(tree));
}
