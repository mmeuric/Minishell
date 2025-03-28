/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:45 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:32:02 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <syntax_tree.h>

void	advance(t_token **current)
{
	*current = (*current)->next;
}

bool	match(t_token *tok, t_token_type types[], int size)
{
	int	i;

	if (!tok)
		return (false);
	i = 0;
	while (i < size)
	{
		if (tok->type == types[i])
			return (true);
		i++;
	}
	return (false);
}

t_token	*clone_tok(t_token *tok)
{
	t_token	*clone;
	t_token	*no_space;

	if (!tok)
		return (NULL);
	clone = new_token(tok->type, ft_strdup(tok->value), tok->len);
	clone->to_expand = tok->to_expand;
	no_space = tok->nospace_next;
	while (no_space)
	{
		ft_tokadd_back(&clone->nospace_next, clone_tok(no_space));
		no_space = no_space->nospace_next;
	}
	return (clone);
}

t_ast_redir	*tok_to_redir(t_token *redir_ptr)
{
	int			fd;
	int			mode;
	t_ast_redir	*redir;

	mode = 0;
	fd = 0;
	mode |= (redir_ptr->type == HEREDOC) * (O_CREAT | O_RDWR);
	mode |= (redir_ptr->type == INPUT) * (O_RDONLY);
	mode |= (redir_ptr->type == OUTPUT) * (O_CREAT | O_WRONLY | O_TRUNC);
	mode |= (redir_ptr->type == APPEND) * (O_CREAT | O_APPEND | O_WRONLY);
	fd += ((redir_ptr->type == OUTPUT) | (redir_ptr->type == APPEND));
	redir = (t_ast_redir *)redir_node(
			redir_ptr->type,
			clone_tok(redir_ptr->next),
			(int []){mode, fd},
			NULL);
	return (redir);
}
