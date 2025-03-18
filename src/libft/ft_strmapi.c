/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:51:56 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:51:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*target;
	int		i;

	if (!s || !f)
		return (NULL);
	target = ft_strdup(s);
	if (!target)
		return (NULL);
	i = 0;
	while (target[i])
	{
		target[i] = f(i, target[i]);
		i++;
	}
	return (target);
}
