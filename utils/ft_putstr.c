/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:02:51 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 21:03:15 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
	{
		while (s[0])
			ft_putchar(s++[0]);
	}
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	else
		n *= -1;
	if (n <= -10)
		ft_putnbr(-1 * (n / 10));
	ft_putchar((-1 * (n % 10)) + '0');
}
