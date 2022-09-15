/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:40:22 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/15 16:04:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define SPRITE 50
# define FALSE 1
# define TRUE 0

// typedef struct s_game
// {
// 	int		
// }	t_game;

typedef struct s_imagem
{
	void	*img_ptr;
	int		x;
	int		y;
}	t_imagem;

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
	int			count_player;
	int			count_collectible;
	int			count_exit;
	
	t_window	window;

}	t_game;

//mapa
char	**generate_map(char	*path_file);
void	check_input(int argc, char **argv);
int		check_game(t_game *game, int x, int y, int size_line);

//win
//t_window	windows_size(char	**map);

#endif