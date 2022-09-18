/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:11:30 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/18 05:07:24 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	up(t_game **game, t_player *ppl, int line)
{
	if ((*game)->map[ppl->x - line][ppl->y] == 'E'
		&& (*game)->count_collectible == 0)
		exit(0);
	else if ((*game)->map[ppl->x - line][ppl->y] != '1'
		&& (*game)->map[ppl->x - line][ppl->y] != 'E'
	{
		if ((*game)->map[ppl->x - line][ppl->y] == 'C')
			(*game)->count_collectible--;
		*game)->moves++;
	}
}

static	void	down(t_game **game, t_player *ppl, int line)
{
	if ((*game)->map[ppl->x + line][ppl->y] == 'E'
		&& (*game)->count_collectible == 0)
		exit(0);
	else if ((*game)->map[ppl->x + line][ppl->y] != '1'
		&& (*game)->map[ppl->x + line][ppl->y] != 'E'
	{
		if ((*game)->map[ppl->x + line][ppl->y] == 'C')
			(*game)->count_collectible--;
		*game)->moves++;
	}
}

static	void	left(t_game **game, t_player *ppl, int column)
{
	if ((*game)->map[ppl->x][ppl->y - column] == 'E'
		&& (*game)->count_collectible == 0)
		exit(0);
	else if ((*game)->map[ppl->x][ppl->y - column] != '1'
		&& (*game)->map[ppl->x][ppl->y] != 'E'
	{
		if ((*game)->map[ppl->x][ppl->y - column] == 'C')
			(*game)->count_collectible--;
		*game)->moves++;
	}
}

static	void	right(t_game **game, t_player *ppl, int line)
{
	if ((*game)->map[ppl->x][ppl->y + column] == 'E'
		&& (*game)->count_collectible == 0)
		exit(0);
	else if ((*game)->map[ppl->x][ppl->y + column] != '1'
		&& (*game)->map[ppl->x][ppl->y] != 'E'
	{
		if ((*game)->map[ppl->x][ppl->y + column] == 'C')
			(*game)->count_collectible--;
		*game)->moves++;
	}
}

int move(int key, t_game **game)
{
	if (key == KEY_W || KEY_UP)
		up(&*game, &(*game)->player, DECREMENT);
	else if (key == KEY_S || KEY_DOWN)
		down(&*game, &(*game)->player, INCREMENT);
	else if (key == KEY_A || KEY_LEFT)
		left(&*game, &(*game)->player, DECREMENT)
	else if (key == KEY_D || KEY_RIGHT)
		right(&*game, &(*game)->player, INCREMENT);
	render_map(&*game, -1, -1);
}