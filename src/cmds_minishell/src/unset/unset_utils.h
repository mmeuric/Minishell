/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:38 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:38:42 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_UTILS_H
# define UNSET_UTILS_H
# include <global_utils.h>
# include <lst_operations.h>
# include <stdlib.h>

void	del_from_env(t_env **env, char *key);
#endif
