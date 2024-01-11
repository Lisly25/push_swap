/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:06:39 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/11 11:49:40 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*if previous num pair has been moved smaller first, sort = 'o'.
If it had been larger first, o = 'r'
If this is the 1st pair being sorted, sort = 'n'*/

static void	move_low_first(int **a, size_t moves_low, t_sort_status *status)
{
	size_t	move_high;

	if (get_real_i(a, status->pair_lower, status) <= status->real_size / 2)
		print_n_commands("ra", moves_low);
	else
		print_n_commands("rra", moves_low);
	ft_printf("pb\n");
	status->prev_low = status->pair_lower;
	status->real_size = status->real_size - 1;
	move_high = move_count(a, status->pair_higher, status);
	if (get_real_i(a, status->pair_higher, status) > status->real_size / 2)
		print_n_commands("ra", move_high);
	else
		print_n_commands("rra", move_high);
	ft_printf("pb\n");
	status->prev_high = status->pair_higher;
	status->real_size = status->real_size - 1;
	return ;
}

static void	move_high_first(int **a, size_t moves_high, t_sort_status *status)
{
	size_t	move_low;

	if (get_real_i(a, status->pair_higher, status) <= status->real_size / 2)
		print_n_commands("ra", moves_high);
	else
		print_n_commands("rra", moves_high);
	ft_printf("pb\n");
	status->prev_high = status->pair_higher;
	status->real_size = status->real_size - 1;
	move_low = move_count(a, status->pair_lower, status);
	if (get_real_i(a, status->pair_lower, status) > status->real_size / 2)
		print_n_commands("ra", move_low);
	else
		print_n_commands("rra", move_low);
	ft_printf("pb\n");
	ft_printf("sb\n");
	status->prev_low = status->pair_lower;
	status->real_size = status->real_size - 1;
	return ;
}

static void	sort_pair(int **a, t_sort_status *status, size_t size)
{
	size_t	move_low_to_top;
	size_t	move_high_to_top;

	move_low_to_top = move_count(a, status->pair_lower, status);
	move_high_to_top = move_count(a, status->pair_higher, status);
	if (move_high_to_top < (move_low_to_top - 1))
		move_high_first(a, move_high_to_top, status);
	else
		move_low_first(a, move_low_to_top, status);
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
