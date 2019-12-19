/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:40:40 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:35:50 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

typedef struct s_people t_people;

/*
** Function that places people in tables to see if all ppl can be served
** Args:
** t_people **ppl = array of strucs contain ppl and eating time
** int i = index of person in array
** int nbTable = number of tables
** int totalTime = maximum time on each table
** int *avail = int array holding the time each person spends on certain table
** Returns:
** 1 if all people are served in totalTime
** 0 if can't serve all people in totalTime
*/

int		scan(t_people **ppl, int i, int nbTable, int totalTime, int *avail)
{
	if (!ppl[i])
		return (1);
	for (int j = 0; j < nbTable; j++)
		if (avail[j] + ppl[i]->time <= totalTime)
		{
			avail[j] += ppl[i]->time;
			if (scan(ppl, i + 1, nbTable, totalTime, avail))
				return (1);
			avail[j] -= ppl[i]->time;
		}
	return (0);
}

/*
** Function that initates the recursive filling of tables
*/

int		isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int *avail = calloc(nbTable, sizeof(int));
	int ret = scan(people, 0, nbTable, totalTime, avail);
	free(avail);
	return (ret);
}
