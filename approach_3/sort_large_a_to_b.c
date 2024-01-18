/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:58:50 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/18 12:25:35 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*rotate_both(t_stacks *stacks, int rotates_a, int rotates_b)
{
	while (rotates_a > 0 && rotates_a > 0)
	{
		ft_rr(stacks);
		ft_printf("rr\n");
		rotates_a--;
		rotates_b--;
	}
	while (rotates_a > 0)
	{
		ft_rotate_a(stacks);
		ft_printf("ra\n");
		rotates_a--;
	}
	while (rotates_b > 0)
	{
		ft_rotate_b(stacks);
		ft_printf("rb\n");
		rotates_b--;
	}
	return (stacks);
}

t_stacks	*move_a_to_b(t_stacks *stacks, size_t index)
{
	int	rotates_a;
	int	rotates_b;

	rotates_a = move_count(stacks->a, index);
	rotates_b = get_moves_pb(stacks, index);
	if (rotates_a >= 0 && rotates_b >= 0)
		stacks = rotate_both(stacks, rotates_a, rotates_b);
	else if (rotates_a < 0 && rotates_b < 0)
		stacks = reverse_rotate_both(stacks, rotates_a, rotates_b);
	else
		stacks = mixed_rotates(stacks, rotates_a, rotates_b);
	stacks = ft_push_to_b(stacks);
	ft_printf("pb\n");
	return (stacks);
}
