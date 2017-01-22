/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:58:38 by icheres           #+#    #+#             */
/*   Updated: 2016/12/29 18:06:34 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	ft_putcharf(char c)
{
	write(1, &c, 1);
}

void	ft_putstrf(char const *s)
{
	char *aux;

	aux = (char *)s;
	while (*aux)
		ft_putcharf(*aux++);
}

void	err_exit(char *s)
{
	ft_putstrf(s);
	exit(1);
}
