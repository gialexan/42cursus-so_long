/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:40:22 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/13 21:59:35 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define SPRITE 50

typedef struct s_imagem
{
	void	*img_ptr;
	int		x;
	int		y;
}	t_imagem;

typedef struct s_window
{
	void	*win_ptr; // ponteiro janela
	int		width; //largura
	int		height; // altura
	
}	t_window;

typedef struct s_game
{
	void		*mlx_ptr; // ponteiro mlx init
	char		**map; // mapa
	
	t_window	window;
	t_imagem	floor;
	t_imagem	wall;
}	t_game;

//mapa
char	**gen_map(char	*path_file);
void	val_map(int argc, char **argv);

//win
t_window	win_size(char	**map);


#endif