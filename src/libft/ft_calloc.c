/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:33:17 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:33:19 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*target;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	target = ft_malloc(count * size);
	if (target)
		ft_bzero(target, count * size);
	return (target);
}
