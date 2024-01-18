/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/18 16:20:04 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_pb(t_stacks *stacks, size_t index)
{
	ssize_t	b_min;
	ssize_t	b_max;
	int		moves;
	ssize_t	next_smallest;

	b_min = get_min(stacks->b);
	b_max = get_max(stacks->b);
	next_smallest = get_next_min(stacks->b, stacks->a[index][0]);
	if (stacks->a[index][0] > stacks->b[b_max][0])
		moves = move_count(stacks->b, b_max);
	else if (stacks->a[index][0] < stacks->b[b_min][0])
		moves = move_count(stacks->b, b_max);
	else
		moves = move_count(stacks->b, next_smallest);
	return (moves);
}

int	combined_rotation_moves(t_stacks *stacks, size_t index)
{
	int	rotates_src;
	int	rotates_dest;
	int	rotates_all;

	rotates_src = move_count(stacks->a, index);
	rotates_dest = get_moves_pb(stacks, index);
	if (rotates_dest >= 0 && rotates_src >= 0)
	{
		if (rotates_dest > rotates_src)
			rotates_all = rotates_dest;
		else
			rotates_all = rotates_src;
	}
	else if (rotates_dest < 0 && rotates_src < 0)
	{
		if (rotates_dest > rotates_src)
			rotates_all = -rotates_src;
		else
			rotates_all = -rotates_dest;
	}
	else
		rotates_all = add_absolute_values(rotates_src, rotates_dest);
	return (rotates_all);
}

static ssize_t	get_cheapest_to_p_to_b(t_stacks *stacks)
{
	size_t	i;
	size_t	cheapest_i;
	int		rotates_all;
	int		least_moves;

	i = 0;
	cheapest_i = 0;
	least_moves = INT_MAX;
	while (stacks->b[i] != NULL)
	{
		rotates_all = combined_rotation_moves(stacks, i);
		if (rotates_all < least_moves)
			cheapest_i = i;
		i++;
	}
	return (cheapest_i);
}

static t_stacks	*rotate_a_final(t_stacks *stacks)
{
	size_t	min;
	int		moves;

	min = get_min(stacks->a);
	moves = move_count(stacks->a, min);
	while (moves < 0)
	{
		stacks = ft_rev_rotate_a(stacks);
		ft_printf("rra\n");
		moves++;
	}
	while (moves > 0)
	{
		stacks = ft_rotate_a(stacks);
		ft_printf("ra\n");
		moves++;
	}
	return (stacks);
}

void	sort_large(t_stacks *stacks, size_t size)
{
	ssize_t	next_to_be_moved;
	size_t	original_size;

	original_size = size;
	stacks = ft_push_to_b(stacks);
	stacks = ft_push_to_b(stacks);
	ft_printf("pb\npb\n");
	size = size - 2;
	while (size > 3)
	{
		next_to_be_moved = get_cheapest_to_p_to_b(stacks);
		stacks = move_a_to_b(stacks, next_to_be_moved);
		size--;
	}
	stacks = sort_last_3_large(stacks);
	while (size != original_size)
	{
		stacks = move_b_to_a(stacks);
		size++;
	}
	stacks = rotate_a_final(stacks);
	return ;
}
