/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:06:39 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/10 16:08:20 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	get_max(int **a, size_t count)
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

static int	get_next_min(int **a, size_t count, int prev_smallest, int max)
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


static int	get_move_to_top_first(int index, size_t count)
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

static int	get_move_to_top_rest(int index, int index_prev, size_t size, int **a)
{
	int	mid_sort_index;
	int	i;
	int	count;

	count = 0;
	if (index > index_prev)
	{
		while (i != index_prev)
		{
			if (a[i++][0] < a[index][0])
				count++;
		}
		mid_sort_index = index_prev - count - index - 1;
	}
	else//trying to count the small numbers that've already been pushed from the stack
	{
		while (i != index)
		{
			if (a[i++][0] < a[index][0])
				count++;
		}
		i = index_prev + 1;
		while (i < size)
		{
			if (a[i++][0] < a[index][0])
				count++;
		}
		mid_sort_index = ;
	}
}

char	*sort_pair(int **a, size_t count, int num1_index, int num2_index)
{
	char	*result;
	int		num1_move_count;
	int		num2_move_count;

	num1_move_count = get_moves_to_top(num1_index, count);
	num2_move_count = get_moves_to_top(num2_index, count);
	if (num1_move_count > num2_move_count);
	{
		if (num2_index > count / 2)
			
	}
	else
	
}*/


/*if previous num pair has been moved smaller first, sort = 'o'.
If it had been larger first, o = 'r'
If this is the 1st pair being sorted, sort = 'n'*/

static ssize_t	get_real_i(int **a, ssize_t index, t_sort_status *status)
{
	if (status->prev_low == -1)
		return (index);
	if (status->prev_method == 'o')
	{
		
	}
	if (status->prev_method == 'r')
	{
		
	}
}

static size_t	move_count(int **a, ssize_t index, t_sort_status *status)
{
	ssize_t	real_index;

	real_index = get_real_i(a, index, status);
	if (real_index <= (status->real_size / 2))
		return (real_index);
	else
		return (status->real_size - real_index);
}

static void	sort_pair(int **a, t_sort_status *status, size_t size)
{
	size_t	move_low_to_top;
	size_t	move_high_to_top;

	move_low_to_top = move_count(a, status->pair_lower, status);
	move_high_to_top = move_count(a, status->pair_higher, status);
	if (move_high_to_top < (move_low_to_top - 1))
		move_high_first();
	else
		move_low_first();
	return ;
}

void	sort_large(int **a, size_t size)
{
	t_sort_status	*status;

	status = init_sort_status(a, size);
	if (status == NULL)
		return ;
	while (status->real_size > 0)
	{
		sort_pair(a, status, size);
		status->pair_lower = get_next_min(a, size, a[status->pair_higher][0]);
		status->pair_higher = get_next_min(a, size, a[status->pair_lower][0]);
		if (status->pair_higher == -1 && status->pair_lower != -1)
		{
			print_n_commands("pa", ((int)size - 1));
			free(status);
			return ;
		}
	}
	print_n_commands("pa", (int)size);
	free(status);
	return ;
}
