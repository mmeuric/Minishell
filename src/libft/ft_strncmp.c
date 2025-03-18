/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:52:02 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:52:03 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static int	ft_min3(int a, int b, int c)
{
	return (ft_min(ft_min(a, b), c));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	len_s1;
	int	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return (ft_memcmp(s1, s2, ft_min3(len_s1 + 1, len_s2 + 1, n)));
}
