/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_sort_last_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:20:20 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/18 15:21:50 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*sort_last_3(t_stacks *stacks)
{
	int	**a;

	a = stacks->a;
	if (a[0][0] < a[1][0] && a[1][0] < a[2][0] && a[0][0] < a[2][0])
		return (stacks);
	else if (a[0][0] < a[1][0] && a[1][0] > a[2][0] && a[0][0] < a[2][0])
	{
		stacks = ft_rev_rotate_a(stacks);
		stacks = ft_swap_a(stacks);
		ft_printf("rra\nsa\n");
	}
	else if (a[0][0] > a[1][0] && a[1][0] < a[2][0] && a[0][0] < a[2][0])
	{
		stacks = ft_swap_a(stacks);
		ft_printf("sa\n");
	}
	else
		stacks = pt_2_sort_last_3(stacks);
	return (stacks);
}

static t_stacks	*pt_2_sort_last_3(t_stacks *stacks)
{
	int	**a;

	a = stacks->a;
	if (a[0][0] < a[1][0] && a[1][0] > a[2][0] && a[0][0] > a[2][0])
	{
		stacks = ft_rev_rotate_a(stacks);
		ft_printf("rra\n");
	}
	else if (a[0][0] > a[1][0] && a[1][0] < a[2][0] && a[0][0] > a[2][0])
	{
		stacks = ft_rotate_a(stacks);
		ft_printf("ra\n");
	}
	else if (a[0][0] > a[1][0] && a[1][0] > a[2][0] && a[0][0] > a[2][0])
	{
		stacks = ft_rotate_a(stacks);
		stacks = ft_swap_a(stacks);
		ft_printf("ra\nsa\n");
	}
	return (stacks);
}
