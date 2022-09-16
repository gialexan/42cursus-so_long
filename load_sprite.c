/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:16:03 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/16 15:20:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}