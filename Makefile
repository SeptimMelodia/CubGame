# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stune <stune@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 02:37:00 by stune             #+#    #+#              #
#    Updated: 2021/03/30 18:50:37 by stune            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = 	all_elem.c\
		all_struct.c\
		check_valid_map.c\
		draw_wall.c\
		draw3d.c\
		error_handler.c\
		g_win.c\
		get_textures.c\
		main.c\
		make_screen.c\
		map_parser.c\
		minimapa.c\
		move.c\
		norminette_correct.c\
		ray_casting.c\
		sprit_not_drink.c\
		utils.c\
		get_next_line_utils.c\
		get_next_line.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAG = -g -Wall -Wextra -Werror
MLX = libmlx.dylib
LIB = libft.a
MLX_PATH = minilibx_mms_20200219/
LIB_PATH = libft_m/

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C $(LIB_PATH)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAG) -L$(MLX_PATH) -lmlx -L$(LIB_PATH) -lft $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)
	cp minilibx_mms_20200219/libmlx.dylib .

%.o: %.c cub3d.h
	$(CC) -c $(CFLAG) -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX)
	$(MAKE) clean -C $(MLX_PATH)
	$(MAKE) fclean -C $(LIB_PATH)

re: fclean all
