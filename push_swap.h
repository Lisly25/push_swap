/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:35:18 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/04 11:38:54 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

void	free_stack(int **stack);

int		**get_list(int argc, char **argv, size_t i);

int		**get_str(char *str);

int		**init_stack_b(int **stack_a);

size_t	get_arr_size(int **stack);

void	get_sort_commands(int **stack_a);

char	*sort_3(int **a, size_t count);

char	*sort_5(int **a, size_t count);

char	*sort_large(int **a, size_t count);

int		check_for_errors(int **a);

#endif