/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commands_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:30 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/25 11:08:18 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_stacks	*run_ps_command(t_stacks *stacks, char *command, size_t n)
{
	if (ft_strncmp(command, "ss\n", n) == 0)
		stacks = ft_ss(stacks);
	else if (ft_strncmp(command, "sa\n", n) == 0)
		stacks = ft_swap_a(stacks);
	else if (ft_strncmp(command, "sb\n", n) == 0)
		stacks = ft_swap_b(stacks);
	else if (ft_strncmp(command, "pa\n", n) == 0)
		stacks = ft_push_to_a(stacks);
	else if (ft_strncmp(command, "pb\n", n) == 0)
		stacks = ft_push_to_b(stacks);
	else if (ft_strncmp(command, "rr\n", n) == 0)
		stacks = ft_rr(stacks);
	else if (ft_strncmp(command, "ra\n", n) == 0)
		stacks = ft_rotate_a(stacks);
	else if (ft_strncmp(command, "rb\n", n) == 0)
		stacks = ft_rotate_b(stacks);
	else if (ft_strncmp(command, "rrr\n", n) == 0)
		stacks = ft_rrr(stacks);
	else if (ft_strncmp(command, "rra\n", n) == 0)
		stacks = ft_rev_rotate_a(stacks);
	else if (ft_strncmp(command, "rrb\n", n) == 0)
		stacks = ft_rev_rotate_b(stacks);
	return (stacks);
}

static int	check_if_real_command(char *command, size_t n)
{
	if (ft_strncmp(command, "ss\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "sa\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "sb\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "pa\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "pb\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "rr\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "ra\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "rb\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "rrr\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "rra\n", n) == 0)
		return (0);
	else if (ft_strncmp(command, "rrb\n", n) == 0)
		return (0);
	return (1);
}

static int	are_stacks_sorted(t_stacks *stacks)
{
	int	i;
	int	value;

	i = 1;
	if (get_arr_size(stacks->a) < 1)
		return (1);
	value = stacks->a[0][0];
	if (stacks->b[0] != NULL)
		return (1);
	while (stacks->a[i] != NULL)
	{
		if (value > stacks->a[i][0])
			return (1);
		value = stacks->a[i][0];
		i++;
	}
	return (0);
}

void	test_commands(t_stacks *stacks)
{
	char	*command;
	ssize_t	n;

	command = NULL;
	n = -1;
	while (command != NULL || n == -1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		n = ft_strlen(command);
		if (check_if_real_command(command, n) == 1)
		{
			ft_putendl_fd("Error", 2);
			return ;
		}
		stacks = run_ps_command(stacks, command, n);
		free(command);
	}
	if (are_stacks_sorted(stacks) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return ;
}
