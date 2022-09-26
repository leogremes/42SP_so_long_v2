/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:26:07 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 22:29:06 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_elements(t_data *sl, char c);

int	file_check(char *map_name)
{
	char	*file_path;
	int		fd;
	
	if (ft_strstr(map_name, ".ber\0") == NULL)
		error_msg_and_exit("Map must be a .ber file!");
	file_path = ft_strjoin("./maps/", map_name);
	fd = open(file_path, O_RDONLY);
	free(file_path);
	if (fd < 0)
		error_msg_and_exit("Inexistent map file!");
	return (fd);
}

void	read_elements(t_data *sl, int fd)
{
	char	buffer;
	char	*map_str;

	map_str = NULL;
	while (read(fd, &buffer, 1) > 0)
	{
		count_elements(sl, buffer);
		if (buffer != ' ')
			map_str = ft_strappend(map_str, buffer);
	}
	close(fd);
	if (sl->exits != 1 || sl->starts != 1 || sl->collectibles == 0)
	{
		if (map_str)
			free(map_str);
		invalid_elements_exit(sl);
	}
	sl->map = ft_split(map_str, '\n');
	free(map_str);
}

static void	count_elements(t_data *sl, char c)
{
	if (c == 'E')
		sl->exits++;
	else if (c == 'C')
		sl->collectibles++;
	else if (c == 'P')
		sl->starts++;
}
