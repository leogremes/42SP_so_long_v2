/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:23:25 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 17:32:56 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_static_images(t_data *sl);
static void	free_animated_node(t_animation *node, t_data *sl);

void	free_map(t_data *sl)
{
	size_t	i;
	
	if (sl->map)
	{
		i = -1;
		while (sl->map[++i])
			free(sl->map[i]);
		free(sl->map);
	}
}

void	close_window(t_data *sl)
{
	t_animation	*tmp;

	free_static_images(sl);
	sl->current = NULL;
	while(sl->head)
	{
		tmp = sl->head->next;
		free_animated_node(sl->head, sl);
		free(sl->head);
		sl->head = tmp;
	}
	mlx_destroy_window(sl->mlx, sl->win);
	sl->win = NULL;
	mlx_destroy_display(sl->mlx);
}

static void	free_static_images(t_data *sl)
{
	mlx_destroy_image(sl->mlx, sl->images.floor);
	mlx_destroy_image(sl->mlx, sl->images.wall);
	mlx_destroy_image(sl->mlx, sl->images.exit);
	mlx_destroy_image(sl->mlx, sl->images.banner);
	mlx_destroy_image(sl->mlx, sl->images.n0);
	mlx_destroy_image(sl->mlx, sl->images.n1);
	mlx_destroy_image(sl->mlx, sl->images.n2);
	mlx_destroy_image(sl->mlx, sl->images.n3);
	mlx_destroy_image(sl->mlx, sl->images.n4);
	mlx_destroy_image(sl->mlx, sl->images.n5);
	mlx_destroy_image(sl->mlx, sl->images.n6);
	mlx_destroy_image(sl->mlx, sl->images.n7);
	mlx_destroy_image(sl->mlx, sl->images.n8);
	mlx_destroy_image(sl->mlx, sl->images.n9);
}

static void	free_animated_node(t_animation *node, t_data *sl)
{
	mlx_destroy_image(sl->mlx, node->pl_u);
	mlx_destroy_image(sl->mlx, node->pl_d);
	mlx_destroy_image(sl->mlx, node->pl_r);
	mlx_destroy_image(sl->mlx, node->pl_l);
	mlx_destroy_image(sl->mlx, node->collec);
	mlx_destroy_image(sl->mlx, node->enemy);
}
