/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 13:37:02 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*ra_and_push(t_stacks *stacks, size_t moves, size_t stack_size)
{
	while (moves != 0)
	{
		stacks = ft_rotate(stacks);
		ft_printf("ra\n");
		moves--;
	}
	stacks = ft_push_to_b(stacks, stack_size);
	ft_printf("pb\n");
	return (stacks);
}

static t_stacks	*rra_and_push(t_stacks *stacks, size_t moves, size_t size_a)
{
	while (moves != 0)
	{
		stacks = ft_rev_rotate(stacks);
		ft_printf("rra\n");
		moves--;
	}
	stacks = ft_push_to_b(stacks, size_a);
	ft_printf("pb\n");
	return (stacks);
}

static t_stacks	*move_other_half(t_stacks *stacks)
{
	size_t	index;
	size_t	move_index_to_top;
	size_t	size_of_a;

	size_of_a = get_arr_size(stacks->a);
	index = get_min(stacks->a, size_of_a);
	move_index_to_top = move_count(size_of_a, index);
	if (index <= size_of_a / 2)
		stacks = ra_and_push(stacks, move_index_to_top, size_of_a);
	else
		stacks = rra_and_push(stacks, move_index_to_top, size_of_a);
	return (stacks);
}

static t_stacks	*sort_pair(t_stacks *stacks, ssize_t smaller, ssize_t larger)
{
	size_t	move_to_top_small;
	size_t	move_to_top_large;
	size_t	size_of_a;

	size_of_a = get_arr_size(stacks->a);
	move_to_top_small = move_count(size_of_a, smaller);
	move_to_top_large = move_count(size_of_a, larger);
	if (move_to_top_large < (move_to_top_small - 1))
	{
		if (larger <= size_of_a / 2)
			stacks = ra_and_push(stacks, move_to_top_large, size_of_a);
		else
			stacks = rra_and_push(stacks, move_to_top_large, size_of_a);
		stacks = move_other_half(stacks);
		stacks = ft_swap(stacks, 'b');
	}
	else
	{
		if (smaller <= size_of_a / 2)
			stacks = ra_and_push(stacks, move_to_top_small, size_of_a);
		else
			stacks = rra_and_push(stacks, move_to_top_small, size_of_a);
		stacks = move_other_half(stacks);
	}
	return (stacks);
}

void	sort_large(t_stacks *stacks, size_t size)
{
	ssize_t	pair_small;
	ssize_t	pair_large;
	size_t	original_size;

	original_size = size;
	while (size > 1)
	{
		pair_small = get_min(stacks->a, size);
		pair_large = get_next_min(stacks->a, size, stacks->a[pair_small][0]);
		if (pair_large != -1 && pair_large != -1)
		{
			stacks = sort_pair(stacks, pair_small, pair_large);
			size = size - 2;
		}
		else
		{
			ft_printf("Error\n");
			return ;
		}
	}
	if (size == 1)
		print_n_commands("pa", (original_size - 1));
	else
		print_n_commands("pa", original_size);
}
