/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:35:18 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/17 11:47:48 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include "limits.h"

typedef struct s_stacks
{
	int	**a;
	int	**b;
}	t_stacks;

void		free_stack(int **stack);

void		free_list(char **list);

int			**init_stack_a(int argc, char **argv);

int			**get_list(int argc, char **argv, int i);

int			**get_str(char *str);

int			**init_stack_b(int **stack_a);

size_t		get_arr_size(int **stack);

void		get_sort_commands(t_stacks *stacks);

char		*sort_3(int **a, size_t count);

char		*sort_5(int **a, size_t count);

void		sort_large(t_stacks *stacks, size_t size);

int			check_for_errors(int **a);

int			check_if_num(char *str);

int			check_if_int(char *num);

size_t		count_of_greater_than(int **a, int num, size_t count);

size_t		range_count_of_g_t(int **a, int num, int start, int end);

void		print_n_commands(char *command, int n);

ssize_t		get_next_min(int **a, size_t size, int prev_smallest);

ssize_t		get_min(int **a, size_t count);

//void	ft_ps_malloc_error(int **stack_1, int **stack_2);

t_stacks	*ft_push_to_b(t_stacks *stacks, size_t size);

t_stacks	*ft_rev_rotate(t_stacks *stacks);

t_stacks	*ft_rotate(t_stacks *stacks);

t_stacks	*ft_swap(t_stacks *stacks, char stack);

t_stacks	*ft_swap_b(t_stacks *stacks);

size_t		move_count(size_t stack_size, size_t index);

void		free_stacks_struct(t_stacks *stacks);



void		print_int_arr(int **stack_a);//comment out after debug!

#endif