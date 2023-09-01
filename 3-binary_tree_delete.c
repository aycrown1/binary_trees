#include "binary_trees.h"

/**
 * binary_tree_delete - frees memory allocated by a binary tree
 * @tree: pointer to the root node of a binary tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{

	  /*Delete the left and right subtrees recursively */
	  binary_tree_delete(tree->left);
	  binary_tree_delete(tree->right);
		free(tree);
	}
}
