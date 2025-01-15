/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:46:40 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/15 14:21:44 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_overflow(long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	check_num(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_doublon(char **av)
{
	int	i;
	int	j;
	int	len;

	len = ft_len(av);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_argument(char **check, int ac, int i)
{
	long	tmp;

	while (check[i])
	{
		if (check_doublon(check + i))
		{
			if (ac == 2)
				ft_free(check);
			ft_error("Error\n");
		}
		if (!check_num(check[i]))
		{
			if (ac == 2)
				ft_free(check);
			ft_error("Error\n");
		}
		tmp = ft_atol(check[i]);
		if (!check_overflow(tmp))
			ft_error("Error\n");
		i++;
	}
}

void	check_arg(int ac, char **av)
{
	int		i;
	char	**check;

	i = 0;
	if (!av[1][i])
		ft_error("Error11\n");
	if (ac == 2)
		check = ft_split(av[1], ' ');
	else
	{
		i = 1;
		check = av;
	}
	validate_argument(check, ac, i);
	if (ac == 2)
		ft_free(check);
}
