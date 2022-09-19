/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:39:20 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/19 01:34:50 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	die(char *errmsg, int errnum)
{
	ft_putstr_fd(errmsg, errnum);
	exit(1);
}

static int	num(int n)
{
	return(n > 10);
}
int main(int argc, char **argv)
{
	char	*str;
	t_game	game;
	int x;

	/* válida entradas ok*/
	if (argc != 2)
		die("Número de argumentos inválidos!\n", 0);
	if (ft_strlen(argv[1]) < 5)
		die("Mapa invalido! (<NomeMapa>.ber)\n", 0);
	str = ft_strrchr(argv[1], '.');
	if (ft_strncmp(str, ".ber", 5))
		die("Mapa invalido! (<NomeMapa>.ber)\n", 0);
	x = num(9);
	

	/* gera mapa ok */
	game.map = generate_map(argv[1]);
	if (!game.map)
		die("Erro, arquivo de mapa inválido!\n", 0);
	// /* checar mapa ok */
	if(check_game(&game, -1, -1, ft_strlen(game.map[0])))
	{
		free_tab(game.map);
		exit (1);
	}
	/* iniciar jogo */
	init_game(&game);
}