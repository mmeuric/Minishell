/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:51:27 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:51:28 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*target;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	target = ft_malloc(s1_len + s2_len + 1);
	if (!target)
		return (NULL);
	ft_memcpy(target, s1, s1_len);
	ft_memcpy(target + s1_len, s2, s2_len);
	target[s1_len + s2_len] = '\0';
	return (target);
}
