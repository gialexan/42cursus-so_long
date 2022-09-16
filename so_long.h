/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:40:22 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/16 15:04:35 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define SPRITE 32
# define FALSE 1
# define TRUE 0
# define PATH_FLOOR "img/black.xpm"
# define PATH_WALL "img/wall.xpm"
# define PATH_PLAYER "img/pac_closed.xpm"
# define PATH_EXIT "img/portal.xpm"

typedef struct s_image
{
	void	*img_ptr;
	int		width; // largura
	int		height; // altura
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
	int			count_player; // jogador
	int			count_collectible; // coletáveis
	int			count_exit; // saída
	t_image		floor; // sea
	t_image		wall; // parede
	t_image		exit; //world
	t_image		player; // shark
	t_window	window; // janela
}	t_game;

//mapa
char	**generate_map(char	*path_file);
int		check_game(t_game *game, int x, int y, int line_size);

//jogo
void	init_game(t_game *game);
void	load_sprite(t_game **game);

#endif