/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:51:23 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/29 10:58:27 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg_and_exit(char	*msg)
{
	ft_putstr(COLOR_RED);
	ft_putendl("Error!");
	ft_putstr(msg);
	ft_putendl(COLOR_DEFAULT);
	exit (0);
}

void	invalid_args_exit(int args_qtd)
{
	if (args_qtd == 1)
		error_msg_and_exit("Missing arguments!");
	error_msg_and_exit("Excessive number of arguments!");
}

void	invalid_elements_exit(t_data *sl)
{
	if (sl->exits == 0)
		error_msg_and_exit("There are no exits in this map!");
	if (sl->exits > 1)
		error_msg_and_exit("The map must contain only 1 exit!");
	if (sl->starts == 0)
		error_msg_and_exit("There are no starting points in this map!");
	if (sl->starts > 1)
		error_msg_and_exit("The map must containt only 1 starting point!");
	if (sl->collectibles == 0)
		error_msg_and_exit("There are no collectibles in the map!");
}

void	game_win(t_data *sl)
{
	ft_putendl(COLOR_GREEN);
	ft_putendl("Yb  dP  dP\"Yb  88   88     Yb        dP 88 88b 88     d8b");
	ft_putendl(" YbdP  dP   Yb 88   88      Yb  db  dP  88 88Yb88     Y8P");
	ft_putendl("  8P   Yb   dP Y8   8P       YbdPYbdP   88 88 Y88     `\"'");
	ft_putstr(" dP     YbodP  `YbodP'        YP  YP    88 88  Y8     (8)");
	ft_putendl(COLOR_DEFAULT);
	ft_putchar('\n');
	close_window(sl);
	exit(0);
}

void	game_lose(t_data *sl)
{
	ft_putendl(COLOR_RED);
	ft_putendl("Yb  dP  dP\"Yb  88   88     88      dP\"Yb  .dP\"Y8 888888\
     d8b");
	ft_putendl(" YbdP  dP   Yb 88   88     88     dP   Yb `Ybo.\" 88__    \
   Y8P");
	ft_putendl("  8P   Yb   dP Y8   8P     88  .o Yb   dP o.`Y8b 88\"\"   \
    `\"'");
	ft_putstr(" dP     YbodP  `YbodP'     88ood8  YbodP  8bodP' 888888    \
 (8)");
	ft_putendl(COLOR_DEFAULT);
	ft_putchar('\n');
	close_window(sl);
	exit(0);
}
