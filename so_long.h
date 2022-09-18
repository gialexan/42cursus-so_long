/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:40:22 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/18 05:06:33 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//inc
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
//macro help
# define SPRITE		32
# define FALSE		1
# define TRUE		0
# define INCREMENT	1
# define DECREMENT -1
//img
# define PATH_FLOOR "img/black.xpm"
# define PATH_WALL "img/wall.xpm"
# define PATH_PLAYER "img/pac_closed.xpm"
# define PATH_EXIT "img/portal.xpm"
# define PATH_COLL "img/pacdot_food.xpm"
//key
# define KEY_W	0x77
# define KEY_S	0x73
# define KEY_D	0x64
# define KEY_A	0x61
# define KEY_UP		0xff52
# define KEY_ESC	0xff1b
# define KEY_LEFT	0xff51
# define KEY_DOWN	0xff54
# define KEY_RIGHT	0xff53

typedef struct s_image
{
	void		*img_ptr;
	int			x;
	int			y;
	int			width; // largura
	int			height; // altura
}	t_image;

typedef struct s_window
{
	void		*win_ptr; // ponteiro janela
	int			width; //largura
	int			height; // altura
}	t_window;

typedef struct s_game
{
	void		*mlx_ptr; // ponteiro mlx init
	char		**map; // mapa
	int			moves;
	int			count_player; // jogador
	int			count_collectible; // coletáveis
	int			count_exit; // saída
	t_image		floor; // sea
	t_image		wall; // parede
	t_image		exit; //world
	t_image		player; // shark
	t_image		collectible;
	t_window	window; // janela
}	t_game;

//mapa
char	**generate_map(char	*path_file);

//jogo e utilidades
void	init_game(t_game *game);
void	load_sprite(t_game **game);
int		check_game(t_game *game, int x, int y, int line_size);
#endif