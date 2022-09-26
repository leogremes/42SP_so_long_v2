/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:12:49 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 22:43:22 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_walls(t_data *sl);
static void	check_map_shape(t_data *sl);
static void	check_map_characters(t_data *sl);

void	validate_map(t_data *sl, char *map_name)
{
	int	fd;
	
	fd = file_check(map_name);
	read_elements(sl, fd);
	check_map_shape(sl);
	check_map_walls(sl);
	check_map_characters(sl);
}

static void	check_map_shape(t_data *sl)
{
	sl->cols = ft_strlen(sl->map[0]);
	while (sl->map[++sl->rows])
	{
		if (ft_strlen(sl->map[sl->rows]) != sl->cols)
		{
			free_map(sl);
			error_msg_and_exit("Map is not rectangular!");
		}
	}
}

static void	check_map_walls(t_data *sl)
{
	unsigned int	i;
	int				walls;

	walls = 1;
	i = -1;
	while (++i < sl->cols)
	{
		if (sl->map[0][i] != '1' || sl->map[sl->rows - 1][i] != '1')
			walls = 0;
	}
	i = -1;
	while (++i < sl->rows)
	{
		if (sl->map[i][0] != '1' || sl->map[i][sl->cols - 1] != '1')
			walls = 0;
	}
	if (!walls)
	{
		free_map(sl);
		error_msg_and_exit("Map not surrounded by walls!");
	}
}

static void	check_map_characters(t_data *sl)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < sl->rows)
	{
		j = -1;
		while (++j < sl->cols)
		{
			if (sl->map[i][j] == 'P')
			{
				sl->player_r = i;
				sl->player_c = j;
			}
			else if (sl->map[i][j] != 'N' && sl->map[i][j] != 'C' && sl->map[i][j] != '1'
				&& sl->map[i][j] != '0' && sl->map[i][j] != 'E')
			{
				free_map(sl);
				error_msg_and_exit("There are invalid characters on map");
			}
		}
	}
}