/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:22:21 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 14:01:42 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	i = 0;
	while (i < size)
	{
		if (stack[i][0] < prev_num && stack[i][0] > next_smaller)
		{
			next_smaller = stack[i][0];
			next_smaller_i = i;
		}
		i++;
	}
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
	if (index_int <= (stack_size_int / 2))
		move_count = index_int;
	else
		move_count = index_int - stack_size_int;
	return (move_count);
}
