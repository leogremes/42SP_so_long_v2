/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:39:34 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 15:45:17 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_static_images(t_data *sl)
{
	t_images	*i;
	int			w;
	int			h;

	i = &sl->images;
	i->floor = mlx_xpm_file_to_image(sl->mlx, "./sprites/floor.xpm", &w, &h);
	i->wall = mlx_xpm_file_to_image(sl->mlx, "./sprites/wall.xpm", &w, &h);
	i->exit = mlx_xpm_file_to_image(sl->mlx, "./sprites/exit.xpm", &w, &h);
	i->banner = mlx_xpm_file_to_image(sl->mlx, "./sprites/moves.xpm", &w, &h);
	i->n0 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n0.xpm", &w, &h);
	i->n1 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n1.xpm", &w, &h);
	i->n2 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n2.xpm", &w, &h);
	i->n3 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n3.xpm", &w, &h);
	i->n4 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n4.xpm", &w, &h);
	i->n5 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n5.xpm", &w, &h);
	i->n6 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n6.xpm", &w, &h);
	i->n7 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n7.xpm", &w, &h);
	i->n8 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n8.xpm", &w, &h);
	i->n9 = mlx_xpm_file_to_image(sl->mlx, "./sprites/n9.xpm", &w, &h);
}

void	get_images(t_data *sl)
{
	get_static_images(sl);
	get_animated_images(sl);
}
