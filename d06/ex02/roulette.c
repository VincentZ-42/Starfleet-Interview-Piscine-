/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:40:49 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/12 20:28:58 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Function that calculates the probablity of winning the amount you want in n games
// Args:
// firstDollarsBet = Starting Money
// dollarsWanted = Target Goal
// nbGame = number of games being played
// Returns:
// Probability of earning target goal with starting bet in nb amount of games
// Note: Probablity is calculated in mutual case which is one game winning after...
// ... the next by adding the probabilities together
// 2nd Note: *2 recursion is for winning current game and /2 recursion is for losing

double	probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	if (firstDollarsBet == 0 || nbGame < 0)
		return (0.0);
	if (firstDollarsBet >= dollarsWanted)
		return (1.0);
	return ((18 * probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1) \
				+ probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1))/37);
}
