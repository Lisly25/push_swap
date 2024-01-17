/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:36:10 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 10:11:38 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (i <= 5)
	{
		result = sort_5(stacks->a, i);
		ft_printf("%s", result);
		free(result);
	}
	else
		sort_large(stacks, i);
	return ;
}
