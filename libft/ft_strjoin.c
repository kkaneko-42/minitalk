/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:56:54 by kkaneko           #+#    #+#             */
/*   Updated: 2022/01/24 00:50:17 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*check_null(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	res_len;

	if (s1 == NULL || s2 == NULL)
		return (check_null(s1, s2));
	res_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, res_len + 1);
	return (res);
}
/*
#include <stdio.h>
int main()
{
	char	*str1 = ft_strdup("this is a pen");
	char	*str2 = ft_strdup("hello, world");
	char	*nul = NULL;

	printf("s1 + s2 = %s\n", ft_strjoin(str1, str2));
	printf("s1 + null = %s\n", ft_strjoin(str1, nul));
	printf("nul + s2 = %s\n", ft_strjoin(nul, str2));
	printf("nul *+ nul = %s\n", ft_strjoin(nul, nul));
	return (0);
}
*/
