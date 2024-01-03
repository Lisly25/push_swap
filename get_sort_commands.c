/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:36:10 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 14:50:37 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_sort_commands(int **stack_a)
{
	size_t	i;

	i = get_arr_size(stack_a);
	if (i <= 3)
		return (sort_3(stack_a, i));
	if (i <= 5)
		return (sort_5(stack_a, i));
	if (i <= 100)
		return (sort_100(stack_a));
	else
		return (sort_large(stack_a));
}
