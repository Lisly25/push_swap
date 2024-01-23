/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:27:02 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/23 13:38:36 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		exit(1);
	stacks->a = init_stack_a(argc, argv);
	if (stacks->a == NULL)
	{
		free(stacks);
		exit(1);
	}
	if (check_for_errors(stacks->a) == 1)
		exit(1);
	stacks->b = init_stack_b(stacks->a);
	if (stacks->b == NULL)
		free_stacks_struct(stacks);
	test_commands(stacks);
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
	exit (0);
}
