/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:50:17 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/28 17:41:11 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_player_movement(unsigned int row_dst, unsigned int col_dst,
	t_data *sl);
static void move_player(unsigned int row_dst, unsigned int col_dst,
	t_data *sl);

int	closed_by_user(t_data *sl)
{
	ft_putstr(COLOR_YELLOW);
	ft_putstr("Game closed by user!");
	ft_putendl(COLOR_DEFAULT);
	close_window(sl);
	exit(0);
}

int	keypress_handler(int keycode, t_data *sl)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		sl->player_dir = 'u';
		check_player_movement(sl->player_r - 1, sl->player_c, sl);
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		sl->player_dir = 'd';
		check_player_movement(sl->player_r + 1, sl->player_c, sl);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		sl->player_dir = 'r';
		check_player_movement(sl->player_r, sl->player_c + 1, sl);
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		sl->player_dir = 'l';
		check_player_movement(sl->player_r, sl->player_c - 1, sl);
	}
	if (keycode == KEY_ESC)
		closed_by_user(sl);
	return (0);
}

static void	check_player_movement(unsigned int row_dst, unsigned int col_dst,
	t_data *sl)
{
	char	c;

	c = sl->map[row_dst][col_dst];
	if (c == '0')
		move_player(row_dst, col_dst, sl);
	else if (c == 'C')
	{
		sl->collectibles--;
		move_player(row_dst, col_dst, sl);
	}
	else if (c == 'E')
	{
		if (!sl->collectibles)
			game_win(sl);
	}
	else if (c == 'N')
		game_lose(sl);
}

static void move_player(unsigned int row_dst, unsigned int col_dst,
	t_data *sl)
{
	sl->map[row_dst][col_dst] = 'P';
	sl->map[sl->player_r][sl->player_c] = '0';
	sl->player_r = row_dst;
	sl->player_c = col_dst;
	sl->moves++;
}
