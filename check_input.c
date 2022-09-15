/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:18:40 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/15 12:47:02 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	die(char *errmsg, int errnum)
{
	ft_putstr_fd(errmsg, errnum);
	exit(1);
}

void	check_input(int argc, char **argv)
{
	int	len_argv;

	if (argc != 2)
		die("Número de argumentos inválidos!\n", 0);
	len_argv = ft_strlen(argv[1]);
	if ((len_argv < 5) || (argv[1] == 0))
		die("Mapa invalido! (<NomeMapa>.ber)\n", 0);
	if ((ft_strcmp(".ber", (argv[1] + len_argv - 4)) != 0))
		die("Mapa invalido! (<NomeMapa>.ber)\n", 0);
}
