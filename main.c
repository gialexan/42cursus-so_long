/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:39:20 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/15 16:33:43 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	int i;

	/* válida mapa */
	check_input(argc, argv);
	/* gera mapa */
	game.map = generate_map(argv[1]);
	if (!game.map)
		return (ft_printf("Arquivo de mapa inválido!\n"));
	/* checar mapa */
	check_game(&game, -1, -1, ft_strlen(game.map[0]));
	init_game(&game)
	exit(1);

	
	/* iniciar o jogo */
	// root.mlx_ptr = mlx_init(); // iniciando mlx
	// root.window.win_ptr = mlx_new_window(root.mlx_ptr,root.window.width ,root.window.height, "so_long"); // iniciando janela
	
	// root.floor.img_ptr = mlx_xpm_file_to_image(root.mlx_ptr, "img/floor.xpm", &root.floor.x , &root.floor.y); // salvando chão
	// root.wall.img_ptr = mlx_xpm_file_to_image(root.mlx_ptr, "img/wall.xpm", &root.wall.x , &root.wall.y); // salvando parede
	
	// x = 0;
	// while (root.map[x])
	// {
	// 	y = 0;
	// 	while (root.map[x][y])
	// 	{
	// 		if (root.map[x][y] == '1') {
	// 			mlx_put_image_to_window(root.mlx_ptr, root.window.win_ptr, root.wall.img_ptr, (50 * x),(50 * y));
	// 		}
	// 		if (root.map[x][y] == '0') {
	// 			mlx_put_image_to_window(root.mlx_ptr, root.window.win_ptr, root.floor.img_ptr, (50 * x), (50 * y));
	// 		}
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_loop(root.mlx_ptr);
}