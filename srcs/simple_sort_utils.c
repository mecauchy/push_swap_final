/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:04:55 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 15:01:20 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	find_max(t_stack *lst)
// {
// 	int	max;

// 	max = lst->nb;
// 	while (lst)
// 	{
// 		if (lst->nb > max)
// 			max = lst->nb;
// 		lst = lst->next;
// 	}
// 	return (max);
// }

// int	find_min(t_stack *stack_a)
// {
// 	int	min;

// 	min = stack_a->nb;
// 	while (stack_a)
// 	{
// 		if (stack_a->nb < min)
// 			min = stack_a->nb;
// 		stack_a = stack_a->next;
// 	}
// 	return (min);
// }

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

int	find_min(t_stack *stack_a)
{
	int	min;
	int	min_pos;
	int	current_pos;

	min_pos = 0;
	current_pos = 0;
	min = stack_a->nb;
	while (stack_a)
	{
		if (stack_a->nb < min)
		{
			min = stack_a->nb;
			min_pos = current_pos;
		}
		stack_a = stack_a->next;
		current_pos++;
	}
	return (min_pos);
}

int	max_bits(t_stack **lst)
{
	int	bits;
	int	max;

	bits = 0;
	max = find_max(*lst);
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
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
