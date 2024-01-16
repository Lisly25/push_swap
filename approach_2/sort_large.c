/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/16 10:34:15 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ra_and_push(int **a, int **b, size_t moves, size_t stack_size)
{
	while (moves != 0)
	{
		ft_rotate(a, b);
		ft_printf("ra\n");
		moves--;
	}
	b = ft_push(&a, &b, stack_size);
	ft_printf("pb\n");
	return (stack_size - 1);
}

static size_t	rra_and_push(int **a, int **b, size_t moves, size_t stack_size)
{
	while (moves != 0)
	{
		ft_rev_rotate(a, b);
		ft_printf("rra\n");
		moves--;
	}
	b = ft_push(&a, &b, stack_size);
	ft_printf("pb\n");
	return (stack_size - 1);
}

static size_t	move_other_half(int ***a, int ***b, size_t size_of_a)
{
	size_t	index;
	size_t	move_index_to_top;

	index = get_min(*a, size_of_a);
	move_index_to_top = move_count(size_of_a, index);
	if (move_index_to_top <= size_of_a / 2)
		size_of_a = ra_and_push(*a, *b, move_index_to_top, size_of_a);
	else
		size_of_a = rra_and_push(a, b, move_index_to_top, size_of_a);
	return (size_of_a);
}

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
			size_of_a = ra_and_push(a, b, move_to_top_large, size_of_a);
		else
			size_of_a = rra_and_push(a, b, move_to_top_large, size_of_a);
		size_of_a = move_other_half(&a, &b, size_of_a);
		ft_swap_b(&a, &b);
	}
	else
	{
		if (smaller <= size_of_a / 2)
			size_of_a = ra_and_push(a, b, move_to_top_small, size_of_a);
		else
			size_of_a = rra_and_push(a, b, move_to_top_small, size_of_a);
		size_of_a = move_other_half(&a, &b, size_of_a);
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
