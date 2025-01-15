/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:38 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/15 15:18:22 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// t_stack	*_lst(void)
// {
// 	static t_stack	stack;
// 	static int		init = 0;

// 	if (init == 0)
// 	{
// 		init = 1;
// 		stack.next = NULL;
// 	}
// 	return (&stack);
// }
// void	free_lst(void)
// {
// 	t_stack	*tmp;
// 	t_stack	*tmp2;

// 	tmp = _lst();
// 	while (tmp)
// 	{
// 		tmp2 = tmp->next;
// 		free(tmp);
// 		tmp = tmp2;
// 	}
// }