/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:36:17 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:36:19 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*target;

	len = ft_strlen(s1);
	target = ft_malloc(len + 1);
	if (target)
	{
		ft_memcpy(target, s1, len);
		target[len] = '\0';
	}
	return (target);
}
