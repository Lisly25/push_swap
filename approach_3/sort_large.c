/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 13:48:18 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_pb(t_stacks *stacks, size_t index)
{
	ssize_t	b_min;
	ssize_t	b_max;
	int		moves;
	ssize_t	next_smaller;
	int		num;

	num = stacks->a[index][0];
	//printf("Error here?\n");
	//printf("Stacks within get_moves_pb:\n");
	//print_int_arr(stacks->a);
	//print_int_arr(stacks->b);
	b_min = get_min(stacks->b);
	b_max = get_max(stacks->b);
	//printf("Stacks within get_moves_pb:\n");
	//print_int_arr(stacks->a);
	//print_int_arr(stacks->b);
	//printf("what is wrong? Stack a at index *%d* is %d\n", index, stacks->a[index][0]);
	//printf("what is wrong? Stack a at index *%d* is %d\n", index, num);
	next_smaller = get_one_smaller(stacks->b, num);
	//printf("No error after get next min\n");
	if (num > stacks->b[b_max][0])
	{
		moves = move_count(stacks->b, b_max);
		//printf("We determined our num was bigger than anything in stack b\n");
		//printf("Num we are looking at is %d, we determined that we need to rotate b %d times to get it ready for num\n", stacks->a[index][0], moves);
	}
	else if (num < stacks->b[b_min][0])
	{
		moves = move_count(stacks->b, b_min);
		//printf("We determined our num was smaller than anything in stack b\n");
		//printf("Num we are looking at is %d, we determined that we need to rotate b %d times to get it ready for num\n", stacks->a[index][0], moves);
	}
	else
	{
		moves = move_count(stacks->b, next_smaller);
		//printf("We just looked for the next larger num in stack b\n");
	}
	//printf("B is currently:\n");
	//print_int_arr(stacks->b);
	return (moves);
}

int	combined_rotation_moves(t_stacks *stacks, size_t index)
{
	int	rotates_src;
	int	rotates_dest;
	int	rotates_all;

	rotates_src = move_count(stacks->a, index);
	rotates_dest = get_moves_pb(stacks, index);
	//printf("In combined rotation moves, stack a rotations are %d, stack b rotations are %d\n", rotates_src, rotates_dest);
	if (rotates_dest > 0 && rotates_src > 0)
	{
		if (rotates_dest > rotates_src)
			rotates_all = rotates_dest;
		else
			rotates_all = rotates_src;
		//printf("We need %d positive rotations total\n", rotates_all);
	}
	else if (rotates_dest < 0 && rotates_src < 0)
	{
		if (rotates_dest > rotates_src)
			rotates_all = -rotates_src;
		else
			rotates_all = -rotates_dest;
	}
	else
		rotates_all = add_absolute_values(rotates_src, rotates_dest);
	return (rotates_all);
}

static ssize_t	get_cheapest_to_p_to_b(t_stacks *stacks)
{
	size_t	i;
	size_t	cheapest_i;
	int		rotates_all;
	int		least_moves;
	size_t	stack_a_size;

	i = 0;
	cheapest_i = 0;
	least_moves = INT_MAX;
	stack_a_size = get_arr_size(stacks->a);
	//printf("Stack a's size is: %zu\n", stack_a_size);
	while (i < stack_a_size)
	{
		rotates_all = combined_rotation_moves(stacks, i);
		if (rotates_all < least_moves)
		{
			cheapest_i = i;
			least_moves = rotates_all;
			//printf("New cheapest move is %d\n", rotates_all);
		}
		i++;
		//printf("i is %d, stack size of a is: %zu\n", i, get_arr_size(stacks->a));
	}
	//printf("FInished one round of looking for cheapest\n");
	return (cheapest_i);
}

static t_stacks	*rotate_a_final(t_stacks *stacks)
{
	size_t	min;
	int		moves;

	min = get_min(stacks->a);
	moves = move_count(stacks->a, min);
	while (moves < 0)
	{
		stacks = ft_rev_rotate_a(stacks);
		ft_printf("rra\n");
		moves++;
	}
	//printf("Moves: %d\n", moves);
	while (moves > 0)
	{
		stacks = ft_rotate_a(stacks);
		ft_printf("ra\n");
		moves--;
	}
	return (stacks);
}

void	sort_large(t_stacks *stacks, size_t size)
{
	ssize_t	next_to_be_moved;
	size_t	original_size;

	original_size = size;
	stacks = ft_push_to_b(stacks);
	stacks = ft_push_to_b(stacks);
	ft_printf("pb\npb\n");
	//printf("Stacks after 2 initial pushes:\n");
	//print_int_arr(stacks->a);
	//print_int_arr(stacks->b);
	size = size - 2;
	while (size > 3)
	{
		next_to_be_moved = get_cheapest_to_p_to_b(stacks);
		stacks = move_a_to_b(stacks, next_to_be_moved);
		size--;
		//printf("Stack B after push to b:\n");
		//print_int_arr(stacks->b);
	}
	//printf("Stack b after only 3 elements in stack a are left:\n");
	//print_int_arr(stacks->b);
	stacks = sort_last_3_large(stacks);
	//printf("Stack a after sorting remaining elements:\n");
	//print_int_arr(stacks->a);
	while (size != original_size)
	{
		stacks = move_b_to_a(stacks);
		//printf("Moving from b to a\n");
		size++;
		//printf("Size: %zu\n", size);
	}
	stacks = rotate_a_final(stacks);
	return ;
}
