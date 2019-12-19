/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:50:13 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:32:43 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

/*
** This is same as flood fill........
*/

void sinkIsland(int **map, int row, int col)
{
	if (map[row][col] != 1 || map[row] == NULL)
		return ;
	if (row < 0 || col < 0 || col == -1)
		return ;

	map[row][col] = 0;
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row, col - 1);
}
