/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:37:21 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 16:18:02 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index_max(t_stack *lst)
{
	int	max;

	max = lst->index;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

int	find_max(t_stack *lst)
{
	int	max;

	max = lst->nb;
	while (lst)
	{
		if (lst->nb > max)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}

int	find_index_min(t_stack *stack_a)
{
	int	min;
	int	min_pos;
	int	current_pos;

	min_pos = 0;
	current_pos = 0;
	min = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index < min)
		{
			min = stack_a->index;
			min_pos = current_pos;
		}
		stack_a = stack_a->next;
		current_pos++;
	}
	return (min_pos);
}

void	sort_indice(t_stack *stack_a)
{
	int		index;
	t_stack	*current;
	t_stack	*compare;

	current = stack_a;
	while (current)
	{
		index = 0;
		compare = stack_a;
		while (compare)
		{
			if (current->nb > compare->nb)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
