/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpNephew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:50:51 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/12 23:38:58 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

// Function that calculates that nephew will die after p punches
// Use printf("prob_die = %f\n", prob_die); to visualize better

double punch(int ns, int p, int ne)
{
	double	prob_die = 0;
	double	chance = ((double)1 / (double)ns);

	if (ns <= ne || p == 0)
		return (ns <= ne ? 1 : 0);
	while (ns > 0)
	{
		prob_die += chance * punch(ns - 1, p - 1, ne);
		ns--;
	}
	return (prob_die);
}

// Function that initates finding the probablity of nephew surviving
// we are actually finding the opposite, then subtracting from 1
double probaNephewWillLive(int nStairs, int nPunch, int nephewStair)
{
	return (1 - punch(nStairs, nPunch, nephewStair));
}
