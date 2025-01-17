/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:11:49 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 16:39:46 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_sep(char *str, char charset)
{
	if (*str == charset)
		return (1);
	return (0);
}

static int	ft_ltrcnt(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_is_sep(str + i, charset)))
		i++;
	return (i);
}

static int	ft_wrdcnt(char *str, char charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		if (*str && ft_is_sep(str, charset))
			str++;
		i = ft_ltrcnt(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

static char	*ft_wdcpy(char *str, int size)
{
	char	*dest;

	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	dest[size] = '\0';
	while (size--)
		dest[size] = str[size];
	return (dest);
}

int	ft_only_sep(char *str, char charset)
{
	while (*str)
	{
		if (*str != charset)
			return (0);
		str++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		i;
	int		j;

	i = 0;
	if (s == NULL || ft_only_sep((char *)s, c))
		return (NULL);
	size = ft_wrdcnt((char *)s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		while (*s && ft_is_sep((char *)s, c))
			s++;
		j = ft_ltrcnt((char *)s, c);
		str[i] = ft_wdcpy((char *)s, j);
		if (str[i] == NULL)
			return (NULL);
		s += j;
		i++;
	}
	str[size] = 0;
	return (str);
}
