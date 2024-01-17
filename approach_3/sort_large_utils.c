/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:22:21 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 17:08:04 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_n_commands(char *command, int n)
{
	while (n != 0)
	{
		ft_printf("%s\n", command);
		n--;
	}
	return ;
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

ssize_t	get_next_min(int **a, size_t size, int prev_smallest)
{
	int		next_smallest;
	ssize_t	next_smallest_i;
	size_t	i;

	next_smallest = INT_MAX;
	next_smallest_i = -1;
	i = 0;
	if (prev_smallest == -1)
		return (-1);
	while (i < size)
	{
		if (a[i][0] > prev_smallest && a[i][0] < next_smallest)
		{
			next_smallest = a[i][0];
			next_smallest_i = i;
		}
		i++;
	}
	return (next_smallest_i);
}

int	move_count(int **stack, size_t index)
{
	size_t	stack_size;

	stack_size = get_arr_size(stack);
	if (index <= stack_size / 2)
		return (index);
	else
		return (index - stack_size);
}
//if reverse rotations are needed, returns a neg. number