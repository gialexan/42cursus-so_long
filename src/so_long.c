/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:39:20 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/21 15:37:01 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->window.win_ptr = mlx_new_window (
			game->mlx_ptr, game->window.width, game->window.height, "so_long");
	load_sprite(&game);
	mlx_hook(game->window.win_ptr, 2, 1L << 0, &move, &game);
	mlx_hook(game->window.win_ptr, 17, 0, &exit_game, &game);
	mlx_expose_hook(game->window.win_ptr, &render_map, &game);
	mlx_loop(game->mlx_ptr);
}

int	check_game(t_game *game, int x, int y, size_t line_size)
{
	int	xmax;
	int	ymax;

	ymax = 0;
	xmax = 0;
	while (game->map[++x])
	{
		if (game->map[x + 1] == NULL)
			xmax = x;
		y = -1;
		while (game->map[x][++y])
		{
			if (wall(game->map[x][0], game->map[x][ymax], game->map[xmax][y])
				|| character(game, game->map[x][y], x, y)
				|| line_size != ft_strlen(game->map[x]))
				return (1);
		}
		ymax = y - 1;
	}
	flood_fill(game, game->tmp_map, game->init_ppl_x, game->init_ppl_y);
	if (utilities(game))
		return (1);
	game->window.height = x * SPRITE;
	game->window.width = y * SPRITE;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str;

	if (argc != 2)
		return (die("Number of invalid argument!"));
	if (ft_strlen(argv[1]) < 5)
		return (die("Invalid map file! (<NameMap>.ber)"));
	str = ft_strrchr(argv[1], '.');
	if (ft_strncmp(str, ".ber", 5))
		return (die("Invalid map file! (<NameMap>.ber)"));
	ft_bzero(&game, sizeof(t_game));
	game.map = generate_map(argv[1]);
	if (!game.map)
		return (die("Error, map invalid!"));
	game.tmp_map = ft_array_dup(game.map);
	if (check_game(&game, -1, -1, ft_strlen(game.map[0])))
	{
		free_map(game.tmp_map);
		free_map(game.map);
		return (die("Error, invalid map components!"));
	}
	ft_free((void *)tmp);
	init_game(&game);
}
