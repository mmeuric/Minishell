/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:31:12 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:15:52 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_utils.h"
#include <libft.h>
#include <stdio.h>

int	handle_exit_status(int used, int res)
{
	if (res == 88)
		used = 0;
	if (used)
		set_exit_status(res);
	return (used);
}

int	check_builtins(int argc, char *command, char **args)
{
	int	used;
	int	res;

	if (!command)
		return (0);
	res = 88;
	used = 1;
	if (!ft_strcmp(command, "echo"))
		res = echo(argc, args);
	else if (!ft_strcmp(command, "cd"))
		res = cd(*args, get_envp(NULL));
	else if (!ft_strcmp(command, "pwd"))
		res = pwd();
	else if (!ft_strcmp(command, "export"))
		res = export(argc, args, get_envp_internal(NULL));
	else if (!ft_strcmp(command, "unset"))
		res = unset(argc, args, get_envp_internal(NULL));
	else if (!ft_strcmp(command, "exit"))
		res = my_exit(argc, *args);
	else if (!ft_strcmp(command, "env"))
		res = env_(get_envp_internal(NULL));
	return (handle_exit_status(used, res));
}
