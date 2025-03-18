/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:30:09 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:39:05 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "syntax_tree.h"
# include "error.h"
# include "expander.h"
# include "globals.h"
# include "signals.h"

void	executor(t_ast_cmd *tree, bool forked);
void	free_list(char **args);
int		execute_cmd(char **cmd, t_env *envp);
bool	check_absolute_path(char **cmd, t_env *env);
bool	check_if_executable(char **cmd, char *exec, char **paths, t_env *env);
char	*check_file_tok(t_token *file_tok);
pid_t	ft_fork(void);
/* binary */
void	exec_pipe(t_ast_binary *tree, bool forked);
void	exec_or(t_ast_binary *tree, bool forked);
void	exec_and(t_ast_binary *tree, bool forked);
/* unary */
void	exec_redir(t_ast_redir *tree, bool forked);
void	exec_exe(t_ast_exec *exe, bool forked);
void	exec_subsh(t_ast_subsh *tree, bool forked);
/* utils */
int		is_dir(char *str);

#endif /* EXECUTOR_H */
