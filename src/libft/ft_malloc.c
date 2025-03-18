/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:34:09 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:15:22 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_malloc(unsigned long size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "shell42: MALLOC FAILED\n", 22);
		exit(88);
	}
	return (ptr);
}
