/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:20:32 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/25 00:06:39 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**generate_map(char *path_file)
{
	int		fd;
	char	*tmp;
	char	*line;
	char	**map;
	char	*map_tmp;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_tmp = ft_strdup("");
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		tmp = map_tmp;
		map_tmp = ft_strjoin(tmp, line);
		ft_free((void *)&line);
		ft_free((void *)&tmp);
	}
	map = ft_split(map_tmp, '\n');
	ft_free((void *)&map_tmp);
	close (fd);
	return (map);
}

int	render_map(t_game *game, int x, int y)
{
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				draw_image(game, &game->wall, x, y);
			else if (game->map[x][y] == '0')
				draw_image(game, &game->floor, x, y);
			else if (game->map[x][y] == 'C')
				draw_image(game, &game->collectible, x, y);
			else if (game->map[x][y] == 'P')
				draw_image(game, &game->player, x, y);
			else if (game->map[x][y] == 'E')
				draw_image(game, &game->exit, x, y);
			else if (game->map[x][y] == 'A')
				draw_image(game, &game->enemy, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

void	swap_player(t_game *game, t_image *ppl, int move, char coord)
{
	int	old_position_x;
	int	old_position_y;

	old_position_x = ppl->x;
	old_position_y = ppl->y;
	if (coord == 'x')
	{
		if (move < 0)
			ppl->x -= 1;
		else if (move > 0)
			ppl->x += 1;
	}
	else if (coord == 'y')
	{
		if (move < 0)
			ppl->y -= 1;
		else if (move > 0)
			ppl->y += 1;
	}
	game->map[ppl->x][ppl->y] = 'P';
	game->map[old_position_x][old_position_y] = '0';
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
