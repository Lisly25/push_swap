/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:29:50 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/23 11:24:18 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "libft/libft.h"
# include "vector_bonus.h"

# define MAX_VALUE 2147483647
# define MIN_VALUE -2147483648

typedef struct s_stacks
{
	int	**a;
	int	**b;
}	t_stacks;

size_t		get_arr_size(int **stack);

int			**init_stack_b(int **stack_a);

int			**init_stack_a(int argc, char **argv);

void		free_stack(int **stack);

void		free_list(char **list);

void		free_stacks_struct(t_stacks *stacks);

int			check_if_int(char *num);

int			is_empty_string(char *str);

int			check_for_errors(int **a);

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

t_vector	*get_ps_commands(void);

void		test_commands(t_stacks *stacks, t_vector *commands);

#endif