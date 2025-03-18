/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:30:51 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 03:33:50 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include <libft.h>

enum
{
	ATTR_SET,
	ATTR_GET,
	ATTR_CHG
};

void	set_exit_status(unsigned int exit_status);
int		get_exit_status(void);
#endif
