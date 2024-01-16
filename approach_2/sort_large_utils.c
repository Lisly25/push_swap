/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:22:21 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/16 17:28:50 by skorbai          ###   ########.fr       */
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

ssize_t	get_min(int **a, size_t count)
{
	int		min;
	ssize_t	min_index;
	size_t	i;

	i = 0;
	min_index = -1;
	min = INT_MAX;
	while (i < count)
	{
		if (a[i][0] < min)
		{
			min = a[i][0];
			min_index = i;
		}
		i++;
	}
	return (min_index);
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

size_t	move_count(size_t stack_size, size_t index)
{
	if (index <= stack_size / 2)
		return (index);
	else
		return (stack_size - index);
}

void	ft_swap_b(int ***a, int ***b)
{
	ft_swap(b, a);
	ft_printf("sb\n");
}
