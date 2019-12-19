/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:14:01 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/06 22:49:38 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

typedef struct s_node t_node;

// Function that recursively searchs the array of structs in root
// If we find first name match, we increase found_2 to 1
// If we find 2nd name match, we increase found_2 to 2
// As we traverse the list, we return the node if we find any matches
t_node	*find_me(t_node *root, char *first, char *second, int *found_2)
{
	t_node *temp = NULL;
	t_node *cur;
	int match = 0;

	if (!strcmp(root->name, first))
	{
		(*found_2)++;
		return (root);
	}
	if (!strcmp(root->name, second))
	{
		(*found_2)++;
		return (root);
	}
	for (int i = 0; root->children[i]; i++)
	{
		cur = find_me(root->children[i], first, second, found_2);
		if (cur)
		{
			temp = cur;
			match++;
		}
	}
	return (match == 2 ? root : temp);
}

// Function that passes all arguments into searching function
// Note we must find common parent to return a success
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	int found_2 = 0;
	t_node *parent = find_me(root, firstSpecies, secondSpecies, &found_2);

	return (found_2 == 2 ? parent : NULL);
}
