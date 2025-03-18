/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_dispatcher.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:24:55 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:24:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_DISPATCHER_H
# define BUILTIN_DISPATCHER_H
# include <libft.h>

int	echo(int argc, char **args);
int	pwd(void);
int	cd(char *arg, t_env *env);
#endif
