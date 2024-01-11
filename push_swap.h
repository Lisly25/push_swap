/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:35:18 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/11 09:51:15 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include "limits.h"

typedef struct s_sort_status {
	ssize_t	pair_lower;
	ssize_t	pair_higher;
	ssize_t	prev_low;
	ssize_t	prev_high;
	size_t	real_size;
	char	prev_method;
}	t_sort_status;

void			free_stack(int **stack);

void			free_list(char **list);

int				**init_stack_a(int argc, char **argv);

int				**get_list(int argc, char **argv, size_t i);

int				**get_str(char *str);

int				**init_stack_b(int **stack_a);

size_t			get_arr_size(int **stack);

void			get_sort_commands(int **stack_a);

char			*sort_3(int **a, size_t count);

char			*sort_5(int **a, size_t count);

void			sort_large(int **a, size_t count);

int				check_for_errors(int **a);

int				check_if_num(char *str);

int				check_if_int(char *num);

size_t			count_of_greater_than(int **a, int num, size_t count);

size_t			range_count_of_g_t(int **a, int num, int start, int end);

void			print_n_commands(char *command, int n);

ssize_t			get_next_min(int **a, size_t size, int prev_smallest);

ssize_t			get_min(int **a, size_t count);

t_sort_status	*init_sort_status(int **a, size_t size);

size_t			move_count(int **a, ssize_t index, t_sort_status *status);

ssize_t			get_real_i(int **a, ssize_t index, t_sort_status *status);

#endif