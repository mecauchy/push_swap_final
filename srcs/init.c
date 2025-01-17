/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:07:38 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 19:05:55 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *exit_msg)
{
	int	i;

	i = 0;
	while (exit_msg[i])
	{
		write(2, &exit_msg[i], 1);
		i++;
	}
	exit(1);
}

char	**ft_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
	return (NULL);
}

void	free_stack(t_stack **lst)
{
	t_stack	*to_free;

	while (*lst)
	{
		to_free = (*lst);
		*lst = (*lst)->next;
		free(to_free);
	}
}

t_stack	*initialize_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	char	**new_lst;

	if (ac == 2)
	{
		new_lst = ft_split(av[1], ' ');
		stack_a = ft_lstnew(ft_atoi(new_lst[0]));
		i = 1;
	}
	else
	{
		new_lst = av;
		stack_a = ft_lstnew(ft_atoi(new_lst[1]));
		i = 2;
	}
	while (new_lst[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(new_lst[i])));
		i++;
	}
	if (ac == 2)
		ft_free(new_lst);
	return (stack_a);
}
