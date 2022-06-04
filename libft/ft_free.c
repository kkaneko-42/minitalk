/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:45:34 by kkaneko           #+#    #+#             */
/*   Updated: 2022/01/24 16:50:56 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free(char **p)
{
	if (p == NULL)
		return ;
	free(*p);
	*p = NULL;
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char *str = NULL;

    ft_free(NULL);
    printf("%p\n", str);
    return (0);
}
*/
