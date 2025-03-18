/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:27:57 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:27:59 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_OPERATIONS_H
# define LST_OPERATIONS_H
# include <libft.h>

t_env	*ft_lstnew(char *key, char *value, int equal_sign, t_env *prev);
void	ft_lstadd_back(t_env **lst, t_env *new);
int		ft_lstsize(t_env *lst);
void	ft_lstdelone(t_env *lst, void (*del)(void *));
t_env	*ft_lstlast(t_env *lst);
int		ft_lstsize(t_env *lst);
#endif
