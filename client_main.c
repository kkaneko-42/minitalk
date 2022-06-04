/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:13:23 by kkaneko           #+#    #+#             */
/*   Updated: 2022/06/05 01:30:04 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(pid_t pid, const t_uchar bit)
{
	int	kill_fg;

	kill_fg = 0;
	if (bit & 1)
	{
		kill_fg = kill(pid, SIGUSR2);
		usleep(SLEEP_USEC);
	}
	else
	{
		kill_fg = kill(pid, SIGUSR1);
		usleep(SLEEP_USEC);
	}
	if (kill_fg < 0)
	{
		ft_printf(SEND_ERR);
		exit(1);
	}
}

size_t	send_char(pid_t pid, const char c)
{
	ssize_t	i;
	size_t	res;
	t_uchar	uc;

	uc = (t_uchar)c;
	res = 0;
	i = sizeof(char) * PER_BYTE - 1;
	while (i >= 0)
	{
		send_bit(pid, (uc >> i));
		++res;
		--i;
	}
	return (res);
}

static size_t	send_str(pid_t pid, const char *str)
{
	size_t	i;
	size_t	n_sent;

	i = 0;
	while (str[i] != 0x00)
	{
		n_sent = send_char(pid, str[i]);
		if (n_sent != sizeof(char) * PER_BYTE)
		{
			ft_printf(SEND_ERR);
			exit(1);
		}
		++i;
	}
	send_char(pid, ETX);
	return (i);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf(ARG_ERR);
		return (1);
	}
	pid = (pid_t)ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf(ARG_ERR);
		return (1);
	}
	send_str(pid, av[2]);
	return (0);
}
