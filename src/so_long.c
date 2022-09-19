/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:39:20 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/19 17:08:22 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	char	*str;
	t_game	game;

	if (argc != 2)
		return (die("Number of invalid argument!"));
	if (ft_strlen(argv[1]) < 5)
		return (die("Invalid map file! (<NameMap>.ber)"));
	str = ft_strrchr(argv[1], '.');
	if (ft_strncmp(str, ".ber", 5))
		return (die("Invalid map file! (<NameMap>.ber)"));
	game.map = generate_map(argv[1]);
	if (!game.map)
		return (die("Error, map invalid!"));
	if (check_game(&game, -1, -1, ft_strlen(game.map[0])))
	{
		free_map(game.map);
		return (die("Error, invalid map components!"));
	}
	init_game(&game);
}
