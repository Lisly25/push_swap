/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 17:13:51 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_moves_pb(t_stacks *stacks, size_t index)
{
	size_t	b_min;
	size_t	b_max;

	b_min = get_min(stacks->b);
	b_max = get_max(stacks->b);
	if (stacks->a[index][0] > stacks->b[b_max][0])
		//rotate enough to get max to top;
	if (stacks->a[index][0] < stacks->b[b_min][0])
		//rotate enough to get min to bottom - is that right???;
}

static size_t	get_cheapest_to_p_to_b(t_stacks *stacks)
{
	//to get the combination of moves needed:
	// 1. need to see how many rotations you'd need to get num to top of stack a
	// 2. need to see how many rotations it'd take to rotate stack b to be ready for accepting the num
	// 3. 1 move for "pb"
	// +1: if rotations in 1 and 2 are done in the same direction, they can use double moves to lessen the number of moves
	int		rotates_dest;
	size_t	i;
	int		rotates_src;

	rotates_src = move_count(stacks->a, i);
	i = 0;
	while (stacks->b[i] != NULL)
	{
		rotates_src = move_count(stacks->a, i);
		rotates_dest = get_moves_pb(stacks, i);
	}
}

void	sort_large(t_stacks *stacks, size_t size)
{
	size_t	next_to_be_moved;

	stacks = ft_push_to_b(stacks);
	stacks = ft_push_to_b(stacks);
	next_to_be_moved = get_cheapest_to_p_to_b(stacks);
}
