/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:36:10 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/15 15:17:40 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_sort_commands(int **stack_a, int **stack_b)
{
	size_t	i;
	char	*result;

	i = get_arr_size(stack_a);
	if (i <= 3)
	{
		result = sort_3(stack_a, i);
		ft_printf("%s", result);
	}
	else if (i <= 5)
	{
		result = sort_5(stack_a, i);
		ft_printf("%s", result);
		free(result);
	}
	else
		sort_large(stack_a, stack_b, i);
	return ;
}
