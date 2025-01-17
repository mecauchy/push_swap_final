/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:04:55 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 16:14:25 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	quick_find_min(t_stack *stack_a)
{
	int	min;

	min = stack_a->nb;
	while (stack_a)
	{
		if (stack_a->nb < min)
			min = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (min);
}

int	max_index_bits(t_stack **lst)
{
	int	bits;
	int	max;

	bits = 0;
	max = find_index_max(*lst);
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}
