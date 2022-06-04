/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 06:52:07 by kkaneko           #+#    #+#             */
/*   Updated: 2022/01/24 00:50:26 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0x00)
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = 0x00;
	return (res);
}
/*
#include <stdio.h>
#include <string.h>
int main(int ac, char **av)
{
	printf("----src:%s---\n", av[1]);
	printf("ori:%s\n", strdup(av[1]));
	printf("made:%s\n", ft_strdup(av[1]));
	return (0);
}
*/
