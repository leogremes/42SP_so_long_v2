/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:51:23 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 22:41:32 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg_and_exit(char	*msg)
{
	ft_putstr(COLOR_RED);
	ft_putstr(COLOR_BOLD);
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
