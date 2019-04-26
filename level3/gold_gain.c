/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 02:26:50 by maparmar          #+#    #+#             */
/*   Updated: 2019/04/26 03:30:19 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define max(a, b) (a > b ? a : b)
int gold_gain(int **mine, int n)
{
	int row = n, col = n;
	int r, c;
	for (c = col -1; c >= 0; c--)
	{	
		for (r = row -1; r >= 0; r--)
		{
			int right = (c == col -1) ? 0 : mine[r][c + 1]; // to go right
			int right_up = (c == col -1 || r == 0) ? 0 : mine[r - 1][c + 1]; // to go right_up
			int right_down = (c == col -1 || r == row -1) ?  0  : mine[r + 1][c + 1]; // to go right_down

			mine[r][c] += max(right, max(right_down, right_up)); // updte the mine matrix and start from the bottom right and traverse by column
		}
	}
	int max_gold = mine[0][0];
	for (r = 1; r < row; r++) // find the max in the first column and that's the answer.
	{
		max_gold = max(max_gold, mine[r][0]);
	}
	return max_gold;
}
/**************
	TEST MAIN
**************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int side;
	printf("Enter the side of the matrix and press enter after entering it\n");
	scanf("%d", &side);
	printf("Please enter each element one by one starting from 1st row and press enter after entering each element\n");
	int **mine = (int **)malloc(sizeof(int *) * side);
	for(int r = 0; r < side; r++)
	{
		mine[r] = (int *)malloc(sizeof(int) * side);
		for(int c = 0; c < side; c++)
		{
			scanf("%d", &(mine[r][c]));
		}
	}
	printf("Please wait 😀😀😀😀😀😀😀\n");
	clock_t start_time = clock();
	while (clock() < start_time + 5000000)
		;
	printf("The max gold gain is: %d\n", gold_gain(mine, side));
	return 0;
}