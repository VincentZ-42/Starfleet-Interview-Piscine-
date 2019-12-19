/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:27:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/12 22:33:02 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// #ULL = unsigned long long data type of constant #, having 8 bytes
// uint64_t is same as 8 times (unsigned long long data type) so 8x8 board

// Function that gets the initial position of our knight by shifting the board...
// ...one bit at a time until we find a matching bit
int		getInitialPos(uint64_t board)
{
	int pos = 0;

	if (board & 0)
		return (-1);
	while (board)
	{
		if ((board & 1) == 0)
			board >>= 1;
		else if (board & 1ULL)
			return (pos);
		else
			return (-1);
		pos++;
	}
	return (pos);

}

// Function that calculates all probablities and adds them together b/c probabilities...
// ...are independent of each other.
// We mutiple by 0.125 b/c each move is 1/8 chance of exiting board
double	move(int row, int col, int n)
{
	double prob = 0;

	if (n == 0 || row < 0 || col < 0 || row > 7 || col > 7)
		return ((row < 0 || col < 0 || row > 7 || col > 7) ? 1 : 0);

	prob += 0.125 * move(row - 2, col + 1, n - 1);
	prob += 0.125 * move(row - 2, col - 1, n - 1);
	prob += 0.125 * move(row + 2, col + 1, n - 1);
	prob += 0.125 * move(row + 2, col - 1, n - 1);
	prob += 0.125 * move(row - 1, col + 2, n - 1);
	prob += 0.125 * move(row - 1, col - 2, n - 1);
	prob += 0.125 * move(row + 1, col + 2, n - 1);
	prob += 0.125 * move(row + 1, col - 2, n - 1);
	return (prob);
}

// Function that initiates the recursive calls to calculate probability
double	knightOut(uint64_t board, int n)
{
	int pos = getInitialPos(board);
	if (pos == -1 || n < 1)
		return (-1);
	return (move(pos / 8, pos % 8, n));
}

