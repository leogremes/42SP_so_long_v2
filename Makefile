CC = cc
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) src/* utils/* -Iinc -g