/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:49:26 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/12 11:09:19 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

// Function that calculates the probablity that random placement of two...
// ...locations will be GREATER than desired distance
// Args:
// int dist = desired distance that between two locations
// int *locations = array of integers representing location from start
// int n = number of elements in array
// Returns:
// probablity of two locations being larger than desired distance

// Note: using two for-loops to find the different between the 1st element...
// ...and the all elements after that, then counting that many times
// Note: We do not traverse backwards because we don't want repeated calculations

double	probaDistance(int dist, int *locations, int n)
{
	int count = 0;
	int total = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (abs(locations[i] - locations[j]) > dist)
				count++;
			total++;
		}
	return ((double)count / total);
}
