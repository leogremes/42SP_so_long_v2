/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:19:54 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/29 15:23:10 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_data *sl, unsigned int row, unsigned int col);
static void	change_animation_sprite(t_data *sl);
static void	draw_banner(t_data *sl);

int	screen_updater(t_data *sl)
{
	unsigned int	row;
	unsigned int	col;

	if (sl->win)
	{
		change_animation_sprite(sl);
		draw_banner(sl);
		row = -1;
		while (++row < sl->rows)
		{
			col = -1;
			while (++col < sl->cols)
				put_image(sl, row, col);
		}
	}
	return (0);
}

static void	put_image(t_data *sl, unsigned int row, unsigned int col)
{
	void	*img;

	img = point_to_image(sl, row, col);
	if (img)
	{
		mlx_put_image_to_window(sl->mlx, sl->win, img, col * SPRITE_SIZE,
			row * SPRITE_SIZE + BANNER_HEIGHT);
	}
	sl->animation_tick++;
}

static void	change_animation_sprite(t_data *sl)
{
	if (sl->animation_tick >= ANIMATION_TICKS)
	{
		sl->animation_tick = 0;
		if (sl->current->next)
			sl->current = sl->current->next;
		else
			sl->current = sl->head;
	}
}

static void	draw_banner(t_data *sl)
{
	void	*img;
	int		moves;
	int		len;
	int		i;

	moves = sl->moves;
	len = ft_nbrlen(moves);
	if (len < 3)
		len = 3;
	if (sl->images.banner)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->images.banner, 0, 0);
	i = 0;
	while (++i <= len)
	{
		img = NULL;
		if (moves > 0 || i == 1)
			img = point_to_number_image(sl, moves % 10);
		if (img)
		{
			mlx_put_image_to_window(sl->mlx, sl->win, img,
				BANNER_WIDTH + ((len - i) * BANNER_HEIGHT), 0);
			moves /= 10;
		}
	}
}
