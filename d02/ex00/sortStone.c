/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:05:59 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/05 09:52:44 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

typedef struct		s_stone t_stone;
typedef struct		s_group
{
	int size;
	struct s_group *next;
	t_stone *first;
	t_stone *last;
}					t_group;

// Creates a struct called group that holds pointers to mutiple pointers at once
t_group				*createGroup(t_stone *stone)
{
	t_group			*group;

	group = (t_group*)calloc(1, sizeof(t_group));
	group->first = stone;
	group->next = NULL;
	group->last = stone;
	group->size = stone->size;
	return (group);
}

// Inserts stone into its designated group size
// Will create a group if it doesnt exist
void				insertStone(t_group **group, t_stone *stone)
{
	t_group *temp;

	if (*group == NULL)
		*group = createGroup(stone);
	else
	{
		temp = *group;
		while (temp->next)
		{
			if (temp->size == stone->size)
			{
				temp->last->next = stone;
				temp->last = stone;
				return ;
			}
			temp = temp->next;
		}
		temp->next = createGroup(stone);
	}
}

// Creates list of groups from our linked list of stones
t_group				*getGroups(t_stone *stones)
{
	t_group *group = NULL;

	while (stones)
	{
		insertStone(&group, stones);
		stones = stones->next;
	}
	return (group);
}

// Swaps all information from groups a into b and vice versa
void				swapGroups(t_group *a, t_group *b)
{
	int	temp_size;
	t_stone *temp_first, *temp_last;

	temp_first = a->first;
	temp_last = a->last;
	temp_size = a->size;

	a->first = b->first;
	a->last = b->last;
	a->size = b->size;

	b->first = temp_first;
	b->last = temp_last;
	b->size = temp_size;
}

// Merge all the groups back into a single linked list
t_stone				*mergeGroups(t_group *groups)
{
	t_stone *stones = NULL;
	t_stone *temp;

	while (groups)
	{
		if (!stones)
			stones = groups->first;
		else
			temp->next = groups->first;
		temp = groups->last;
		groups = groups->next;
	}
	temp->next = NULL;
	return (stones);
}

// Clears all used memory to create groups
void				deleteGroups(t_group *groups)
{
	t_group *temp1, *temp2;

	temp1 = groups;
	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
}

// Enhanced version of bubble sort using a pointer to keep the address of hte first and last stone
void				sortStones(struct s_stone **stone)
{
	int sorting = 1;
	t_group *g1;
	t_group *g2 = NULL;
	t_group *groups = getGroups(*stone);

	while (sorting)
	{
		sorting = 0;
		g1 = groups;
		while (g1->next != g2)
		{
			if (g1->size > g1->next->size) 
			{
				swapGroups(g1, g1->next);
				sorting = 1;
			}
			g1 = g1->next;
		}
		g2 = g1;
	}
	*stone = mergeGroups(groups);
	deleteGroups(groups);
}

