/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 16:47:28 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_cheapest_to_p_to_b(t_stacks *stacks)
{
	//to get the combination of moves needed:
	// 1. need to see how many rotations you'd need to get num to top of stack a
	// 2. need to see how many rotations it'd take to rotate stack b to be ready for accepting the num
	// 3. 1 move for "pb"
	// +1: if rotations in 1 and 2 are done in the same direction, they can use double moves to lessen the number of moves
	size_t	b_max;
	size_t	b_min;
	size_t	moves;
	size_t	i;

	moves = 1;
	i = 0;
	b_max = get_max(stacks->b);
	b_min = get_min(stacks->b);
	while (stacks->b[i] != NULL)
	{
		moves = get_moves_pb(stacks, b_min, b_max);
	}
}

void	sort_large(t_stacks *stacks, size_t size)
{
	stacks = ft_push_to_b(stacks);
	stacks = ft_push_to_b(stacks);
	
}
