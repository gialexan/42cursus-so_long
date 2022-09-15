/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:09:16 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/14 16:54:18 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	windows_size(char	**map)
{
	t_window	window;
	int			line;
	int			column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			
			column++;
		}
		line++;
	}
	window.height = column * SPRITE;
	window.width = line * SPRITE;
	return (window);
}
