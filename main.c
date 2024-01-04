/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:30:47 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/04 15:34:11 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		**stack_a;
	char	*result;

	if (argc < 1)
	{
		ft_putstr_fd(argv[1], 1);
		exit (1);
	}
	if (argc == 2)
		stack_a = get_str(argv[1]);
	else
		stack_a = get_list((argc - 1), argv, 1);
	if (stack_a == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit (1);
	}
	if (check_for_errors(stack_a) == 1)
		exit (1);
	get_sort_commands(stack_a);
	free_stack(stack_a);
	exit (0);
}
