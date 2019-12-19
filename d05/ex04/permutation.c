/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:41:55 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:33:34 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

/*
** Function that swaps the address of two characters in string
*/

void	swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/*
** Function that does all permutations by swaping characters...
** ...and calls itself recursively until left == right index
*/

void	permute(char *str, int l, int r)
{
	if (l == r)
		printf("%s\n", str);
	else
		for (int i = l; i <= r; i++)
		{
			swap(&str[l], &str[i]);
			permute(str, l + 1, r);
			swap(&str[l], &str[i]);
		}
}

/*
** Function that initates our permutation recursive calls
*/

void	printPermutations(char *str)
{
	int start = 0;
	int end = strlen(str) - 1;
	permute(str, start, end);
}
