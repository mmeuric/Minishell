/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:57:41 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:30:33 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_TREE_H
# define SYNTAX_TREE_H

# include "lexer.h"
# include "libft.h"

/* -------------------------------------------------------------------------- */
/*                                ENUMERATIONS                                */
/* -------------------------------------------------------------------------- */

typedef enum e_node_type
{
	P_EXEC,
	P_SUBSH,
	P_REDIR,
	P_PIPE,
	P_AND,
	P_OR
}	t_node_type;

/* -------------------------------------------------------------------------- */
/*                                STRUCTURES                                  */
/* -------------------------------------------------------------------------- */

/* Structure de base pour un nœud AST */
typedef struct s_cmd
{
	t_node_type		type;
}	t_ast_cmd;

/* Commande avec arguments */
typedef struct s_ast_exec
{
	t_node_type		type;
	t_token			*argv_tok;
}	t_ast_exec;

/* Redirection */
typedef struct s_ast_redir
{
	t_node_type		type;
	t_token_type	direction;
	t_token			*file_tok;
	int				fd;
	int				mode;
	t_ast_cmd		*cmd;
}	t_ast_redir;

/* Opérations binaires (AND, OR, PIPE) */
typedef struct s_ast_binary
{
	t_node_type		type;
	t_ast_cmd		*left;
	t_ast_cmd		*right;
}	t_ast_binary;

/* Sous-shell */
typedef struct s_ast_subsh
{
	t_node_type		type;
	t_ast_cmd		*cmd;
}	t_ast_subsh;

/* -------------------------------------------------------------------------- */
/*                             FONCTIONS PRINCIPALES                          */
/* -------------------------------------------------------------------------- */

t_ast_cmd	*parse_cmd(t_token **current);

/* Création de nœuds AST */
t_ast_cmd	*exec_node(t_token *argv_tok);
t_ast_cmd	*subsh_node(t_ast_cmd *cmd);
t_ast_cmd	*binary_node(t_node_type type, t_ast_cmd *left, t_ast_cmd *right);
t_ast_cmd	*redir_node(t_token_type direction, t_token *file_tok,
				int mode_fd[2], t_ast_cmd *cmd);

/* -------------------------------------------------------------------------- */
/*                                UTILITAIRES                                 */
/* -------------------------------------------------------------------------- */

void		advance(t_token **current);
bool		match(t_token *tok, t_token_type types[], int size);
t_token		*clone_tok(t_token *tok);
void		free_ast(t_ast_cmd *tree);
void		free_tok_lst(t_token *tok);
t_ast_redir	*tok_to_redir(t_token *redir_ptr);
void		print_nosp_tok(FILE *f, t_token *tok); // Debug

/* -------------------------------------------------------------------------- */
/*                            UTILITAIRES REDIRECTION                         */
/* -------------------------------------------------------------------------- */

t_ast_cmd	*redir_file(t_token **current);
bool		add_redir_node(t_ast_redir **lst, t_ast_cmd *node);
void		free_redir(t_ast_cmd *sub_sh, t_ast_redir *redir_lst,
				t_token *exe_lst);

#endif /* SYNTAX_TREE_H */
