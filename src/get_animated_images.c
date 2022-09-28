/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_animated_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:02:06 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 15:44:18 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_animation	*get_img_node0(t_data *sl)
{
	t_animation	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_animation));
	if (!node)
		return (NULL);
	node->pl_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/pu0.xpm", &w, &h);
	node->pl_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/pd0.xpm", &w, &h);
	node->pl_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/pr0.xpm", &w, &h);
	node->pl_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/pl0.xpm", &w, &h);
	node->collec = mlx_xpm_file_to_image(sl->mlx, "./sprites/c0.xpm", &w, &h);
	node->enemy = mlx_xpm_file_to_image(sl->mlx, "./sprites/e0.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_animation	*get_img_node1(t_data *sl)
{
	t_animation	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_animation));
	if (!node)
		return (NULL);
	node->pl_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/pu1.xpm", &w, &h);
	node->pl_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/pd1.xpm", &w, &h);
	node->pl_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/pr1.xpm", &w, &h);
	node->pl_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/pl1.xpm", &w, &h);
	node->collec = mlx_xpm_file_to_image(sl->mlx, "./sprites/c1.xpm", &w, &h);
	node->enemy = mlx_xpm_file_to_image(sl->mlx, "./sprites/e1.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_animation	*get_img_node2(t_data *sl)
{
	t_animation	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_animation));
	if (!node)
		return (NULL);
	node->pl_u = mlx_xpm_file_to_image(sl->mlx, "./sprites/pu2.xpm", &w, &h);
	node->pl_d = mlx_xpm_file_to_image(sl->mlx, "./sprites/pd2.xpm", &w, &h);
	node->pl_r = mlx_xpm_file_to_image(sl->mlx, "./sprites/pr2.xpm", &w, &h);
	node->pl_l = mlx_xpm_file_to_image(sl->mlx, "./sprites/pl2.xpm", &w, &h);
	node->collec = mlx_xpm_file_to_image(sl->mlx, "./sprites/c2.xpm", &w, &h);
	node->enemy = mlx_xpm_file_to_image(sl->mlx, "./sprites/e2.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

void	get_animated_images(t_data *sl)
{
	sl->head = get_img_node0(sl);
	sl->head->next = get_img_node1(sl);
	sl->current = sl->head->next;
	sl->current->next = get_img_node2(sl);
	sl->current = sl->current->next;
	sl->current->next = get_img_node1(sl);
}
