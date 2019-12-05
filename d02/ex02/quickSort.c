/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:19:34 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/05 11:05:20 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

typedef struct s_player t_player;

// Swaps the address of elements in the array
void		swap(t_player **a, t_player **b)
{
	t_player *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Paritition can be anything, we choose to use the last element as pivot
// This function takes array, the 1st element and the pivot element
// And swaps element's address based on its value in comparison to the pivot 
int			partition(t_player **players, int lo, int hi)
{
	int pivot = players[hi]->score;
	int i = lo - 1;

	for (int j = lo; j < hi; j++)
		if (players[j]->score > pivot)
			swap(&players[++i], &players[j]);
	swap(&players[i + 1], &players[hi]);
	return (i + 1);

}

// Picks a partition depending on function above and performs quicksort...
// to one iteration above and below chosen partition
void		recur(t_player **players, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(players, lo, hi);
		recur(players, lo, p - 1);
		recur(players, p + 1, hi);
	}
}

// Quicksort
// Finds length of array and passes it into recursive function above
// Similar to Merge Sort, QuickSort is a divide and conquer algorithm...
// - It picks an element as pivot and partitions the given array around the pivot
// - It keeps doing this recursively until there are no more elements to pivot
// - And your array will be sorted when the recursion ends
void		quickSort(struct s_player **players)
{
	int		len = 0;
	
	while (players[len])
		len++;
	recur(players, 0, len - 1);
}
