/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:21:14 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/04 09:24:16 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define PRIME 33
#define SIZE_T_MAX 

size_t		hash(char *input)
{
	size_t hash = 0;

	while (*input)
		hash = hash * PRIME + (unsigned char)(*input++);
	return (hash);
}

// Initiates our dictionary
// capacity is the size of our array
// Note the use of malloc and calloc here
// Option to use memset instead of calloc here
struct s_dict	*dictInit(int capacity)
{
	struct s_dict *dict;

	if (capacity < 1)
		return (NULL);
	if (!(dict = (struct s_dict*)malloc(sizeof(struct s_dict))))
		return (NULL);
	if (!(dict->items = (struct s_item**)calloc(capacity, sizeof(struct s_item))))
		return (NULL);
	//memset(dict->items, 0, capacity);
	dict->capacity = capacity;
	return (dict);
}

// Inserts the name:value of art piece pair into our dictionary after hasing it
// If it can't find the element, we create a new one
// Else, we see if there are any existing elements and create a linked list to it
int			dictInsert(struct s_dict *dict, char *key, int value)
{
	struct s_item *temp;
	size_t i;

	i = hash(key) % dict->capacity;
	if (!dict->items[i])
	{
		if (!(dict->items[i] = (struct s_item*)malloc(sizeof(struct s_item))))
			return (0);
		dict->items[i]->key = key;
		dict->items[i]->value = value;
		dict->items[i]->next = NULL;		
	}
	else
	{
		temp = dict->items[i];
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = (struct s_item*)malloc(sizeof(struct s_item))))
			return (0);
		temp->next->key = key;
		if (!temp->next || !temp->next->key)
			return (0);
		temp->next->value = value;
		temp->next->next = NULL;
	}
	return (1);
}

// Hashes the name of the art piece and looks up the key in our hash table
// if we find it, we return the struct containing the info
int		dictSearch(struct s_dict *dict, char *key)
{
	struct s_item *temp;
	size_t i;

	i = hash(key) % dict->capacity;
	temp = dict->items[i];
	while (temp)
	{
		if (!strcmp(key, temp->key))
			return (temp->value);
		temp = temp->next;
	}
	return (-1);
}

// joins two strings together
char		*strjoin(char *s1, char *s2)
{
	int len = strlen(s1) + strlen(s2) + 1;
	char *ret;

	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	strcat(ret, s1);
	strcat(ret,s2);
	ret[len] = '\0';
	free(s1);
	return (ret);
}

char		*make_header(struct s_dict *dict)
{
	char *header;
	struct s_item *temp;

	// need 3 bytes to fit '<', '>', and '\0' characters
	if (!(header = (char*)malloc(sizeof(char) * 2 + 1)))
		return (NULL);
	header[0] = '<';
	for (int i = 0; i < dict->capacity; i++)
	{
		if (dict->items[i] != NULL)
		{
			temp = dict->items[i];
			while (temp)
			{
				header = strjoin(header, temp->key);
				header = strjoin(header, ",");
				temp = temp->next;
			}
		}
	}
	header[strlen(header) - 1] = '>';
	return (header);
}

/*
size_t		get_index(char *book, char *find, size_t len)
{
	size_t 
}

char		*compress(char *book, struct s_dict *dict)
{
	;
}
*/
