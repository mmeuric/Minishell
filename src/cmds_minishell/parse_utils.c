/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:42:39 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:42:41 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_utils.h"

char	*get_key(char *line)
{
	size_t	index;
	char	*equal_sign;

	if (!line)
		return (NULL);
	equal_sign = ft_strchr(line, '=');
	if (equal_sign)
	{
		index = (size_t)equal_sign - (size_t)line;
		if (is_concate(line))
			index--;
		return (ft_substr(line, 0, index));
	}
	return (ft_strdup(line));
}

char	*get_value(char *line)
{
	char	*equal_sign;

	if (!line)
		return (NULL);
	equal_sign = ft_strchr(line, '=');
	if (!equal_sign)
		return (ft_strdup(""));
	return (ft_substr(equal_sign, 1, ft_strlen(equal_sign + 1)));
}
