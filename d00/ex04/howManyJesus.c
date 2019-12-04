/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:25:46 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/03 21:57:43 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#define PRIME 33

// simple hash function that encodes all strings of input lenght
size_t	hash(char *string, int len)
{
	size_t hash = 0;
	unsigned char *s = (unsigned char*)string;

	while (len--)
		hash = hash * PRIME + (*s++);
	return (hash);
}

//Traverses the entire bible, hashing at every character, then moving forward
int		howManyJesus(char *bible, char *jesus)
{
	size_t count = 0;
	size_t len = strlen(jesus);
	size_t find = hash(jesus, len);

	while (*bible)
	{
		if (hash(bible, len) == find)
			count++;
		bible++;
	}
	return (count);
}
