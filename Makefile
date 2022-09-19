# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 20:17:18 by gialexan          #+#    #+#              #
#    Updated: 2022/09/19 20:17:19 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_FILE = so_long.c tool_check.c tool_destroy.c tool_event.c tool_map.c tool_sprite.c

SRC_DIR = src/

LIBFT_DIR = libft/

MINILIBX_DIR = minilibx/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx/libmlx.a

RM = rm -f

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

MINILIBX_FLAGS = -lX11 -lXext -lmlx

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX_FLAGS)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
			$(MAKE) -C $(MINILIBX_DIR)

clean:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(MAKE) clean -C $(MINILIBX_DIR)
					$(RM) $(OBJ)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft minilibx