/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:30 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/15 12:39:10 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*lst_before_last(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->next->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

int	reverse_rotate(t_stack **lst)
{
	t_stack	*stock;
	t_stack	*head;
	t_stack	*before_last;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	head = ft_lstlast(*lst);
	before_last = lst_before_last(*lst);
	stock = *lst;
	*lst = head;
	(*lst)->next = stock;
	before_last->next = NULL;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
