/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:41:51 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/16 14:56:11 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	load_img(t_game **game, t_image *test, char *t)
// {
// 	test->img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
// 		t, &test->width, &test->height);
// 	(*game)->floor.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
// 		PATH_FLOOR, &(*game)->floor.width, &(*game)->floor.height);
// 	(*game)->wall.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
// 		PATH_WALL, &(*game)->wall.width, &(*game)->wall.height);
// 	(*game)->exit.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
// 		PATH_EXIT, &(*game)->exit.width, &(*game)->exit.height);
// 	(*game)->player.img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr,
// 		PATH_PLAYER, &(*game)->player.width, &(*game)->player.height);
// }

int andar(int nome)
{
	printf("%d\n", nome);
	return (0);
}

void	init_game(t_game *game)
{
	int x;
	int y;
	game->mlx_ptr = mlx_init();
	game->window.win_ptr = mlx_new_window (
		game->mlx_ptr,game->window.width, game->window.height, "so_long");
	load_sprite(&game);
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1') {
				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->wall.img_ptr, (SPRITE * y),(SPRITE * x));
			}
			if (game->map[x][y] == '0') {
				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->floor.img_ptr, (SPRITE * y), (SPRITE * x));
			}
			if (game->map[x][y] == 'P') {
				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->player.img_ptr, (SPRITE * y), (SPRITE * x));
			}
			if (game->map[x][y] == 'E') {
				mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr, game->exit.img_ptr, (SPRITE * y), (SPRITE * x));
			}
			y++;
		}
		x++;
	}
	mlx_hook(game->window.win_ptr, 2, 1, andar, NULL);
	mlx_loop(game->mlx_ptr);
}