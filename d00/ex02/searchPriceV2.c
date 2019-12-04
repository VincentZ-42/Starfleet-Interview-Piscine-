/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:04:25 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/03 11:25:23 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		binary_search(struct s_art **arts, int start, int end, char *name)
{
	if (start < end)
	{
		int middle = start + (end - start) / 2;
		int match = strcmp(arts[middle]->name, name);
		if (match == 0)
			return (arts[middle]->price);
		else if (match > 0)
		   return (binary_search(arts, start, middle - 1, name));
 		else
			return (binary_search(arts, middle + 1, end, name));		
	}
	return (-1);
}

int		searchPrice(struct s_art **arts, int n, char *name)
{
	return (binary_search(arts, 0, n - 1, name));
}
