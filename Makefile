CC = cc
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) src/* utils/* minilibx-linux/libmlx.a -Iinc -Iminilibx-linux -lX11 -lXext -g