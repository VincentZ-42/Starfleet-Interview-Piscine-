/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 21:48:41 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:30:39 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** Function that recursively finds the best price by adding smaller slices first
** starts with all cuts of 1, then some cuts of 2, and etc, until we have size 0
*/

void	recur(int pizzaSize, double *prices, double *best, double sum)
{
	if (pizzaSize <= 0)
	{
		if (sum > *best)
			*best = sum;
		return ;
	}
	for (int i = 1; i <= pizzaSize; i++)
		recur(pizzaSize - i, prices, best, sum + prices[i]);
}

/*
** Initiates my recursion of combination of sums with an address to best price
*/

double bestPrice(int pizzaSize, double *prices)
{
	double best = 0.0;
	recur(pizzaSize, prices, &best, 0);
	return (best);
}
