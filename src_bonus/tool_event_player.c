/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_event_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:11:30 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/23 20:56:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	up(t_game *game, t_image *ppl)
{	
	if (game->map[ppl->x - 1][ppl->y] == 'A')
		exit_game(game);
	else if (game->map[ppl->x - 1][ppl->y] == 'E' &&
		game->count_collectible == 0 || game->map[ppl->x - 1][ppl->y] == 'A')
		exit_game(game);
	else if (game->map[ppl->x - 1][ppl->y] != '1' &&
		game->map[ppl->x - 1][ppl->y] != 'E')
	{
		if (game->map[ppl->x - 1][ppl->y] == 'C')
			game->count_collectible--;
		load_mov(game, ppl, PATH_PPL_UP);
		swap_player(game, ppl, -1, 'x');
		game->moves++;
	}
}

static	void	down(t_game *game, t_image *ppl)
{
	if (game->map[ppl->x + 1][ppl->y] == 'A')
		exit_game(game);
	else if (game->map[ppl->x + 1][ppl->y] == 'E' &&
		game->count_collectible == 0 || game->map[ppl->x - 1][ppl->y] == 'A')
		exit_game(game);
	else if (game->map[ppl->x + 1][ppl->y] != '1' &&
		game->map[ppl->x + 1][ppl->y] != 'E')
	{
		if (game->map[ppl->x + 1][ppl->y] == 'C')
			game->count_collectible--;
		load_mov(game, ppl, PATH_PPL_DOWN);
		swap_player(game, ppl, 1, 'x');
		game->moves++;
	}
}

static	void	left(t_game *game, t_image *ppl)
{
	if (game->map[ppl->x][ppl->y - 1] == 'A')
		exit_game(game);
	if (game->map[ppl->x][ppl->y - 1] == 'A')
		exit_game(game);
	else if (game->map[ppl->x][ppl->y - 1] == 'E' &&
			game->count_collectible == 0)
		exit_game(game);
	else if (game->map[ppl->x][ppl->y - 1] != '1' &&
		game->map[ppl->x][ppl->y - 1] != 'E')
	{
		if (game->map[ppl->x][ppl->y - 1] == 'C')
			game->count_collectible--;
		load_mov(game, ppl, PATH_PPL_LEFT);
		swap_player(game, ppl, -1, 'y');
		game->moves++;
	}
}

static	void	right(t_game *game, t_image *ppl)
{
	if (game->map[ppl->x][ppl->y + 1] == 'A')
		exit_game(game);
	else if (game->map[ppl->x][ppl->y + 1] == 'E' &&
		game->count_collectible == 0 || game->map[ppl->x - 1][ppl->y] == 'A')
		exit_game(game);
	else if (game->map[ppl->x][ppl->y + 1] != '1' &&
		game->map[ppl->x][ppl->y + 1] != 'E')
	{
		if (game->map[ppl->x][ppl->y + 1] == 'C')
			game->count_collectible--;
		load_mov(game, ppl, PATH_PPL_RIGHT);
		swap_player(game, ppl, 1, 'y');
		game->moves++;
	}
}

int	move_ppl(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_S || key == KEY_DOWN)
		down(game, &game->player);
	else if (key == KEY_W || key == KEY_UP)
		up(game, &game->player);
	else if (key == KEY_A || key == KEY_LEFT)
		left(game, &game->player);
	else if (key == KEY_D || key == KEY_RIGHT)
		right(game, &game->player);
	render_map(game);
	ft_putnbr_fd(game->moves, 0);
	ft_putchar_fd('\n', 0);
	return (0);
}
