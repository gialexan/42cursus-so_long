/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:19:16 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/24 23:53:19 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//Includes
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

//Sprites Other
# define SPRITE		32
# define PATH_FLOOR 	"./img/other/space.xpm"
# define PATH_WALL 		"./img/other/wall.xpm"
# define PATH_EXIT 		"./img/other/exit.xpm"

//Sprite Coin
# define PATH_COLL 		"./img/coin/coin_0.xpm"
# define PATH_COLL1 	"./img/coin/coin_1.xpm"
# define PATH_COLL2 	"./img/coin/coin_2.xpm"
# define PATH_COLL3 	"./img/coin/coin_3.xpm"
# define PATH_COLL4 	"./img/coin/coin_4.xpm"
# define PATH_COLL5 	"./img/coin/coin_5.xpm"
# define PATH_COLL6 	"./img/coin/coin_6.xpm"
# define PATH_COLL7 	"./img/coin/coin_7.xpm"

//Sprites Player
# define PATH_PPL_DOWN	"./img/player/tux_down.xpm"
# define PATH_PPL_RIGHT	"./img/player/tux_right.xpm"
# define PATH_PPL_LEFT	"./img/player/tux_left.xpm"
# define PATH_PPL_UP	"./img/player/tux_up.xpm"

//Sprites Monster
# define PATH_ENEM		"./img/monster/fly.xpm"
# define PATH_ENEM1 	"./img/monster/fly_1.xpm"
# define PATH_ENEM2		"./img/monster/fly_5.xpm"

//Bottons
# define KEY_ESC		0xff1b
# define KEY_LEFT		0xff51
# define KEY_UP			0xff52  
# define KEY_RIGHT		0xff53
# define KEY_DOWN		0xff54
# define KEY_A			0x0061
# define KEY_S			0x0073
# define KEY_D			0x0064
# define KEY_W			0x0077

//animation
# define SPEED_ANIMATION 		2000
# define SPEED_ANIMATION_ENEMY 	9000
# define UP_ENEMY				1
# define DOWN_ENEMY				0

typedef struct s_image
{
	void		*img_ptr;
	int			x;
	int			y;
	int			width;
	int			height;
}	t_image;

typedef struct s_window
{
	void		*win_ptr;
	int			width;
	int			height;
}	t_window;

typedef struct s_game
{
	char		**map;
	int			frame;
	int			moves;
	void		*mlx_ptr;
	int			val_exit;
	char		**tmp_map;
	int			count_exit;
	int			init_ppl_x;
	int			init_ppl_y;
	int			frame_enemy;
	int			count_player;
	int			val_collectible;
	int			time_animation;
	int			time_move_enemy;
	int			count_collectible;
	int			count_enemy;
	t_image		wall;
	t_image		exit;
	t_image		enemy;
	t_image		floor;
	t_image		player;
	t_window	window;
	t_image		collectible;
}	t_game;

//tool_map
void	init_game(t_game *game);
int		render_map(t_game *game, int x, int y);
char	**generate_map(char	*path_file);

//tool_event
int		move_ppl(int key, t_game *game);
int		check_game(t_game *game, int x, int y, size_t line_size);
void	swap_player(t_game *game, t_image *ppl, int move, char coord);

//tool_sprite
void	load_sprite(t_game *game);
void	load_mov(t_game *game, t_image *image, char *path);
void	load_image(t_game *game, t_image *image, char *path);
void	draw_image(t_game *game, t_image *image, int x, int y);

//tool_destroy
int		die(t_game *game, char *errmsg, int errnum);
void	free_map(char **tab);
int		exit_game(t_game *game);

//tool_check
int		utilities(t_game *game);
int		wall(char side_a, char side_b, char side_c);
void	flood_fill(t_game *game, char **map, int x, int y);
int		character(t_game *game, char character, int x, int y);

//animation
int		init_animation(t_game *game);
void	move_enemy(t_game *game);
void	animation(t_game *game);
#endif