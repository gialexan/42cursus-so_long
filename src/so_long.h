/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:19:16 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/19 19:19:28 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
//# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

# define SPRITE		32
# define PATH_FLOOR 	"../img/space.xpm"
# define PATH_WALL 		"../img/wall.xpm"
# define PATH_EXIT 		"../img/exit.xpm"
# define PATH_COLL 		"../img/coin_0.xpm"
# define PATH_PPL_DOWN	"../img/tux_down.xpm"
# define PATH_PPL_RIGHT	"../img/tux_right.xpm"
# define PATH_PPL_LEFT	"../img/tux_left.xpm"
# define PATH_PPL_UP	"../img/tux_up.xpm"

# define KEY_ESC		0xff1b
# define KEY_LEFT		0xff51
# define KEY_UP			0xff52  
# define KEY_RIGHT		0xff53
# define KEY_DOWN		0xff54
# define KEY_A			0x0061
# define KEY_S			0x0073
# define KEY_D			0x0064
# define KEY_W			0x0077

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
	void		*mlx_ptr;
	char		**map;
	int			moves;
	int			count_player;
	int			count_collectible;
	int			count_exit;
	t_image		floor;
	t_image		wall;
	t_image		exit;
	t_image		player;
	t_image		collectible;
	t_window	window;
}	t_game;

char	**generate_map(char	*path_file);
int		render_map(t_game **game);
void	swap_player(t_game **game, t_image **ppl, int move, char coord);
void	init_game(t_game *game);
int		move(int key, t_game **game);
int		check_game(t_game *game, int x, int y, size_t line_size);
void	load_sprite(t_game **game);
void	draw_image(t_game **game, t_image *image, int x, int y);
void	load_mov_player(t_game **game, char *path);
int		exit_game(t_game **game);
void	free_map(char **tab);
int		die(char *errmsg);
#endif