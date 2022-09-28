/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:47:31 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 17:38:18 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void set_to_zero(t_data *sl);
static void	so_long(t_data *sl);

/* int	main(int argc, char **argv)
{
	t_data	sl;
	
	if (argc != 2)
		invalid_args_exit(argc);
	set_to_zero(&sl);
	validate_map(&sl, argv[1]);
	size_t i = -1;
	while (sl.map[++i])
		ft_putendl(sl.map[i]);
	free_map(&sl);
	ft_putstr("Player_row: ");
	ft_putnbr(sl.player_r);
	ft_putstr("\nPlayer_col: ");
	ft_putnbr(sl.player_c);
	ft_putchar('\n');
	so_long(&sl);
	return (0);
} */

int	main(void)
{
	t_data	sl;
	
	set_to_zero(&sl);
	validate_map(&sl, "map42.ber");
	size_t i = -1;
	while (sl.map[++i])
		ft_putendl(sl.map[i]);
	ft_putstr("rows: ");
	ft_putnbr(sl.rows);
	ft_putstr("\ncols: ");
	ft_putnbr(sl.cols);
	ft_putchar('\n');
	so_long(&sl);
	free_map(&sl);
	return (0);
}

static void	so_long(t_data *sl)
{
	unsigned int window_width;

	window_width = sl->cols * SPRITE_SIZE;
	if (window_width < BANNER_WIDTH + (BANNER_HEIGHT * 3))
		window_width = BANNER_WIDTH + (BANNER_HEIGHT * 3);	
	sl->mlx = mlx_init();
	if (sl->mlx)
	{
		sl->win = mlx_new_window(sl->mlx, window_width,
			sl->rows * SPRITE_SIZE + BANNER_HEIGHT, "so_long");
		if (sl->win)
		{
			get_images(sl);
			mlx_loop_hook(sl->mlx, &screen_updater, sl);
			mlx_hook(sl->win, KEY_PRESS, KP_MASK, &keypress_handler, sl);
			mlx_hook(sl->win, DESTROY_WINDOW, 0, &closed_by_user, sl);
			mlx_loop(sl->mlx);
		}
	}
	else
	 	ft_putendl("No pointer");
}


static void	set_to_zero(t_data *sl)
{
	sl->rows = 0;
	sl->cols = 0;
	sl->starts = 0;
	sl->exits = 0;
	sl->collectibles = 0;
	sl->player_r = 0;
	sl->player_c = 0;
	sl->player_dir = 'r';
	sl->animation_tick = 0;
	sl->moves = 0;
	sl->head = NULL;
	sl->current = NULL;
	sl->map = NULL;
}
