/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:36:10 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/04 09:16:38 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_sort_commands(int **stack_a)
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
		//free(result);
	}
	else
	{
		result = sort_large(stack_a, i);
		ft_printf("%s", result);
		//free(result);
	}
	return ;
}
