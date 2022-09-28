/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:08:08 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/27 17:37:03 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_tile(t_data *sl, t_dfs *dfs, unsigned int row,
	unsigned int col);
static int	check_path(t_data *sl, t_dfs *dfs, unsigned int row,
	unsigned int col);
static void	fix_map(t_data *sl);

void	validate_path(t_data *sl)
{
	t_dfs	dfs;

	dfs.found_exit = 0;
	dfs.collecs_left = sl->collectibles;
	if (!check_path(sl, &dfs, sl->player_r, sl->player_c))
	{
		free_map(sl);
		error_msg_and_exit("There are no valid path!");
	}
	fix_map(sl);
}

static int	check_tile(t_data *sl, t_dfs *dfs, unsigned int row,
	unsigned int col)
{
	if (sl->map[row][col] == '1' || sl->map[row][col] == '2'
		|| sl->map[row][col] == '3' || sl->map[row][col] == 'N')
		return (0);
	if (sl->map[row][col] == 'E')
	{
		if (!dfs->collecs_left)
			return (1);
		dfs->found_exit = 1;
		return (0);
	}
	if (sl->map[row][col] == 'C')
	{
		if (!--dfs->collecs_left && dfs->found_exit)
			return (1);
		return ('3');
	}
	return ('2');
}

static int	check_path(t_data *sl, t_dfs *dfs, unsigned int row,
	unsigned int col)
{
	int tile;
	int	done;

	tile = check_tile(sl, dfs, row, col);
	if (tile == 0 || tile == 1)
		return (tile);
	sl->map[row][col] = tile;
	done = check_path(sl, dfs, row - 1, col);
	if (!done)
		done = check_path(sl, dfs, row, col + 1);
	if (!done)
		done = check_path(sl, dfs, row + 1, col);
	if (!done)
		done = check_path(sl, dfs, row, col - 1);
	return (done);
}

static void	fix_map(t_data *sl)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < sl->rows)
	{
		j = -1;
		while (++j < sl->cols)
		{
			if (sl->map[i][j] == '2')
				sl->map[i][j] = '0';
			else if (sl->map[i][j] == '3')
				sl->map[i][j] = 'C';
		}
	}
	sl->map[sl->player_r][sl->player_c] = 'P';
}