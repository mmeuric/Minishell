/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:52:01 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 04:32:14 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <syntax_tree.h>

t_ast_cmd	*binary_node(t_node_type type, t_ast_cmd *left, t_ast_cmd *right)
{
	t_ast_binary	*node;

	node = ft_malloc(sizeof(t_ast_binary));
	if (!node)
		return (NULL);
	node->type = type;
	node->left = left;
	node->right = right;
	return ((t_ast_cmd *) node);
}

t_ast_cmd	*exec_node(t_token *argv_tok)
{
	t_ast_exec	*node;

	node = ft_malloc(sizeof(t_ast_exec));
	if (!node)
		return (NULL);
	node->type = P_EXEC;
	node->argv_tok = argv_tok;
	return ((t_ast_cmd *) node);
}

t_ast_cmd	*redir_node(t_token_type direction, t_token *file_tok,
	int mode_fd[2], t_ast_cmd *cmd)
{
	t_ast_redir	*node;

	node = ft_malloc(sizeof(t_ast_redir));
	if (!node)
		return (NULL);
	node->type = P_REDIR;
	node->direction = direction;
	node->file_tok = file_tok;
	node->mode = mode_fd[0];
	node->fd = mode_fd[1];
	node->cmd = cmd;
	return ((t_ast_cmd *) node);
}

t_ast_cmd	*subsh_node(t_ast_cmd *cmd)
{
	t_ast_subsh	*node;

	node = ft_malloc(sizeof(t_ast_subsh));
	if (!node)
		return (NULL);
	node->type = P_SUBSH;
	node->cmd = cmd;
	return ((t_ast_cmd *) node);
}
