/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:14:24 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 03:47:17 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

unsigned int	get_chunk_len(char *ptr, char *sp)
{
	unsigned int	len;

	len = 0;
	if (!ft_strchr(sp, *ptr))
	{
		while (ptr[len] && !ft_strchr(sp, ptr[len]))
			len++;
	}
	else
	{
		len++;
		if (ptr[1] == '?')
			return (len + 1);
		while (ft_isalnum(ptr[len]) || ptr[len] == '_')
			len++;
	}
	return (len);
}

/* 
** transforme temporairement les espaces en 132 
** pour éviter une interprétation prématurée.
*/
void	ghost_char_action(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = (char )DIGIT;
		i++;
	}
}
