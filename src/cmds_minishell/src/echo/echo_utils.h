/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:31:49 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:31:51 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_UTILS_H
# define ECHO_UTILS_H
# include <global_utils.h>
# include <unistd.h>

void	print_spaced_arg(char *arg);
void	print_last_arg(char *arg, int new_line);
int		consist_of(char *line, char c);
size_t	count(const char *s, int c);
#endif
