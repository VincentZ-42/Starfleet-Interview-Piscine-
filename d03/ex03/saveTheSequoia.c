/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 22:10:29 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/06 22:49:14 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct s_node t_node;

// Function that swaps the parent node with the child node
// Saves the node to a temp variable
// Then we check if we should do it to the left or right side
// Lastly, we change the pointers of the left n right node to proper ones
void pop(struct s_node **parent, struct s_node **child)
{
	t_node *temp = *parent;
	t_node *c_l = (*child)->left;
	t_node *c_r = (*child)->right;
	*parent = *child;
	if (temp->left == *child)
	{
		(*child)->left = temp;
		(*child)->right = temp->right;
	}
	else
	{
		(*child)->right = temp;
		(*child)->left = temp->left;
	}
	temp->left = c_l;
	temp->right = c_r;
}

// Function that does the comparisons and then pops the current node
// ...with the node of left or right depending it if it is lower...
// We add all the elements in the node to return number of elements in tree
int heap(struct s_node **node)
{
	if (!*node)
		return 0;

	int n = 1;

	if ((*node)->right && (*node)->value < (*node)->right->value)
		pop(node, &(*node)->right);
	if ((*node)->left && (*node)->value < (*node)->left->value)
		pop(node, &(*node)->left);
	n += heap(&(*node)->right);
	n += heap(&(*node)->left);

	return (n);
}

// Function that changes min heap to max heap data structure
void	saveTheSequoia(struct s_node **root)
{
	if (!root)
		return ;
	int n = heap(root);
	for (int i = 0; i < n - 1; i++)
		heap(root);
}
