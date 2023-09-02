#include "binary_trees.h"

/**
 * find_min - Find the node with the minimum value in a tree.
 * @node: A pointer to the root node of the tree.
 * Return: A pointer to the node with the minimum value.
 */
avl_t *find_min(avl_t *node)
{
	while (node->left)
		node = node->left;
	return node;
}

/**
 * avl_remove - Remove a node from an AVL tree.
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove.
 * Return: A pointer to the new root node of the tree after removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return NULL;

	if (value < root->n)
	{
		root->left = avl_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = avl_remove(root->right, value);
	}
	else
	{
		if (!root->left || !root->right)
		{
			avl_t *temp = root->left ? root->left : root->right;
			free(root);
			root = temp;
		}
		else
		{
			avl_t *temp = find_min(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	if (!root)
		return (root);

	int left_height = (root->left) ? root->left->height : 0;
	int right_height = (root->right) ? root->right->height : 0;

	root->height = 1 + ((left_height > right_height) ? left_height : right_height);

	int balance = left_height - right_height;

	if (balance > 1 && value < root->left->n)
		return (binary_tree_rotate_right(root));
	if (balance < -1 && value > root->right->n)
		return (binary_tree_rotate_left(root));
	if (balance > 1 && value > root->left->n)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && value < root->right->n)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
