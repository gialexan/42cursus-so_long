# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 02:09:45 by gialexan          #+#    #+#              #
#    Updated: 2022/11/25 14:01:47 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				so_long

NAME_BONUS =		so_long_bonus

MAP =				map/map.ber

MAP_BONUS =         map/map_bonus.ber

SRC_FILE = 			so_long.c tool_check.c tool_destroy.c tool_event.c tool_map.c tool_sprite.c

SRC_BONUS_FILE =	so_long_bonus.c tool_animation_bonus.c tool_destroy_bonus.c tool_event_player_bonus.c \
tool_sprite_bonus.c tool_check_bonus.c tool_event_monster_bonus.c tool_map_bonus.c

SRC_DIR_BONUS = 	src_bonus

SRC_DIR = 			src

LIBFT_DIR = 		libft

MINILIBX_DIR = 		minilibx

SRC_BONUS =			$(addprefix $(SRC_DIR_BONUS)/, $(SRC_BONUS_FILE))

SRC = 				$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ = 				$(SRC:.c=.o)

OBJ_BONUS =			$(SRC_BONUS:.c=.o)

LIBFT = 			./libft/libft.a

MINILIBX = 			./minilibx/libmlx.a

RM = 				rm -f

CC = 				clang

CFLAGS = 			-Wall -Wextra -Werror -g

MINILIBX_FLAGS = 	-lX11 -lXext -lmlx

all: $(NAME)
		./so_long $(MAP)

bonus: $(NAME_BONUS)
		./so_long_bonus $(MAP_BONUS)

$(NAME):			$(LIBFT) $(MINILIBX) $(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(MINILIBX) $(OBJ_BONUS)
					$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS) -o $(NAME_BONUS)

$(LIBFT):
					$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
					$(MAKE) -C $(MINILIBX_DIR)

vm:					$(NAME)
					valgrind ./so_long $(MAP)

vb:					$(NAME_BONUS)
					valgrind ./so_long_bonus $(MAP_BONUS)
clean:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(MAKE) clean -C $(MINILIBX_DIR)
					$(RM) $(OBJ)
					$(RM) $(OBJ_BONUS)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft minilibx