/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:48:19 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:36:59 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

/*
** Function that checks if string is Palindrome
*/

char	*isPalindrome(char *str)
{
	int len = strlen(str) - 1;

	for (int i = 0; i < len; i++)
		if (str[i] != str[len--])
			return (NULL);
	return (str);
}

/*
** Function that shortens string by copying entire string...
** ...except the character at index skip into a new string
*/

char	*shorten(char *str, int skip)
{
	int len = strlen(str), j = 0;
	char *fresh = calloc(len, sizeof(char));

	for (int i = 0; i < len; i++)
		if (i != skip)
			fresh[j++] = str[i];
   return (fresh);	
}

/*
** Function that deletes a character and recursively checks if...
** there is an Palindrome after deleting nDelete amount of chars
** Args:
** sequence = string with random extra characters
** nDelete = number of characters to delete
** Returns:
** Null for failure
** Palindrome string if success
*/

char	*findPalindrome(char *sequence, int nDelete)
{
	char *temp, *result;

	if (!sequence || !nDelete)
		return (isPalindrome(sequence));
	for (int i = 0; sequence[i]; i++) {
		temp = shorten(sequence, i);
		if ((result = findPalindrome(temp, nDelete - 1)))
			return (result);
		free(temp);
	}
	return (NULL);
}
