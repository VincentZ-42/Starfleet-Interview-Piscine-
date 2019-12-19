/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:29:42 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/12 21:25:49 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

// Function that calculates the minimum amount of ppl needed to achieve %
// that two ppl chose the same number
// Args:
// int elements = max number of betters
// int minPercentage = target percentage of winning we are aiming for
// Returns:
// ppl_bet = minimum amount of ppl who needs to bet
// 
// Note: This is an expansion of the birthday problem where two ppl have same birthdays
// It is easier to calculate the % of two ppl not chose the same number and then...
// ...minus that from the whole to get the chance of two ppl choosing the same number
// As the chances of losing decreases, our chances of winning increases (finding match)

int		minPersons(int elements, int minPercentage)
{
	double chance_lose = 1.0;
	double chance_win = (double)minPercentage / 100;
	int ppl_bet = 1;

	while (ppl_bet <= elements && 1 - chance_lose <= chance_win)
	{
		chance_lose *= (double)(elements - ppl_bet) / elements;
		ppl_bet++;
	}
	return (ppl_bet);
}

