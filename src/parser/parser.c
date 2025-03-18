/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:52:21 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 03:22:53 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

bool	parser(t_token *tokens, t_ast_cmd **tree)
{
	t_token		*current;

	*tree = NULL;
	if (!tokens)
		return (false);
	current = tokens;
	if (current->type == NEW_LINE)
		return (free_tok_lst(tokens), true);
	*tree = parse_cmd(&current);
	if (!(*tree) || current->type != NEW_LINE)
	{
		syntax_error(current->value);
		return (free_tok_lst(tokens), false);
	}
	free_tok_lst(tokens);
	return (patch_heredoc(*tree));
}
