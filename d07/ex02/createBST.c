/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:38:38 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/13 17:59:34 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#define CE(x) create_elem(x)

typedef struct s_node t_node;

// Function that creates a new node given a value
t_node	*create_elem(int value)
{
	t_node *new = (t_node*)malloc(sizeof(t_node));
	
	if (!new)
		return (NULL);
	new->value = value;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

// Function that creates our BST by dividing array in half
// Similar to merge sort
t_node			*sortedArraytoBST(int *arr, int l, int r)
{
	if (l > r)
		return (NULL);

	int mid = (l + r) / 2;
	t_node *root = CE(arr[mid]);
	root->left = sortedArraytoBST(arr, l, mid - 1);
	root->right = sortedArraytoBST(arr, mid + 1, r);
	return (root);
}

// Function that initates the creation of BST from sorted array
// Balanced tree : a height-balanced binary tree is defined as...
// ... a binary tree in which the depth of the two subtrees of...
// ... every node never differ by more than 1.
struct s_node	*createBST(int *arr, int n)
{
	if (n <= 0 || !arr)
		return (NULL);
	return (sortedArraytoBST(arr, 0, n - 1));
}
