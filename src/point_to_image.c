/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:41:25 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 15:45:49 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*point_to_player_image(t_data *sl);

void	*point_to_number_image(t_data *sl, unsigned int n)
{
	if (n == 0)
		return (sl->images.n0);
	if (n == 1)
		return (sl->images.n1);
	if (n == 2)
		return (sl->images.n2);
	if (n == 3)
		return (sl->images.n3);
	if (n == 4)
		return (sl->images.n4);
	if (n == 5)
		return (sl->images.n5);
	if (n == 6)
		return (sl->images.n6);
	if (n == 7)
		return (sl->images.n7);
	if (n == 8)
		return (sl->images.n8);
	if (n == 9)
		return (sl->images.n9);
	return (NULL);
}

void	*point_to_image(t_data *sl, unsigned int row, unsigned int col)
{
	if (sl->map[row][col] == '1')
		return (sl->images.wall);
	if (sl->map[row][col] == '0')
		return (sl->images.floor);
	if (sl->map[row][col] == 'E')
		return (sl->images.exit);
	if (sl->map[row][col] == 'C')
		return (sl->current->collec);
	if (sl->map[row][col] == 'N')
		return (sl->current->enemy);
	if (sl->map[row][col] == 'P')
		return (point_to_player_image(sl));
	return (NULL);
}

static void	*point_to_player_image(t_data *sl)
{
	if (sl->player_dir == 'u')
		return (sl->current->pl_u);
	if (sl->player_dir == 'd')
		return (sl->current->pl_d);
	if (sl->player_dir == 'l')
		return (sl->current->pl_l);
	return (sl->current->pl_r);
}
