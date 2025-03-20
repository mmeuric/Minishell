/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:26:52 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/20 15:18:50 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <global_utils.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <exit.h>

t_env		*get_envp(t_env *envp);
void		prompt_pwd(void);
extern int	g_signal_status;

#endif /* GLOBALS_H */
