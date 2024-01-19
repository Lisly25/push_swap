/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils_pt_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:00:59 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/19 14:01:46 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_absolute_values(int rotates_src, int rotates_dest)
{
	if (rotates_dest < 0)
		rotates_dest = -rotates_dest;
	if (rotates_src < 0)
		rotates_src = -rotates_src;
	return (rotates_dest + rotates_src);
}
