/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:52:51 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:52:52 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringbuilder.h>

static size_t	align(size_t size)
{
	return ((size + (16 - 1)) & ~ (16 - 1));
}

void	sb_reallocate(t_strbuilder *sb, size_t len)
{
	char	*new;

	sb->capacity = align(sb->used_len + len + 1);
	new = ft_calloc(1, sb->capacity);
	ft_memcpy(new, sb->str, sb->used_len);
	free(sb->str);
	sb->str = new;
}
