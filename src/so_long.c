/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:47:31 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 22:41:55 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void set_to_zero(t_data *sl);

int	main(int argc, char **argv)
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
	return (0);
}

/* int	main(void)
{
	t_data	sl;
	int		i;
	
	set_to_zero(&sl);
	validate_map(&sl, "map00.ber");
	i = -1;
	while (sl.map[++i])
		ft_putendl(sl.map[i]);
	free_map(&sl);
	return (0);
} */

static void	set_to_zero(t_data *sl)
{
	sl->rows = 0;
	sl->cols = 0;
	sl->starts = 0;
	sl->exits = 0;
	sl->collectibles = 0;
	sl->player_r = 0;
	sl->player_c = 0;
	sl->animation_tick = 0;
	sl->head = NULL;
	sl->current = NULL;
	sl->map = NULL;
}
