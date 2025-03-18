/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:52:12 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:52:13 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_to_find;
	size_t	hay_len;

	len_to_find = ft_strlen(needle);
	i = 0;
	if (len_to_find == 0)
		return ((char *)haystack);
	if (!haystack && len == 0)
		return (NULL);
	hay_len = ft_strlen(haystack);
	if (hay_len == 0 || len == 0 || len_to_find > len)
		return (NULL);
	while (haystack[i] && i < len - (len_to_find - 1))
	{
		if (haystack[i] == needle[0])
			if (ft_strncmp(haystack + i, needle, len_to_find) == 0)
				return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
