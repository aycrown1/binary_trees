#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue = NULL, *current = NULL;
	int front = 0, rear = 0;
	int non_full_node_seen = 0;

	if (tree == NULL)
		return (0);

	/* Create a queue for level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);

	queue[rear] = tree;
	rear++;

	while (front < rear)
	{
		current = queue[front];
		front++;

		if (current == NULL)
			non_full_node_seen = 1;
		else
		{
			if (non_full_node_seen)
			{
				free(queue);
				return (0);
			}

			/* Enqueue left and right children */
			queue[rear] = current->left;
			rear++;
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
	return (1);
}
