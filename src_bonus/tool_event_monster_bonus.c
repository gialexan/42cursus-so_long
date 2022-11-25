/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_event_monster_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:45:23 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/24 23:54:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	swap_enemy(t_game *game, int x, int y, int direction)
{
	if (direction == DOWN_ENEMY)
	{
		if (game->map[x][y] == 'A' && game->map[x + 1][y] == '0')
		{
			game->map[x + 1][y] = 'A';
			game->map[x][y] = '0';
		}
		else if (game->map[x][y] == 'A' && game->map[x + 1][y] == 'P')
			exit_game(game);
	}
	else if (direction == UP_ENEMY)
	{
		if (game->map[x][y] == 'A' && game->map[x - 1][y] == '0')
		{
			game->map[x - 1][y] = 'A';
			game->map[x][y] = '0';
		}
		else if (game->map[x][y] == 'A' && game->map[x - 1][y] == 'P')
			exit_game(game);
	}
}

static	void	search_enemy(t_game *game, int direction)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'A')
				swap_enemy(game, x, y, direction);
			y++;
		}
		x++;
	}
}

static	void	choose_move(t_game *game)
{
	if (game->frame_enemy == 1)
		search_enemy(game, UP_ENEMY);
	else if (game->frame_enemy == 2)
		search_enemy(game, UP_ENEMY);
	else if (game->frame_enemy == 3)
		search_enemy(game, UP_ENEMY);
	else if (game->frame_enemy == 4)
		search_enemy(game, DOWN_ENEMY);
	else if (game->frame_enemy == 5)
		search_enemy(game, DOWN_ENEMY);
}

static	void	update_frame_enemy(t_game *game)
{
	if (game->frame_enemy < 6)
		game->frame_enemy++;
	else
		game->frame_enemy = 1;
}

void	move_enemy(t_game *game)
{
	if (game->time_move_enemy++ < SPEED_ANIMATION_ENEMY)
		return ;
	game->time_move_enemy = 0;
	update_frame_enemy(game);
	choose_move(game);
}
