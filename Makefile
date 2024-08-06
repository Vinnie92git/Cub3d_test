# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vini <vini@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 15:58:33 by vini              #+#    #+#              #
#    Updated: 2024/08/05 18:43:04 by vini             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror \
		-I /libft/ft_printf/include \
		-I /libft/gnl/include \
		-I /libft/Libft/include \
		-I /mlx/ \
		-I /usr/include -Imlx
DEBUG = -fsanitize=address -static-libasan -g
RM = rm -f
SRC = main.c parser.c parser_utils.c parser_utils_2.c map_validation.c info_validation.c \
		data_initialisation.c render.c render_utils.c render_utils_2.c keys.c raycasting.c \
		utils.c utils_2.c

# MINILIBX
# MLX_FLAGS = -Lmlx -lmlx -Llibft -lft -lX11 -lXext -lm -lz
# MLX_FLAGS = -lmlx -lXext -lX11
# MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# MLX_FLAGS =-Lmlx -Llibft -lft -lXext -lX11 -lm -lz -lmlx_Linux

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/

OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# COLOURS
GREEN = \033[0;32m
COLOR_OFF = \033[0m

# RULES
all: $(OBJ_DIR) $(LIBFT_DIR) $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# basic library compiled
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)
	@echo "$(GREEN)#### Cub3D ####$(COLOR_OFF)"
	@echo "    -Has been compiled ✅"

# all .o files removed
clean:
	@$(RM) $(OBJ)
	@make clean -C libft
	@rm -rf $(OBJ_DIR)

# library .a file removed
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@rm -rf $(OBJ_DIR)

re:	fclean all

.PHONY:	all clean fclean re
