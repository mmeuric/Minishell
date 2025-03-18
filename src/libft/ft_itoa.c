/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:34:01 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:34:02 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_length(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*target;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	target = ft_malloc(neg + get_length(n) + 1);
	if (!target)
		return (NULL);
	i = neg + get_length(n);
	target[i--] = '\0';
	while (i >= neg)
	{
		target[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		target[0] = '-';
	return (target);
}
