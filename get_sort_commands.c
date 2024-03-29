/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:36:10 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/23 11:11:56 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*sort_3(int **a, size_t count)
{
	if (count == 1)
		return ("\n");
	if (count == 2)
	{
		if (a[0][0] > a[1][0])
			return ("sa\n");
		else
			return ("\n");
	}
	if (a[0][0] < a[1][0] && a[1][0] < a[2][0] && a[0][0] < a[2][0])
		return ("\n");
	if (a[0][0] < a[1][0] && a[1][0] > a[2][0] && a[0][0] < a[2][0])
		return ("rra\nsa\n");
	if (a[0][0] > a[1][0] && a[1][0] < a[2][0] && a[0][0] < a[2][0])
		return ("sa\n");
	if (a[0][0] < a[1][0] && a[1][0] > a[2][0] && a[0][0] > a[2][0])
		return ("rra\n");
	if (a[0][0] > a[1][0] && a[1][0] < a[2][0] && a[0][0] > a[2][0])
		return ("ra\n");
	if (a[0][0] > a[1][0] && a[1][0] > a[2][0] && a[0][0] > a[2][0])
		return ("ra\nsa\n");
	return ("");
}

static void	sort_4(t_stacks *stacks)
{
	stacks = ft_push_to_b(stacks);
	ft_printf("pb\n");
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
		sort_4(stacks);
	}
	else
		sort_large(stacks, i);
	return ;
}
