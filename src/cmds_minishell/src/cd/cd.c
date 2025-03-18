/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:30:03 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:30:05 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_utils.h"
#include <stdio.h>

int	cd(char *arg, t_env *env)
{
	t_env	*node;

	if (!arg)
	{
		node = search_in_env(env, "HOME");
		if (!node)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
		else
			return (change_directory(node->value));
	}
	else
		return (change_directory(arg));
}
