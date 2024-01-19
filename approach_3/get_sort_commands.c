/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:36:10 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 15:19:16 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_4(t_stacks *stacks, size_t size)
{
	stacks = ft_push_to_b(stacks);
	ft_printf("pb\n");
	size--;
	stacks = sort_last_3_large(stacks);
	stacks = move_b_to_a(stacks);
	stacks = rotate_a_final(stacks);
	return ;
}

void	get_sort_commands(t_stacks *stacks)
{
	size_t	i;
	char	*result;

	i = get_arr_size(stacks->a);
	if (i <= 3)
	{
		result = sort_3(stacks->a, i);
		ft_printf("%s", result);
	}
	else if (i == 4)
	{
		sort_4(stacks, i);
	}
	else
		sort_large(stacks, i);
	return ;
}
