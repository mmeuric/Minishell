/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:30:02 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 03:37:38 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "stringbuilder.h"
# include "exit.h"

void	syntax_error(char *where);
void	tok_error(char which);
void	unclosed_error(char which);
int		print_err(char *preced, int msg_code);

#endif // ERROR_H
