/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:06:39 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/06 11:58:31 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(int **a, size_t count)
{
	int		min;
	size_t	i;

	i = 0;
	min = INT_MAX;
	while (i < count)
	{
		if (a[i][0] < min)
			min = a[i][0];
		i++;
	}
	return (min);
}

static int	get_max(int **a, size_t count)
{
	int		max;
	size_t	i;

	i = 0;
	max = INT_MIN;
	while (i < count)
	{
		if (a[i][0] > max)
			max = a[i][0];
		i++;
	}
	return (max);
}

static int	get_next_smallest(int **a, size_t count, int prev_smallest, int max)
{
	int		next_smallest;
	size_t	i;

	next_smallest = max;
	while (i < count)
	{
		if (a[i][0] > prev_smallest && a[i][0] < next_smallest)
			next_smallest = a[i][0];
		i++;
	}
	return (next_smallest);
}
//will need a similar section that returns the actual commands
static int	get_moves_to_get_to_top(int index, size_t count)
{
	size_t	median;
	int		moves;

	median = count / 2;
	if (index <= median)
		moves = index;
	else
		moves = count - index;
	return (moves);
}

char	*sort_large(int **a, size_t count)
{
	int	max;
	int	min;

	max = get_max(a, count);
	min = get_min(a, count);
	ft_printf("%d %d %d %d\n", a[0][0], count, max, min);
	return ("Nothing for now\n");
}
