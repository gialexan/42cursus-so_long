/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:39:20 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/14 00:51:44 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_game game;
	int x;
	int y;
	
	/* válida mapa */
	val_map(argc, argv);
	/* gera mapa */
	game.map = gen_map(argv[1]);
	if(!game.map)
		printf("Arquivo de mapa inválido!");
	/* checar mapa */
	//check_map
	//validar se existe player, se tem paredes nas bordas, coletáveis, saida 
	
	/* tamanho tela */
	game.window = win_size(game.map);

	/*  */

	
	
	
	// conferir o mapa
	// x = 0;
	// while(game.map[x])
	// {
	// 	y = 0;
	// 	while (game.map[x][y] != '\0')
	// 	{
	// 		printf("%c", game.map[x][y]);
	// 		y++;
	// 	}
	// 	x++;
	// 	printf("\n");
	// }
	
	/* iniciar o jogo */
	game.mlx_ptr = mlx_init(); // iniciando mlx
	game.window.win_ptr = mlx_new_window(game.mlx_ptr,game.window.width ,game.window.height, "so_long"); // iniciando janela
	
	game.floor.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "img/floor.xpm", &game.floor.x , &game.floor.y); // salvando chão
	game.wall.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "img/wall.xpm", &game.wall.x , &game.wall.y); // salvando parede
	
	x = 0;
	while (game.map[x])
	{
		y = 0;
		while (game.map[x][y])
		{
			if (game.map[x][y] == '1') {
				mlx_put_image_to_window(game.mlx_ptr, game.window.win_ptr, game.wall.img_ptr, (50 * x),(50 * y));
			}
			if (game.map[x][y] == '0') {
				mlx_put_image_to_window(game.mlx_ptr, game.window.win_ptr, game.floor.img_ptr, (50 * x), (50 * y));
			}
			y++;
		}
		x++;
	}
	mlx_loop(game.mlx_ptr);
}