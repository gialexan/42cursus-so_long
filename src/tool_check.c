/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:31:29 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/21 18:08:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall(char side_a, char side_b, char side_c)
{
	return ((side_a != '1')
		|| (side_b != '1')
		|| (side_c != '1'));
}

int	utilities(t_game *game)
{
	return ((game->val_exit < 1)
		|| (game->count_exit < 1)
		|| (game->count_player != 1)
		|| (game->count_collectible < 1)
		|| (game->count_collectible != game->val_collectible));
}

int	character(t_game *game, char character, int x, int y)
{
	if (character == 'P')
	{
		game->init_ppl_x = x;
		game->init_ppl_y = y;
		game->count_player++;
	}
	else if (character == 'C')
		game->count_collectible++;
	else if (character == 'E')
		game->count_exit++;
	else if ((character != '0') && (character != '1'))
		return (1);
	return (0);
}

void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (map[x][y] == '0' || map[x][y] == 'P' || map[x][y] == 'E'
		|| map[x][y] == 'C')
	{
		if (map[x][y] == 'C')
			game->val_collectible++;
		if (map[x][y] == 'E')
			game->val_exit++;
		map[x][y] = '5';
		flood_fill(game, map, x, y + 1);
		flood_fill(game, map, x, y - 1);
		flood_fill(game, map, x + 1, y);
		flood_fill(game, map, x - 1, y);
	}
	return ;
}
