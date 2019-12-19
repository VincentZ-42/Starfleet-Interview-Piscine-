/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:19:56 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/12 19:35:25 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#define ADD(a, b) (a + b)
#define MINUS(a, b) (a - b)

// Function that counts the number of hotspots that does not overlap
// Args:
// struct s_hotspot **hotspots = array of structs holding info about hotspot
// Returns:
// Number of non-overlapping hotspots
// Additional Info:
// reach = the maximum range of 1st hotspot
// lowest_pos is the range of the lower bound of current hotspot
// highest_pos is the range of the upper bound of the current hotspot
// As we traverse the array, we change our range to see if any overlaps...
// ...and only count the hotspots that do not overlap
int		selectHotspots(struct s_hotspot **hotspots)
{
	int count = 1;
	int reach = ADD(hotspots[0]->pos, hotspots[0]->radius);
	int lowest_pos;
	int highest_pos;

	for (int i = 1; hotspots[i]; i++)
	{
		lowest_pos = abs(MINUS(hotspots[i]->pos, hotspots[i]->radius));
		highest_pos = ADD(hotspots[i]->pos, hotspots[i]->radius);
		if (reach <= lowest_pos)
		{
			reach = highest_pos;
			count++;
		}
		else if (reach > highest_pos)
			reach = highest_pos;
	}
	return (count);
}
