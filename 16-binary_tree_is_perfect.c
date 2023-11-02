#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check if is perfect
 *
 * Return: 1 if is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaves, height, pow;

	if (!tree)
		return (0);

	leaves = binary_tree_leaves(tree);
	height = binary_tree_height(tree);
	for (pow = 1; height; height--)
		pow *= 2;
	return ((pow == leaves) ? 1 : 0);
}


/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Number of leaves of the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: heigth or 0 if tree is Null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t j, k;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);
	j = binary_tree_height(tree->right);
	k = binary_tree_height(tree->left);
	if (k > j)
		j = k;
	return (j + 1);
}
