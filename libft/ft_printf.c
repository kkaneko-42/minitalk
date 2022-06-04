/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko </var/mail/kkaneko>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:58:34 by kkaneko           #+#    #+#             */
/*   Updated: 2022/01/23 02:33:16 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printopt_str(const char next, va_list *ap)
{
	int		res;
	char	*tmp_arg;

	res = 0;
	if (next == 's')
	{
		tmp_arg = va_arg(*ap, char *);
		if (tmp_arg == NULL)
			tmp_arg = NUL_STR;
		res += ft_strlen(tmp_arg);
		ft_putstr_fd(tmp_arg, 1);
	}
	if (next == 'c')
	{
		res += 1;
		ft_putchar_fd(va_arg(*ap, int), 1);
	}
	if (next == '%')
	{
		res += 1;
		ft_putchar_fd('%', 1);
	}
	return (res);
}

static int	printopt_digit(const char next, va_list *ap)
{
	if (next == 'i' || next == 'd')
		return (ft_putint(va_arg(*ap, int)));
	if (next == 'u')
		return (ft_putuint_base(va_arg(*ap, t_uint), DECI));
	if (next == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_putuint_base((size_t)va_arg(*ap, void *), HEXA_S) + 2);
	}
	if (next == 'x')
		return (ft_putuint_base((t_uint)va_arg(*ap, int), HEXA_S));
	if (next == 'X')
		return (ft_putuint_base((t_uint)va_arg(*ap, int), HEXA_L));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	i;
	int		res;
	va_list	ap;

	va_start(ap, fmt);
	res = 0;
	i = 0;
	while (fmt[i] != 0x00)
	{
		if (fmt[i] == '%')
		{
			res += printopt_str(fmt[i + 1], &ap);
			res += printopt_digit(fmt[i + 1], &ap);
			++i;
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			++res;
		}
		++i;
	}
	va_end(ap);
	return (res);
}
