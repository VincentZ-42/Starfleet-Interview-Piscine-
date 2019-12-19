/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:58:43 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:29:43 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_array t_array;

/*
** Function that recurses on itself with the decrement of the size
** Use this print function to remind yourself how this works:
** printf("new recur, pizza->sum = %d, n = %d\n", pizza->sum, n);
** Function creates a new array with each new size and minus that...
** ...with the # already inside the array, once our sum is 5 and size is 0...
** ...we print the array and start over from the last recursive stack
*/

void	recur(struct s_array *pizza, int n)
{

	if (!n)
	{
		arrayPrint(pizza);
		free(pizza);
	}
	for (int i = n; i > 0; i--) {
		t_array *clone = arrayClone(pizza);
		arrayAppend(clone, i);
		recur(clone, n - i);
	}
}

/*
** Initizes our struct and starts the recursive process
*/

void	printPossibleSlices(int pizzaSize)
{
	t_array *pizza = arrayInit();
	recur(pizza, pizzaSize);
}
