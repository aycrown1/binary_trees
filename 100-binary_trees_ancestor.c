#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *right, *left;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	right = first->parent, left = second->parent;
	if (first == left || !right || (!right->parent && left))
		return (binary_trees_ancestor(first, left));
	else if (right == second || !left || (!left->parent && right))
		return (binary_trees_ancestor(right, second));
	return (binary_trees_ancestor(right, left));
}
