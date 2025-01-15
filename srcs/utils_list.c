/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:28 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/15 15:13:50 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	print_lst(t_stack *lst)
{
	while (lst)
	{
		if (lst->next)
			printf("%d -> ", lst->nb);
		else
			printf("%d -> (null)\n", lst->nb);
		lst = lst->next;
	}
}*/

int	ft_lstsize(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
