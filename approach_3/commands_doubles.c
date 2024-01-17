/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_doubles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:30:45 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 14:47:22 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_ss(t_stacks *stacks)
{
	stacks = ft_swap_a(stacks);
	stacks = ft_swap_b(stacks);
	return (stacks);
}

t_stacks	*ft_rr(t_stacks *stacks)
{
	stacks = ft_rotate_a(stacks);
	stacks = ft_rotate_b(stacks);
	return (stacks);
}

t_stacks	*ft_rrr(t_stacks *stacks)
{
	stacks = ft_rev_rotate_a(stacks);
	stacks = ft_rev_rotate_b(stacks);
	return (stacks);
}
