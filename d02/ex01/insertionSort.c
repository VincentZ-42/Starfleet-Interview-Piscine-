/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:56:12 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/05 10:19:25 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Insertion sort which looks at current number and...
// inserts it backward so that list up to that point is sorted
//
void		insertionSort(struct s_player **players)
{
	struct s_player *temp;
	int i, j;

	for (i = 1; players[i]; i++)
	{
		j = i;
		// This basically does a swap of the currently element...
		// and all previous elements
		while (j > 0 && players[j]->score > players[j - 1]->score)
		{
			temp = players[j];
			players[j] = players[j - 1];
			players[j - 1] = temp;
			j--;
		}
	}
}
