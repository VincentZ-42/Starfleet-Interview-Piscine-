/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:58:04 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/06 22:00:30 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

typedef struct s_node t_node;


t_node		*bst(int *arr, int left, int right)
{
	int mid = (left + right) / 2;
	t_node *root = (t_node*)malloc(sizeof(t_node));

	if (left > right)
		return (NULL);
	root->value = arr[mid];
	root->left = bst(arr, left, mid - 1);
	root->right = bst(arr, mid + 1, right);
	return (root);
}

struct s_node *createBST(int *arr, int n)
{
	return (bst(arr, 0, n - 1));
}
