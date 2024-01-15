/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/15 16:48:20 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	sort_pair(int **a, int **b, ssize_t smaller, ssize_t larger)
{
	size_t	move_to_top_small;
	size_t	move_to_top_large;
	size_t	size_of_a;

	size_of_a = get_arr_size(a);
	move_to_top_small = move_count(size_of_a, smaller);
	move_to_top_large = move_count(size_of_a, larger);
	if (move_to_top_large < (move_to_top_small - 1))
	{
		if (larger <= size_of_a / 2)
			size_of_a = ra_n_times();
		else
			size_of_a = rra_n_times();
		size_of_a = move_other_half_of_pair();
	}
	else
	{
		if (larger <= size_of_a / 2)
			size_of_a = ra_n_times();
		else
			size_of_a = rra_n_times();
		size_of_a = move_other_half_of_pair();
	}
	return (size_of_a);
}

void	sort_large(int **stack_a, int **stack_b, size_t size)
{
	ssize_t	pair_small;
	ssize_t	pair_large;
	size_t	original_size;

	original_size = size;
	while (size > 1)
	{
		pair_small = get_min(stack_a, size);
		pair_large = get_next_min(stack_a, size, pair_small);
		if (pair_large != -1 && pair_large != -1)
			size = sort_pair(stack_a, stack_b, pair_small, pair_large);
		else
		{
			ft_printf("Error\n");
			return ;
		}
	}
	if (size == 1)
		print_n_commands("", (original_size - 1));
	else
		print_n_commands("", original_size);
}
