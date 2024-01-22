/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:35:18 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/22 14:15:47 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

# define MAX_VALUE 2147483647
# define MIN_VALUE -2147483648

typedef struct s_stacks
{
	int	**a;
	int	**b;
}	t_stacks;

void		free_stack(int **stack);

void		free_list(char **list);

int			**init_stack_a(int argc, char **argv);

int			**init_stack_b(int **stack_a);

size_t		get_arr_size(int **stack);

void		get_sort_commands(t_stacks *stacks);

void		sort_large(t_stacks *stacks, size_t size);

int			check_for_errors(int **a);

int			check_if_int(char *num);

ssize_t		get_next_larger(int **stack, int num);

ssize_t		get_one_smaller(int **stack, int prev_num);

ssize_t		get_min(int **stack);

ssize_t		get_max(int **stack);

t_stacks	*ft_push_to_b(t_stacks *stacks);

t_stacks	*ft_rev_rotate_a(t_stacks *stacks);

t_stacks	*ft_rotate_a(t_stacks *stacks);

t_stacks	*ft_push_to_a(t_stacks *stacks);

t_stacks	*ft_rev_rotate_b(t_stacks *stacks);

t_stacks	*ft_rotate_b(t_stacks *stacks);

t_stacks	*ft_ss(t_stacks *stacks);

t_stacks	*ft_swap_b(t_stacks *stacks);

t_stacks	*ft_swap_a(t_stacks *stacks);

t_stacks	*ft_rr(t_stacks *stacks);

t_stacks	*ft_rrr(t_stacks *stacks);

int			move_count(int **stack, ssize_t index);

void		free_stacks_struct(t_stacks *stacks);

int			add_absolute_values(int rotates_src, int rotates_dest);

int			get_moves_pb(t_stacks *stacks, size_t index);

int			combined_rotation_moves(t_stacks *stacks, size_t index);

t_stacks	*sort_last_3_large(t_stacks *stacks);

t_stacks	*move_a_to_b(t_stacks *stacks, size_t index);

t_stacks	*move_b_to_a(t_stacks *stacks);

t_stacks	*rotate_a_final(t_stacks *stacks);

#endif