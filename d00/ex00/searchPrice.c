/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:57:11 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/02 22:38:02 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int		check_match(char *s1, char *s2)
{
	int i;

	i = -1;
	if (strlen(s1) != strlen(s2))
		return (0);
	while (s1[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int		searchPrice(struct s_art **arts, char *name)
{
	int i;

	i = -1;
	if (!*arts || !name)
		return (-1);
	while (arts[++i])
		if (check_match(arts[i]->name, name))
			return (arts[i]->price);
	return (-1);
}
