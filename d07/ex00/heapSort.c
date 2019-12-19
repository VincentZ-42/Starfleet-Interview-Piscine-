/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:37:49 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/13 15:55:27 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h> // for heapsort function
#include <string.h> // for strcmp function

typedef struct s_art t_art;

// Function that compares two elements in array as needed to be used in
// heapsort in C library
int		compare(const void *a, const void *b)
{
	t_art **A = (t_art**)a;
	t_art **B = (t_art**)b;
	return (strcmp((*A)->name, (*B)->name));
}

// Used heapsort from C Libary
// Man heapsort for further details...
void	heapSort(struct s_art **masterpiece, int n)
{
	heapsort(masterpiece, n, sizeof(t_art*), &compare);
}
