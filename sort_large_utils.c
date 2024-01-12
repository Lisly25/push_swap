/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:13:07 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/12 11:37:33 by skorbai          ###   ########.fr       */
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
	i = 0;
	while (i < size)
	{
		if (a[i][0] > prev_smallest && a[i][0] < next_smallest)
		{
			next_smallest = a[i][0];
			next_smallest_i = i;
			printf("Next smallest num's index: %zu\n", next_smallest_i);
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

	status = (t_sort_status *)malloc(sizeof(t_sort_status));
	if (status == NULL)
		return (NULL);
	status->pair_lower = get_min(a, size);
	status->pair_higher = get_next_min(a, size, a[status->pair_lower][0]);
	status->prev_low = status->pair_lower;
	status->prev_high = status->pair_higher;
	status->real_size = size;
	status->og_size = size;
	status->prev_method = 'n';
	printf("Initialising. Pair higher: %zu\n", status->pair_higher);
	return (status);
}

size_t	move_count(int **a, ssize_t index, t_sort_status *status)
{
	ssize_t	real_index;

	real_index = get_real_i(a, index, status);
	if ((size_t)real_index <= (status->real_size / 2))
		return (real_index);
	else
		return (status->real_size - real_index);
}
