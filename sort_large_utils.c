/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:13:07 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/10 15:56:37 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_n_commands(char *command, int n)
{
	while (n != 0)
	{
		ft_printf("%s\n", command);
		n--;
	}
	return ;
}

t_sort_status	*init_sort_status(int **a, size_t size)
{
	t_sort_status	*status;

	status = (t_sort_status *)malloc(sizeof(t_sort_status *));
	if (status == NULL)
		return (NULL);
	status->pair_lower = get_min(a, size);
	status->pair_higher = get_next_min(a, size, a[status->pair_lower][0]);
	status->prev_low = -1;
	status->prev_high = -1;
	status->real_size = size;
	status->prev_method = 'n';
	return (status);
}