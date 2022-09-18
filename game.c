/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:41:51 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/17 23:43:50 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->window.win_ptr = mlx_new_window (
		game->mlx_ptr,game->window.width, game->window.height, "so_long");
	load_sprite(&game);
	//mlx_hook(game->window.win_ptr, 2, 1, &move, &game);
	//mlx_hook(game->window.win_ptr, 2, 1, andar, NULL);
	mlx_loop(game->mlx_ptr);
}






// while (game->map[x])
// 	{
// 		y = 0;
// 		while (game->map[x][y])
// 		{
// 			if (game->map[x][y] == '1') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->wall.img_ptr, (SPRITE * y),(SPRITE * x));
// 			}
// 			if (game->map[x][y] == '0') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->floor.img_ptr, (SPRITE * y), (SPRITE * x));
// 			}
// 			if (game->map[x][y] == 'P') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->player.img_ptr, (SPRITE * y), (SPRITE * x));
// 			}
// 			if (game->map[x][y] == 'E') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->exit.img_ptr, (SPRITE * y), (SPRITE * x));
// 			}
// 			if (game->map[x][y] == 'C'){
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->collectible.img_ptr, (SPRITE * y), (SPRITE * x));
// 			}
// 			y++;
// 		}
// 		x++;
// 	}














// while (game->map[x])
// 	{
// 		y = 0;
// 		while (game->map[x][y])
// 		{
// 			if (game->map[x][y] == '1') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->wall.img_ptr, (SPRITE * y),(SPRITE * x));
// 			}
// 			if (game->map[x][y] == '0') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->floor.img_ptr, (SPRITE * y), (SPRITE * x));
// 			}
// 			if (game->map[x][y] == 'P') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->player.img_ptr, (SPRITE * y), (SPRITE * x));
// 			}
// 			if (game->map[x][y] == 'E') {
// 				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->exit.img_ptr, (SPRITE * y), (SPRITE * x));
// 			}
// 			y++;
// 		}
// 		x++;
// 	}