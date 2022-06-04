/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:35:43 by kkaneko           #+#    #+#             */
/*   Updated: 2022/06/05 01:35:41 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static sig_atomic_t	g_sig;

static void	sig_handler(int sig)
{
	g_sig = sig;
}

void	receiver(void (*handler)(int))
{
	int					err_fg;
	struct sigaction	act;

	err_fg = 0;
	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_handler = handler;
	err_fg += sigemptyset(&(act.sa_mask));
	err_fg += sigaction(SIGUSR1, &act, NULL);
	err_fg += sigaction(SIGUSR2, &act, NULL);
	if (err_fg < 0)
	{
		ft_printf(INIT_ERR);
		exit(1);
	}
}

static t_uchar	get_char(void)
{
	t_uchar	c;
	short	cnt_byte;

	c = 0;
	cnt_byte = 0;
	while (1)
	{
		pause();
		c <<= 1;
		if (g_sig == SIGUSR1)
			c |= 0;
		if (g_sig == SIGUSR2)
			c |= 1;
		++cnt_byte;
		if (cnt_byte == PER_BYTE)
			break ;
	}
	return (c);
}

static char	*get_str(void)
{
	t_uchar	c;
	char	*str;
	char	*tmp;

	str = INIT;
	c = 0;
	while (1)
	{
		c = get_char();
		if (c == ETX)
			break ;
		else
		{
			tmp = str;
			str = ft_stradd(str, c);
			if (str == NULL)
			{
				ft_printf(MALLOC_ERR);
				ft_free(&tmp);
				break ;
			}
			ft_free(&tmp);
		}
	}
	return (str);
}

int	main(void)
{
	char	*str;

	ft_printf("PID:%d\n", getpid());
	receiver(sig_handler);
	while (1)
	{
		str = get_str();
		ft_printf("%s", str);
		ft_free(&str);
	}
	return (0);
}
