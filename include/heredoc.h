/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:31:00 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:40:15 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include <syntax_tree.h>
# include <expander.h>
# include <globals.h>
# include <signals.h>
# include <stringbuilder.h>

char	*handle_heredoc(char *delim, bool expand_env);
char	*ft_mktmp(void);
int		patch_heredoc(t_ast_cmd *tree);
void	patch_token(t_ast_redir *tree);
bool	is_expandable(t_token *tok);
#endif
