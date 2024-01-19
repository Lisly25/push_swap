/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:22:21 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 13:47:18 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_absolute_values(int rotates_src, int rotates_dest)
{
	if (rotates_dest < 0)
		rotates_dest = -rotates_dest;
	if (rotates_src < 0)
		rotates_src = -rotates_src;
	return (rotates_dest + rotates_src);
}

ssize_t	get_min(int **stack)
{
	int		min;
	ssize_t	min_index;
	size_t	i;
	size_t	stack_size;

	i = 0;
	min_index = -1;
	min = INT_MAX;
	stack_size = get_arr_size(stack);
	while (i < stack_size)
	{
		if (stack[i][0] < min)
		{
			min = stack[i][0];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

ssize_t	get_max(int **stack)
{
	int		max;
	ssize_t	max_index;
	size_t	i;
	size_t	stack_size;

	i = 0;
	max_index = -1;
	max = INT_MIN;
	stack_size = get_arr_size(stack);
	while (i < stack_size)
	{
		if (stack[i][0] > max)
		{
			max = stack[i][0];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

ssize_t	get_one_smaller(int **stack, int prev_num)
{
	int		next_smaller;
	ssize_t	next_smaller_i;
	size_t	i;
	size_t	size;

	next_smaller_i = get_min(stack);
	next_smaller = stack[next_smaller_i][0];
	size = get_arr_size(stack);
	//printf("Smallest num in stack is %d, num the neighbour of which we're looking for is %d\n", next_smaller, prev_num);
	i = 0;
	while (i < size)
	{
		//printf("Segfault here?\n");
		if (stack[i][0] < prev_num && stack[i][0] > next_smaller)
		{
			//printf("Stack at i:%d\n", stack[i][0]);
			next_smaller = stack[i][0];
			next_smaller_i = i;
		}
		i++;
	}
	//printf("If num is %d, the one just smaller than it is %d\n", prev_num, stack[next_smaller_i][0]);
	return (next_smaller_i);
}

ssize_t	get_next_larger(int **stack, int num)
{
	int		next_larger;
	ssize_t	next_larger_i;
	size_t	i;
	size_t	size;

	next_larger = INT_MAX;
	next_larger_i = -1;
	size = get_arr_size(stack);
	i = 0;
	while (i < size)
	{
		if (stack[i][0] > num && stack[i][0] < next_larger)
		{
			next_larger = stack[i][0];
			next_larger_i = i;
		}
		i++;
	}
	return (next_larger_i);
}

int	move_count(int **stack, ssize_t index)
{
	size_t	stack_size;
	int		stack_size_int;
	int		index_int;
	int		move_count;

	stack_size = get_arr_size(stack);
	stack_size_int = (int)stack_size;
	index_int = (int)index;
	//printf("In move count, stack size is %d, index is %d\n", stack_size_int, index_int);
	if (index_int <= (stack_size_int / 2))
		move_count = index_int;
	else
		move_count = index_int - stack_size_int;
	//printf("Move count is:%d\n", move_count);
	return (move_count);
}
