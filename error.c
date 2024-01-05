/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:39:22 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/05 11:58:55 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(int **stack)
{
	size_t	i;

	i = 0;
	while (stack[i])
		free(stack[i++]);
	free(stack);
}

void	free_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}
