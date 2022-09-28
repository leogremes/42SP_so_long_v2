/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:13:01 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 16:36:53 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

size_t	ft_nbrlen(int n)
{
	size_t	counter;

	counter = 1;
	if (n < 0)
		counter++;
	else
		n *= -1;
	while (n <= -10)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
