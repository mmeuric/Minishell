/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:34:08 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:34:29 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_utils.h"
#include <stdlib.h>

static int	handle_int(char *str_number, int len)
{
	char	*max_min_str;

	max_min_str = "9223372036854775807";
	if (*str_number == '-' || *str_number == '+')
		if (*str_number++ == '-')
			max_min_str = "9223372036854775808";
	if (len > 19 || ft_memcmp(str_number, max_min_str, len) > 0)
		return (0);
	return (1);
}

static int	check_arg(char *arg)
{
	int		len;
	char	*tmp;
	int		still_zero;

	len = 0;
	tmp = arg;
	still_zero = 1;
	if (!arg || *arg == '\0')
		return (0);
	if (*arg == '+' || *arg == '-')
		arg++;
	if (*arg == '\0')
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg++))
			return (0);
		if (*arg != '0')
			still_zero = 0;
		len += !still_zero;
	}
	if (len >= 19)
		return (handle_int(tmp, len));
	return (1);
}

int	my_exit(int argc, char *arg)
{
	if (arg && !check_arg(arg))
	{
		print_err(arg, -6);
		exit(255);
	}
	if (argc > 1)
	{
		ft_putendl_fd("42shell: exit: too many arguments", 2);
		return (1);
	}
	else if (arg)
		set_exit_status(ft_atoi(arg));
	exit(get_exit_status() % 256);
}
