/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:34:45 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:34:47 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t len)
{
	char			*p;
	unsigned char	uc;

	uc = (unsigned char) c;
	p = (char *)s;
	while (len--)
	{
		*p = uc;
		p++;
	}
	return (s);
}
