/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:52 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:38:53 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset_utils.h"

int	unset(int argc, char **args, t_env **env)
{
	char	*ptr;
	int		i;

	if (!args || !env)
		return (1);
	i = 0;
	while (i < argc)
	{
		ptr = args[i++];
		if (validate_arg(ptr))
			continue ;
		del_from_env(env, ptr);
	}
	return (0);
}
