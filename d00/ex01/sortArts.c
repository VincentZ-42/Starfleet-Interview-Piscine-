/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:01:18 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/03 11:01:09 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h> // need this lib for strcmp

/*
 * We will use merge_sort algorithm because it uses O(nlogn) time
 * merge_sort continuously breaks our list into halves until there is only 2 elements left
 * Then it orders each element as it goes back down the stack
*/

static void	merge(struct s_art **arts, int s, int m, int e)
{
	int i, j;
	int len1 = m - s + 1;
	int len2 = e - m;
	struct s_art *L[len1];
	struct s_art *R[len2];

	for (i = 0; i < len1; i++)
		L[i] = arts[s + i];
	for (j = 0; j < len2; j++)
		R[j] = arts[m + 1 + j];
	i = 0;
	j = 0;
	while (i < len1 && j < len2)
	{
		if (strcmp(L[i]->name, R[j]->name) <= 0)
			arts[s++] = L[i++];
		else
			arts[s++] = R[j++];
	}
	while (i < len1)
		arts[s++] = L[i++];
	while (j < len2)
		arts[s++] = R[j++];
}

static void		merge_sort(struct s_art **arts, int start, int end)
{
	if (start < end)
	{
		int middle = start + (end - start) / 2;
		merge_sort(arts, start, middle);
		merge_sort(arts, middle + 1, end);
		merge(arts, start, middle, end);
	}
}

void			sortArts(struct s_art **arts)
{
	int len;

	len = 0;
	while (arts[len])
		len++;
	merge_sort(arts, 0, len - 1);
}

