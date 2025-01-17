/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:46 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 15:36:26 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack **lst)
{
	t_stack	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	sort_indice(*stack_a);
	if (!is_sorted(stack_a) && stack_size == 2)
		sa(stack_a);
	else if (!is_sorted(stack_a) && stack_size == 3)
		sort_3(stack_a);
	else if (!is_sorted(stack_a) && stack_size <= 5)
		sort_5(stack_a, stack_b);
	else if (!is_sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		exit (1);
	check_arg(ac, av);
	stack_a = initialize_stack(ac, av);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
