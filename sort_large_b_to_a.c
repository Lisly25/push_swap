/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:24:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 11:46:50 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*pa_just_rotate_a(t_stacks *stacks, int moves)
{
	while (moves > 0)
	{
		stacks = ft_rotate_a(stacks);
		ft_printf("ra\n");
		moves--;
	}
	return (stacks);
}

static t_stacks	*pa_just_rev_rotate_a(t_stacks *stacks, int moves)
{
	while (moves < 0)
	{
		stacks = ft_rev_rotate_a(stacks);
		ft_printf("rra\n");
		moves++;
	}
	return (stacks);
}

t_stacks	*move_b_to_a(t_stacks *stacks)
{
	ssize_t	a_min;
	ssize_t	a_max;
	ssize_t	next_larger;
	int		moves;

	a_min = get_min(stacks->a);
	a_max = get_max(stacks->a);
	next_larger = get_next_larger(stacks->a, stacks->b[0][0]);
	if (stacks->b[0][0] > stacks->a[a_max][0])
		moves = move_count(stacks->a, a_min);
	else if (stacks->b[0][0] < stacks->a[a_min][0])
		moves = move_count(stacks->a, a_min);
	else
		moves = move_count(stacks->a, next_larger);
	if (moves > 0)
		stacks = pa_just_rotate_a(stacks, moves);
	else if (moves < 0)
		stacks = pa_just_rev_rotate_a(stacks, moves);
	stacks = ft_push_to_a(stacks);
	ft_printf("pa\n");
	return (stacks);
}
