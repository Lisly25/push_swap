/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:30:47 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/15 15:29:13 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		**stack_a;
	int		**stack_b;
	char	*result;

	stack_a = init_stack_a(argc, argv);
	if (stack_a == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit (1);
	}
	if (check_for_errors(stack_a) == 1)
		exit (1);
	stack_b = init_stack_b(stack_a);
	get_sort_commands(stack_a, stack_b);
	free_stack(stack_a);
	exit (0);
}
