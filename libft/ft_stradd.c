/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:39:30 by kkaneko           #+#    #+#             */
/*   Updated: 2022/01/24 16:54:00 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_stradd(char const *s, char const c)
{
	char	*res;
	size_t	res_size;
	size_t	src_len;

	if (s == NULL)
		res_size = 2;
	else
		res_size = ft_strlen(s) + 2;
	res = (char *)malloc(sizeof(char) * res_size);
	if (res == NULL)
		return (NULL);
	if (s == NULL)
	{
		res[0] = c;
		res[1] = 0x00;
	}
	else
	{
		src_len = ft_strlen(s);
		ft_strlcpy(res, s, src_len + 1);
		res[src_len] = c;
		res[src_len + 1] = 0x00;
	}
	return (res);
}
