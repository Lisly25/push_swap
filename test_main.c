/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:30:47 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 13:14:39 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(int **arr);

int	main(int argc, char **argv)
{
	int		**stack_a;
	//char	*result;

	if (argc < 1)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (argc == 2)
		stack_a = get_str(argv[1]);
	else
		stack_a = get_list((argc - 1), argv, 1);
	if (stack_a == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	print_arr(stack_a);
	return (0);
}
