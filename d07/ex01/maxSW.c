/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:56:29 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/13 17:12:13 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <limits.h>
# define CE(x) create_elem(x)

typedef struct s_deque t_deque;
typedef struct s_dequeNode t_dequeNode;
typedef struct s_max t_max;

t_dequeNode		*create_elem(int value)
{
	t_dequeNode *new = (t_dequeNode*)malloc(sizeof(t_dequeNode));

	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

struct s_deque	*dequeInit(void)
{
	t_deque *fresh = (t_deque*)malloc(sizeof(t_deque));

	if (fresh == NULL)
		return (NULL);
	
	fresh->first = NULL;
	fresh->last = NULL;
	return (fresh);
}

void	pushFront(struct s_deque *deque, int value)
{
	if (!deque)
		return ;
	t_dequeNode *first = deque->first;
	deque->first = CE(value);
	if (!first)
		deque->last = deque->first;
	else
	{
		deque->first->next = first;
		first->prev = deque->first;
	}
}

void	pushBack(struct s_deque *deque, int value)
{
	if (!deque)
		return ;
	t_dequeNode *last = deque->last;
	deque->last = CE(value);
	if (!last)
		deque->first = deque->last;
	else
	{
		deque->last->prev = last;
		last->next = deque->last;
	}
}

int		popFront(struct s_deque *deque)
{
	if (!deque || !deque->first)
		return (INT_MIN);
	
	t_dequeNode *temp = deque->first;
	int value = temp->value;

	deque->first = temp->next;
	if (!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	free(temp);
	return (value);
}

int		popBack(struct s_deque *deque)
{
	if (!deque || !deque->last)
		return (INT_MIN);

	t_dequeNode *temp = deque->last;
	int value = temp->value;
	deque->last = temp->prev;
	if (!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	free(temp);
	return (value);
}

int		isEmpty(struct s_deque *deque)
{
	if (!deque || !deque->first)
		return (1);
	return (0);
}

int		peekFront(t_deque *deque)
{
	if (!deque->first)
		return (INT_MIN);
	return (deque->first->value);
}

int		peekBack(t_deque *deque)
{
	if (!deque->last)
		return (INT_MIN);
	return (deque->last->value);
}

t_max	*createArr(int n)
{
	t_max *fresh = malloc(sizeof(t_max));
	fresh->length = n;
	fresh->max = malloc(sizeof(int) * n);
	return (fresh);
}

// Function that creates a queue and uses it like a hash table as we traverse our arr
// Alternating between checking the front and checking the back to see if max is reached
// Will probablity need to do this on paper to prove it to yourself
struct s_max	*maxSlidingWindow(int *arr, int n, int k)
{
	t_deque *deque = dequeInit();
	t_max	*ans = createArr(n - k + 1);
	int i = 0;
	int j = 0;
	
	for (i = 0; i < n; i++)
	{
		if (!isEmpty(deque) && peekFront(deque) == i - k)
			popFront(deque);
		while (!isEmpty(deque) && arr[peekBack(deque)] < arr[i])
			popBack(deque);
		pushBack(deque, i);
		if (i >= k - 1)
			ans->max[j++] = arr[peekFront(deque)];
	}
	return (ans);
}
