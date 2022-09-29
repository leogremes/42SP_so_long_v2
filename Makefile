SRC_DIR			=	src/
SRC_FILES		=	exit_messages.c		free_memory.c		get_animated_images.c	\
					get_images.c		point_to_image.c	so_long.c				\
					validate_file.c		validate_map.c		validate_path.c			\
					window_drawing.c	window_events.c
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

UTILS_DIR		=	utils/
UTILS_FILES		=	ft_putstr.c			ft_split.c			ft_strlcpy.c			\
					ft_strlen.c			ft_strncmp.c
UTILS			=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

OBJ_DIR			=	obj/
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))	\
					$(addprefix $(OBJ_DIR), $(UTILS_FILES:.c=.o))

MLX_DIR			=	minilibx-linux/
MLX_LIB			=	libmlx.a
MLX				=	$(addprefix $(MLX_DIR), $(MLX_LIB))
MLX_INC			=	mlx.h
MLXFLAGS		=	-lX11 -lXext

INC_DIR			=	inc/
INC_FILES		=	so_long.h
INCLUDES		=	$(addprefix $(INC_DIR), $(INC_FILES)) \
					$(addprefix $(MLX_DIR), $(MLX_INC))

NAME			=	so_long
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ) $(MLX) msg
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) -o $@

$(MLX):
	make -C $(MLX_DIR)

$(OBJ_DIR)%.o: */%.c $(INCLUDES) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INC_DIR) -I$(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

msg:
	@echo "\n\n\
:*^*:._.:*^*:._.:*^*:._.:*^*:._.:*^*:._.:*^*:._.:*^*:._.:*^*:\n\
:                                                           :\n\
:           YOUR GAME IS READY TO PLAY                      :\n\
:                                                           :\n\
:      Type \"./so_long <map_name>.ber\" to play              :\n\
:  Type \"ls -1 maps/*ber\" to see the available maps         :\n\
:                                                           :\n\
:._.:*^*:._.:*^*:._.:*^*:._.:*^*:._.:*^*:._.:*^*:._.:*^*:._.:\n\n"

.PHONY: all bonus clean fclean re msg