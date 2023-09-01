#include "binary_trees.h"


/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to the function to call for each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	binary_tree_t **queue = NULL;
	const binary_tree_t *current = NULL;

	if (tree == NULL || func == NULL)
		return;

	/* Create a queue for level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		current = queue[front];
		front++;

		/* Call the function for the current node's value */
		func(current->n);

		/* Enqueue the left child if it exists */
		if (current->left)
		{
			queue[rear] = current->left;
			rear++;
		}

		/* Enqueue the right child if it exists */
		if (current->right)
		{
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
}
