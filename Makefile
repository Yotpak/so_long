SRCS = getmap.c so_long.c utils.c ft_error.c


NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -framework AppKit -framework OpenGL -L./library/mlx_library -lmlx
MLX = ./library/mlx_library/libmlx.a
FT_PRINTF = ./library/ft_printf/libftprintf.a
GET_NEXT_LINE = ./library/gnl/get_next_line.c ./library/gnl/get_next_line_utils.c
RM = rm -rf
LIBC = ar -rcs

all: $(MLX) $(NAME)

$(NAME): $(SRCS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

bonus : $(SRCBS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)

$(MLX) :
	@make -C ./library/mlx_library

$(FT_PRINTF) :
	@make -C ./library/ft_printf

clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./library/mlx_library
	@make fclean -C ./library/ft_printf

re: fclean all

.PHONY: all bonus clean fclean re .c.o