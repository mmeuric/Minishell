/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:27:37 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:27:39 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "globals.h"
# include "error.h"

typedef enum e_token_type
{
	WORD = 0,
	STR,
	DQSTR,
	OUTPUT,
	APPEND,
	INPUT,
	HEREDOC,
	LPREN,
	RPREN,
	PIPE,
	OR,
	AND,
	WHITE_SPACE,
	NEW_LINE
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	int				len;
	bool			to_expand;
	struct s_token	*nospace_next;
	struct s_token	*next;
}	t_token;

bool			lexer(char *command_line, t_token **tokens);
void			print_substr(int start, int end, char *str);
t_token_type	get_token_type(char *str);
int				get_token_len(t_token_type type, char *str);
// toklist
t_token			*ft_toklast(t_token *lst);
void			ft_tokadd_back(t_token **lst, t_token *new_tok);
void			ft_tokiter(t_token *lst, void (*f)(void *));
t_token			*new_token(t_token_type type, char *value, int len);
bool			add_token(t_token **tokens, t_token *token, bool is_space);
// utils
void			free_tok_lst(t_token *tok);
bool			check_expanding(char *str, t_token_type type);
bool			not_special(char c);

#endif // LEXER_H
