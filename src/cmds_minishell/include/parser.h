/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:05 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:39:32 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "syntax_tree.h"
# include "lexer.h"
# include "error.h"
# include "heredoc.h"

bool	parser(t_token *tokens, t_ast_cmd **tree);

#endif // PARSER_H
