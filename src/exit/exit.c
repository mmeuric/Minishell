/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:18:04 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/18 03:29:42 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GET_EXIT 0xdeadbeef

#include <exit.h>

int	exit_action(unsigned int action)
{
	static int	exit_status;

	if (action != GET_EXIT)
		exit_status = action;
	return (exit_status);
}

void	set_exit_status(unsigned int exit_status)
{
	exit_action(exit_status);
}

int	get_exit_status(void)
{
	return (exit_action(GET_EXIT));
}
