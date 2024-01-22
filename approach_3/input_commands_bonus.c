/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_commands_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:56:20 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/22 16:18:41 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_vector	*get_ps_commands(void)
{
	t_vector	*ps_commands;
	char		*command;
	int			i;

	i = 0;
	ps_commands = vector_new(2);
	if (ps_commands == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	command = get_next_line(0);
	if (command == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (NULL);
	}
	vector_add_back(ps_commands, command);
	while (ps_commands->array[i++] != NULL)
	{
		command = get_next_line(0);
		vector_add_back(ps_commands, command);
	}
	return (ps_commands);
}
