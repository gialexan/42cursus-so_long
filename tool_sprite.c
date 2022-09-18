/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:16:03 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/18 05:01:37 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_game **game, t_image *image, int x, int y)
{
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->window.win_ptr, 
		(*game)->image.img_ptr, (SPRITE * y),(SPRITE * x));
}

static void	load_image(t_game **game, t_image *image, char *path)
{
	image->img_ptr = mlx_xpm_file_to_image((**game).mlx_ptr,
		path, &image->width, &image->height);
}

void	load_sprite(t_game **game)
{
	load_image(&*game, &(*game)->wall, PATH_WALL);
	load_image(&*game, &(*game)->exit, PATH_EXIT);
	load_image(&*game, &(*game)->floor, PATH_FLOOR);
	load_image(&*game, &(*game)->player, PATH_PLAYER);
	load_image(&*game, &(*game)->collectible, PATH_COLL);
}