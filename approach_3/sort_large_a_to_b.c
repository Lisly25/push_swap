/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:58:50 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 13:47:40 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*rotate_both(t_stacks *stacks, int rotates_a, int rotates_b)
{
	while (rotates_a > 0 && rotates_b > 0)
	{
		stacks = ft_rr(stacks);
		ft_printf("rr\n");
		rotates_a--;
		rotates_b--;
	}
	while (rotates_a > 0)
	{
		stacks = ft_rotate_a(stacks);
		ft_printf("ra\n");
		rotates_a--;
	}
	while (rotates_b > 0)
	{
		stacks = ft_rotate_b(stacks);
		ft_printf("rb\n");
		rotates_b--;
	}
	return (stacks);
}

static t_stacks	*rev_rotate_both(t_stacks *stacks, int rotates_a, int rotates_b)
{
	while (rotates_a < 0 && rotates_b < 0)
	{
		stacks = ft_rrr(stacks);
		ft_printf("rrr\n");
		rotates_a++;
		rotates_b++;
	}
	while (rotates_a < 0)
	{
		stacks = ft_rev_rotate_a(stacks);
		ft_printf("rra\n");
		rotates_a++;
	}
	while (rotates_b < 0)
	{
		stacks = ft_rev_rotate_b(stacks);
		ft_printf("rrb\n");
		rotates_b++;
	}
	return (stacks);
}

t_stacks	*mixed_rotates(t_stacks *stacks, int rotates_a, int rotates_b)
{
	while (rotates_a < 0)
	{
		stacks = ft_rev_rotate_a(stacks);
		ft_printf("rra\n");
		rotates_a++;
	}
	while (rotates_a > 0)
	{
		stacks = ft_rotate_a(stacks);
		ft_printf("ra\n");
		rotates_a--;
	}
	while (rotates_b < 0)
	{
		stacks = ft_rev_rotate_b(stacks);
		ft_printf("rrb\n");
		rotates_b++;
	}
	while (rotates_b > 0)
	{
		stacks = ft_rotate_b(stacks);
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
	//printf("Index is %zu, stack size would be %zu\n", index, get_arr_size(stacks->a));
	//printf("Should rotate a %d times, b %d times\n", rotates_a, rotates_b);
	if (rotates_a >= 0 && rotates_b >= 0)
	{
		stacks = rotate_both(stacks, rotates_a, rotates_b);
		//printf("Should rotate both, a %d times, b %d times\n", rotates_a, rotates_b);
		//print_int_arr(stacks->b);
	}
	else if (rotates_a < 0 && rotates_b < 0)
	{
		stacks = rev_rotate_both(stacks, rotates_a, rotates_b);
		//printf("Stack B after rev rotate both:\n");
		//print_int_arr(stacks->b);
	}
	else
	{
		stacks = mixed_rotates(stacks, rotates_a, rotates_b);
		//printf("Stack B after mixed rotate:\n");
		//print_int_arr(stacks->b);
	}
	stacks = ft_push_to_b(stacks);
	ft_printf("pb\n");
	//printf("Stack a:\n");
	//print_int_arr(stacks->a);
	//printf("Stack b\n");
	//print_int_arr(stacks->b);
	return (stacks);
}
