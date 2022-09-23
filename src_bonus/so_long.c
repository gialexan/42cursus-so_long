/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:39:20 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/23 21:09:56 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_animation(t_game *game)
{
	animation(game);
	move_enemy(game);
	return (0);
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		die(game, "Error, unable to start system", 2);
	game->window.win_ptr = mlx_new_window (
			game->mlx_ptr, game->window.width, game->window.height, "so_long");
	if (game->window.win_ptr == NULL)
		die(game, "Error, unable to start screen", 2);
	load_sprite(game);
	game->frame = 0;
	mlx_hook(game->window.win_ptr, 2, 1L << 0, &move_ppl, game);
	mlx_hook(game->window.win_ptr, 17, 0, &exit_game, game);
	mlx_expose_hook(game->window.win_ptr, &render_map, game);
	mlx_loop_hook(game->mlx_ptr, &init_animation, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str;

	if (argc != 2)
		return (die(&game, "Number of invalid argument!", 1));
	if (ft_strlen(argv[1]) < 5)
		return (die(&game, "Invalid map file! (<NameMap>.ber)", 1));
	str = ft_strrchr(argv[1], '.');
	if (ft_strncmp(str, ".ber", 5))
		return (die(&game, "Invalid map file! (<NameMap>.ber)", 1));
	ft_bzero(&game, sizeof(t_game));
	game.map = generate_map(argv[1]);
	if (!game.map)
		return (die(&game, "Error, map invalid!", 1));
	game.tmp_map = ft_array_dup(game.map);
	if (check_game(&game, -1, -1, ft_strlen(game.map[0])))
	{
		free_map(game.tmp_map);
		free_map(game.map);
		return (die(&game, "Error, the game is not playable", 1));
	}
	free_map(game.tmp_map);
	init_game(&game);
}
