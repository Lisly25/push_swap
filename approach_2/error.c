/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:39:22 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/16 11:05:47 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(int **stack)
{
	size_t	i;

	i = 0;
	if (stack != NULL)
	{
		while (stack[i])
			free(stack[i++]);
		free(stack);
	}
}

void	free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

void	ft_ps_malloc_error(int ***stack_1, int ***stack_2)
{
	if (*stack_1 != NULL)
		free_stack(*stack_1);
	if (*stack_2 != NULL)
		free_stack(*stack_2);
	exit(1);
}
