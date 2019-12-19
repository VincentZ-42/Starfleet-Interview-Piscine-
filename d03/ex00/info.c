/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:32:03 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/06 22:03:55 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_node t_node;
typedef struct s_info t_info;

#define BIGGER(a, b) (a > b ? a: b)
#define SMALLER(a, b) (a < b ? a : b)

// BST = binary search tree
// left node value must be lower than root
// right node value must be greater than root
int		check_if_bst(t_node *root)
{
	if (root->left && root->left->value > root->value)
		return (0);
	if (root->right && root->right->value <= root->value)
		return (0);
	return (1);
}

int		height_tree(t_node *root, int h)
{
	int max = -1;

	if (!root)
		return (-1);
	if (root->left)
		max = height_tree(root->left, h + 1);
	if (root->right)
		max = height_tree(root->right, h + 1);
	return (BIGGER(max, h));
}

// Function that checks the height of the left and right side
// and compares them by subtraction
int		check_if_balanced(t_node *root)
{
	int left_height = -1;
	int right_height = -1;

	if (root->left)
		left_height = height_tree(root->left, 0);
	if (root->right)
		right_height = height_tree(root->right, 0);
	if ( (left_height - right_height > 1) || (left_height - right_height < -1))
		return (0);
	else
		return (1);
}

// traverses our tree, filling out all info that we need
void	traverse_tree(t_node *root, t_info *info, int h)
{
	if (root)
	{
		info->height = BIGGER(info->height, h);
		info->max = BIGGER(info->max, root->value);
		info->min = SMALLER(info->min, root->value);
		info->elements++;
		if (!check_if_bst(root))
			info->isBST = 0;
		if (!check_if_balanced(root))
			info->isBalanced = 0;
	}
	if (root->left)
		traverse_tree(root->left, info, h + 1);
	if (root->right)
		traverse_tree(root->right, info, h + 1);
}

// function inits and gets all relevant info about tree
struct s_info	getInfo(struct s_node *root)
{
	t_info info;

	if (root)
	{
		info.min = root->value;
		info.max = root->value;
		info.elements = 0;
		info.height = 0;
		info.isBST = 1;
		info.isBalanced = 1;
		traverse_tree(root, &info, 0);
	}
	else
	{
		info.height = -1;
		info.elements = 0;;
	}
	return (info);
}
