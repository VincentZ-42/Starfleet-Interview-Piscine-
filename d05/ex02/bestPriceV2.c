/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:20:34 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:32:04 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#define BIGGER(a, b) (a > b ? a : b)

/*
** Function that recursively gets the best price from the list of prices
** Starts out with price of size n first and then compares this to ...
** ... the total price of slice 3 and n - 3 ...
** Basically, we are adding from the front and back towards the center
** Comparing all prices from both ends of the list to see which sells the best
*/

double getBest(int n, double *prices, double *best)
{
	if (best[n] == 0)
	{
		best[n] = prices[n];
		for (int i = 1; i <= n / 2; i += 2)
		{
			double temp = getBest(i, prices, best) + getBest(n - i, prices, best);
			best[n] = BIGGER(temp, best[n]);
		}
	}
	return (best[n]);
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double *best = calloc(pizzaSize, sizeof(double));
	return (getBest(pizzaSize, prices, best));
}
