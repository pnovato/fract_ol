NAME = fract_ol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
LIBFT_DIR = libft

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/init_mlx.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) \
		-I$(INCLUDE_DIR) \
		-I$(LIBFT_DIR) \
		-Iminilibx \
		-o $(NAME) $(OBJ) \
		-L$(LIBFT_DIR) -lft \
		-Lminilibx -lmlx -lm -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -Iminilibx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
