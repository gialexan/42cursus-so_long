/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:18:40 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/14 00:47:35 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	val_map(int argc, char **argv)
{
	int len;
	
	if (argc != 2)
	{
		ft_printf("Número de argumentos inválidos!\n");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if ((len < 5) || (argv[1] == 0))
	{
		ft_printf("Mapa invalido! (<NomeMapa>.ber)\n");
		exit(1);
	}
	if ((ft_strcmp(".ber", (argv[1] + len - 4)) != 0))
	{
		ft_printf("Mapa invalido! (<NomeMapa>.ber)\n");
		exit(1);
	}
}
