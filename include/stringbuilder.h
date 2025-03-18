/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:31:42 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 23:31:44 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_H
# define STRINGBUILDER_H

# include "libft.h"

typedef struct s_stringbuilder
{
	size_t	capacity;
	size_t	used_len;
	char	*str;
}	t_strbuilder;

void			sb_reallocate(t_strbuilder *sb, size_t len);
t_strbuilder	*stringbuilder(void);
t_strbuilder	*sb_append(t_strbuilder *sb, char *str);
t_strbuilder	*sb_append_free(t_strbuilder *sb, char *str);
t_strbuilder	*sb_append_int(t_strbuilder *sb, int nb);
void			sb_free(t_strbuilder *sb);

#endif
