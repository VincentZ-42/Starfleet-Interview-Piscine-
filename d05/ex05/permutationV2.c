/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:17:50 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:34:26 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

typedef struct s_dict t_dict;

void	swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/*
** Function that permutes string by swaping characters then storing...
** all permute strings into dictionary, so we don't print duplicates
*/

void	permute(char *str, int l, t_dict *dict)
{
	if (!str[l] && dictSearch(dict, str) == -1)
	{
		dictInsert(dict, str, 1);
		printf("%s\n", str);
	}
	for (int i = l; str[i]; i++)
	{
		swap(&str[l], &str[i]);
		permute(str, l + 1, dict);
		swap(&str[l], &str[i]);
	}
}

void	printUniquePermutations(char *str)
{
	int start = 0;
	t_dict *dict = dictInit(strlen(str));
	permute(str, start, dict);
}
