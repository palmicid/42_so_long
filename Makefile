# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 12:37:19 by pruangde          #+#    #+#              #
#    Updated: 2023/01/29 22:28:20 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME = uname -s

ifeq ($(UNAME), Linux)
	CC = clang
else
	CC = gcc
endif

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
MLX_PATH = mlx
MLX = $(MLX_PATH)/libmlx.a

SRCS = so_long.c cx_file_maps_1.c cx_file_maps_2.c cx_file_maps_3.c \
		cx_file_maps_4.c error_handle.c mapgen_1.c keyhook_utils_1.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) clean
	@$(RM) $(NAME)

re: fclean all

test:
	$(CC) maintest.c $(NAME)
	#valgrind --vgdb=no --leak-check=full --show-leak-kinds=all ./a.out

leak:
	leaks --atExit -- ./a.out

san:
	$(CC) -fsanitize=address -fno-omit-frame-pointer maintest.c

norm:
	@echo "------------------------------------"
	@echo " !!!!!!!!   NORMINETTE   !!!!!!!!"
	@echo ""
	@norminette -R CheckForbiddenSourceHeader *.c
	@norminette -R CheckDefine *.h
	@echo ""
	@echo "------------------------------------"
