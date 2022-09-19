/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:58:51 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/18 22:31:46 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game **game)
{
	free_tab((*game)->map);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->wall.img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->exit.img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->floor.img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->player.img_ptr);
	mlx_destroy_image((*game)->mlx_ptr, (*game)->collectible.img_ptr);
	mlx_destroy_window((*game)->mlx_ptr, (*game)->window.win_ptr);
	mlx_destroy_display((*game)->mlx_ptr);
	free((*game)->mlx_ptr);
	return (0);
}