/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/16 17:49:33 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ra_and_push(int ***a, int ***b, size_t moves, size_t stack_size)
{
	while (moves != 0)
	{
		*a = ft_rotate(a, b);
		ft_printf("ra\n");
		moves--;
	}
	//printf("After rotation\n");
	//print_int_arr(*a);
	*b = ft_push(a, b, stack_size);
	//printf("After push\n");
	//print_int_arr(*a);
	ft_printf("pb\n");
	return (stack_size - 1);
}

static size_t	rra_and_push(int ***a, int ***b, size_t moves, size_t size_a)
{
	while (moves != 0)
	{
		*a = ft_rev_rotate(a, b);
		ft_printf("rra\n");
		moves--;
	}
	//printf("After rev rotation\n");
	//print_int_arr(*a);
	*b = ft_push(a, b, size_a);
	ft_printf("pb\n");
	return (size_a - 1);
}

static size_t	move_other_half(int ***a, int ***b, size_t size_of_a)
{
	size_t	index;
	size_t	move_index_to_top;

	//print_int_arr(*a);
	index = get_min(*a, size_of_a);
	move_index_to_top = move_count(size_of_a, index);
	if (move_index_to_top <= size_of_a / 2)
		size_of_a = ra_and_push(a, b, move_index_to_top, size_of_a);
	else
		size_of_a = rra_and_push(a, b, move_index_to_top, size_of_a);
	return (size_of_a);
}

static size_t	sort_pair(int ***a, int ***b, ssize_t smaller, ssize_t larger)
{
	size_t	move_to_top_small;
	size_t	move_to_top_large;
	size_t	size_of_a;

	size_of_a = get_arr_size(*a);
	move_to_top_small = move_count(size_of_a, smaller);
	move_to_top_large = move_count(size_of_a, larger);
	if (move_to_top_large < (move_to_top_small - 1))
	{
		if (larger <= size_of_a / 2)
			size_of_a = ra_and_push(a, b, move_to_top_large, size_of_a);
		else
			size_of_a = rra_and_push(a, b, move_to_top_large, size_of_a);
		size_of_a = move_other_half(a, b, size_of_a);
		ft_swap_b(a, b);
	}
	else
	{
		if (smaller <= size_of_a / 2)
			size_of_a = ra_and_push(a, b, move_to_top_small, size_of_a);
		else
			size_of_a = rra_and_push(a, b, move_to_top_small, size_of_a);
		size_of_a = move_other_half(a, b, size_of_a);
	}
	return (size_of_a);
}

void	sort_large(int ***stack_a, int ***stack_b, size_t size)
{
	ssize_t	pair_small;
	ssize_t	pair_large;
	size_t	original_size;
	int		**a;

	original_size = size;
	a = *stack_a;
	while (size > 1)
	{
		pair_small = get_min(a, size);
		pair_large = get_next_min(a, size, a[pair_small][0]);
		if (pair_large != -1 && pair_large != -1)
			size = sort_pair(stack_a, stack_b, pair_small, pair_large);
		else
		{
			ft_printf("Error\n");
			return ;
		}
		printf("After sorting pair, a is:\n");
		print_int_arr(*stack_a);
	}
	if (size == 1)
		print_n_commands("pa", (original_size - 1));
	else
		print_n_commands("pa", original_size);
	printf("Stack b is:\n");
	print_int_arr(*stack_b);
}
