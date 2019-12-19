/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:06:18 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/13 19:59:35 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_sellers	*closestSellers(struct s_graph *graph, char *youAreHere)
{
	struct s_queue	*q = queueInit();
	struct s_node	*cur = NULL;
	struct s_sellers *ans = (struct s_sellers*)malloc(sizeof(struct s_sellers));
	int				len, dist, i, j, k;

	// Finding the length of my graph (how long is my list of places)
	// We also find our current location based off 2nd argument
	for (len = 0; graph->places[len]; len++)
		if (strcmp(graph->places[len]->name, youAreHere) == 0)
			cur = graph->places[len];

	// Here we malloc and initialize all variables that will be used
	ans->placeNames = (char**)malloc(sizeof(char*) * len);
	if (!cur || !ans || !ans->placeNames)
		return (NULL);
	cur->visited = 0;
	enqueue(q, cur);
	k = 0; // This is index of ans list
	dist = 0; // This is distance we have to travel to nearest store
	for (i = 0; i < len; i++)
	{
		cur = dequeue(q);
		if (!cur)
			break ;
		// Once we find a store, we will have d, but we want to make sure...
		// ...that there may be other stores with the same dist nearby...
		// ...Thus we will stop looking once the distance increases greater...
		// ...than the last store we've found
		if (dist > 0 && cur->visited > dist)
			break ;

		// If store has CerealBar, we add the name into our answer list
		// Distance is always set to equal the same number if mutiple stores...
		// ...are the same distance from our spot
		if (cur->hasCerealBar)
		{
			ans->distance = cur->visited;
			ans->placeNames[k++] = cur->name;
			dist = cur->visited;
		}
		else
		{
			// If store does not have CerealBar, then we look at all the places...
			// ...connected to that store and add that to our queue to search...
			// ...making sure to increase our distance by one everytime we move...
			// ...to a different node
			// NOTE: we are used visited int to track distance and not as...
			// ...a boolean as stated in header file
			for (j = 0; cur->connectedPlaces[j]; j++)
				if (cur->connectedPlaces[j]->visited == 0)
				{
					cur->connectedPlaces[j]->visited = cur->visited + 1;
					enqueue(q, cur->connectedPlaces[j]);
				}
		}
		// Increase the distance to the visited store to some arbitary number...
		// ...so we don't encounter it again
		cur->visited += 100;
	}
	ans->placeNames[k] = NULL;	// Don't forget to null terminate your array
	return (ans);
}
