/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:31:29 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/17 16:08:53 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall(char sideA, char sideB, char sideC)
{
	return ((sideA != '1')
		|| (sideB != '1')
		|| (sideC != '1'));
}

static int	utilities(t_game **game)
{
	return (((*game)->count_exit < 1)
		|| ((*game)->count_player != 1)
		|| ((*game)->count_collectible < 1));
}

static void	control(t_game **game)
{
	(*game)->count_player = 0;
	(*game)->count_exit = 0;
	(*game)->count_collectible = 0;
}

static int	character(t_game **game, char character)
{
	if (character == 'P')
		(*game)->count_player += 1;
	else if (character == 'C')
		(*game)->count_collectible += 1;
	else if (character == 'E')
		(*game)->count_exit += 1;
	else if ((character != '0') && (character != '1'))
		return (FALSE);
	return (TRUE);
}

int	check_game(t_game *game, int x, int y, int line_size)
{
	int	xmax;
	int	ymax;

	ymax = 0;
	xmax = 0;
	control(&game);
	while (game->map[++x])
	{
		if (game->map[x + 1] == NULL)
			xmax = x;
		y = -1;
		while (game->map[x][++y])
		{
			if ((wall(game->map[x][0], game->map[x][ymax], game->map[xmax][y]))
				|| (character(&game, game->map[x][y]))
				|| (line_size != ft_strlen(game->map[x])))
				return (FALSE);
		}
		ymax = y - 1;
	}
	if (utilities(&game))
		return (FALSE);
	game->window.height = x * SPRITE;
	game->window.width = y * SPRITE;
	return (TRUE);
}
