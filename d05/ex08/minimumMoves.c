/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:40:00 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/12 10:30:16 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node t_node;

/*
** Function that copes and returns a new node
*/

t_node	*create_node(t_node *node, int value)
{
	t_node *fresh = memcpy(malloc(sizeof(t_node)), node, sizeof(t_node));
	
	fresh->value = value;
	return (fresh);
}

/*
** Function that calculates the number of moves needed to reach the end
** Adds to queue from both next and random pointer until we find end
** and recursively calls itself until it reaches the end
*/

void calculate(struct s_queue *q, int *moves)
{
	struct s_node *node = dequeue(q);
	
	if (node->isFinal || !q || *moves != 0)
	{
		*moves = *moves ? *moves : node->value;
		return ;
	}
	if (node->next && *moves == 0)
		enqueue(q, create_node(node->next, node->value + 1));
	if (node->random && *moves == 0)
		enqueue(q, create_node(node->random, node->value + 1));
	calculate(q, moves);
}

/*
** Function that initates the traversing process
*/

int minimumMoves(struct s_node *begin)
{
	struct s_queue *q = queueInit();
	int moves = 0;

	enqueue(q, create_node(begin, 0));
	calculate(q, &moves);
	return (moves ? moves : -1);
}
