/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:30:01 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/29 15:35:49 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

// DEFINES
# define COLOR_DEFAULT "\033[m"
# define COLOR_GREEN "\033[1;32m"
# define COLOR_RED "\033[1;31m"
# define COLOR_YELLOW "\033[1;33m"

# define SPRITE_SIZE 32
# define BANNER_HEIGHT 32
# define BANNER_WIDTH 224

# define ANIMATION_TICKS 20000

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define DESTROY_WINDOW 17
# define KEY_PRESS 2

// STRUCTS
typedef struct s_animation
{
	void				*pl_u;
	void				*pl_d;
	void				*pl_r;
	void				*pl_l;
	void				*collec;
	void				*enemy;	
	struct s_animation	*next;
}	t_animation;

typedef struct s_images
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*banner;
	void	*n0;
	void	*n1;
	void	*n2;
	void	*n3;
	void	*n4;
	void	*n5;
	void	*n6;
	void	*n7;
	void	*n8;
	void	*n9;
}	t_images;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_images		images;
	t_animation		*head;
	t_animation		*current;
	char			**map;
	unsigned int	rows;
	unsigned int	cols;
	unsigned int	starts;
	unsigned int	exits;
	unsigned int	collectibles;
	unsigned int	player_r;
	unsigned int	player_c;
	char			player_dir;
	unsigned int	animation_tick;
	unsigned int	moves;
}	t_data;

typedef struct s_dfs
{
	unsigned int	found_exit;
	unsigned int	collecs_left;
}	t_dfs;

// FUNCTIONS
// src
int		file_check(char *map_name);
void	read_elements(t_data *sl, int fd);
void	validate_map(t_data *sl, char *map_name);
void	validate_path(t_data *sl);
void	get_images(t_data *sl);
void	get_animated_images(t_data *sl);
void	*point_to_number_image(t_data *sl, unsigned int n);
void	*point_to_image(t_data *sl, unsigned int row, unsigned int col);
int		screen_updater(t_data *sl);
int		closed_by_user(t_data *sl);
int		keypress_handler(int keycode, t_data *sl);
void	free_map(t_data *sl);
void	close_window(t_data *sl);
void	invalid_args_exit(int args_qtd);
void	invalid_elements_exit(t_data *sl);
void	error_msg_and_exit(char	*msg);
void	game_win(t_data *sl);
void	game_lose(t_data *sl);
// utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
void	ft_putnbr(int n);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strappend(char *s, char c);
char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(const char *s, char c);
size_t	ft_nbrlen(int n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif