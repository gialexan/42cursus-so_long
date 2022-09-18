/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:20:32 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/18 05:00:04 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**generate_map(char *path_file)
{
	int		fd;
	char	*aux;
	char	*tmp;
	char	**map;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	aux = ft_strdup("");
	while (1)
	{
		tmp = ft_get_next_line(fd);
		if (!tmp)
			break ;
		aux = ft_strjoin(aux, tmp);
		ft_free((void *)&tmp);
	}
	map = ft_split(aux, '\n');
	ft_free((void *)&aux);
	close (fd);
	return (map);
}

void	render_map(t_game **game, int x, int y)
{
	while (game->map[++x])
	{
		y = 0;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == '1')
				draw_image(&*game, &(*game)->wall, x, y);
			else if (game->map[x][y] == '0')
				draw_image(&*game, &(*game)->floor, x, y);
			else if (game->map[x][y] == 'C')
				draw_image(&*game, &(*game)->collectible, x, y);
			else if (game->map[x][y] == 'P')
				draw_image(&*game, &(*game)->player, x, y);
			else if (game->map[x][y] == 'E')
				draw_image(&*game, &(*game)->exit, x, y);
		}
	}
}