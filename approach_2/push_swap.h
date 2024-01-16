/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:35:18 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/16 10:37:53 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include "limits.h"

void	free_stack(int **stack);

void	free_list(char **list);

int		**init_stack_a(int argc, char **argv);

int		**get_list(int argc, char **argv, int i);

int		**get_str(char *str);

int		**init_stack_b(int **stack_a);

size_t	get_arr_size(int **stack);

void	get_sort_commands(int **stack_a, int **stack_b);

char	*sort_3(int **a, size_t count);

char	*sort_5(int **a, size_t count);

void	sort_large(int **a, int **b, size_t size);

int		check_for_errors(int **a);

int		check_if_num(char *str);

int		check_if_int(char *num);

size_t	count_of_greater_than(int **a, int num, size_t count);

size_t	range_count_of_g_t(int **a, int num, int start, int end);

void	print_n_commands(char *command, int n);

ssize_t	get_next_min(int **a, size_t size, int prev_smallest);

ssize_t	get_min(int **a, size_t count);

void	ft_ps_malloc_error(int **stack_1, int **stack_2);

void	ft_swap(int **stack, int **other_stack);

int		**ft_push(int	***src, int ***dest, size_t size);

void	ft_rev_rotate(int **stack, int **other_stack);

void	ft_rotate(int **stack, int **other_stack);

size_t	move_count(size_t stack_size, size_t index);

void	ft_swap_b(int ***a, int ***b);

#endif