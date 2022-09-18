/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:41:51 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/18 08:09:26 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->window.win_ptr = mlx_new_window (
		game->mlx_ptr,game->window.width, game->window.height, "so_long");
	load_sprite(&game);
	mlx_hook(game->window.win_ptr, 2, 1L << 0, &move, &game);
	//mlx_hook(game->window.win_ptr, 2, 1, andar, NULL);
	//mlx_expose_hook(game->window.win_ptr, &render_map, &game);
	mlx_loop(game->mlx_ptr);
}
