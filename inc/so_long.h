/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leda-sil <leda-sil@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:30:01 by leda-sil          #+#    #+#             */
/*   Updated: 2022/09/26 22:28:30 by leda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//# include "mlx.h"

// COLORS
# define COLOR_DEFAULT "\033[m"
# define COLOR_BOLD "\033[1m"
# define COLOR_GREEN "\033[32m"
# define COLOR_RED "\033[31;m"
# define COLOR_YELLOW "\033[33m"
// SIZES
# define SPRITE_SIZE 32
# define BANNER_HEIGHT 32
# define BANNER_WIDTH 224
// TIME
# define ANIMATION_TCKS 10000
//STRUCTS
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
	unsigned int	animation_tick;
} t_data;
//SRC
//validate_map.c
void	validate_map(t_data *sl, char *map_name);
//validate_file.c
int		file_check(char *map_name);
void	read_elements(t_data *sl, int fd);
//free_memory.c
void	free_map(t_data *sl);
//exit_messages.c
void	invalid_args_exit(int args_qtd);
void	invalid_elements_exit(t_data *sl);
void	error_msg_and_exit(char	*msg);
//UTILS
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
void	ft_putnbr(int n);
char	**ft_split(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strappend(char *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char 	*ft_strstr(const char *haystack, const char *needle);

#endif