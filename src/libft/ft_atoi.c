/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:33:03 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:33:05 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	ft_iswhitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\v' || c == ' '
		|| c == '\r')
		return (1);
	return (0);
}

static int	edgecase(int nbr, int sign, int len, const char *strnbr)
{
	if (len > 19 || ft_memcmp(strnbr, "9223372036854775808", len) >= 0)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return (sign * nbr);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	int	i;
	int	len;

	if (!str)
		return (0);
	nbr = 0;
	sign = 1;
	i = 0;
	len = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i++] - '0');
		len++;
	}
	if (len >= 19)
		return (edgecase(nbr, sign, len, str + (i - len)));
	return (sign * nbr);
}
