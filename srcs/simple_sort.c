/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:35:22 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 14:45:30 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **lst)
{
	int	max;

	max = find_max(*lst);
	if ((*lst)->nb == max)
		ra(lst);
	else if ((*lst)->next->nb == max)
		rra(lst);
	if ((*lst)->nb > (*lst)->next->nb)
		sa(lst);
}

int	find_position(t_stack *stack_a, int min)
{
	int	index;

	index = 0;
	while (stack_a)
	{
		if (stack_a->nb == min)
			break ;
		index++;
		stack_a = stack_a->next;
	}
	return (index);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int min)
{
	int	pos;
	int	size;

	pos = find_position(*stack_a, min);
	size = ft_lstsize(*stack_a);
	if (pos <= size / 2)
	{
		while ((*stack_a)->nb != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->nb != min)
			rra(stack_a);
	}
	pb(stack_b, stack_a);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	next_min;

	if (ft_lstsize(*stack_a) > 5)
		return ;
	min = quick_find_min(*stack_a);
	push_to_b(stack_a, stack_b, min);
	next_min = quick_find_min(*stack_a);
	push_to_b(stack_a, stack_b, next_min);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	if (stack_a && (*stack_a) && (*stack_a)->next)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			sa(stack_a);
	}
}
