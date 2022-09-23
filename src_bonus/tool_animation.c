/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:18:42 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/23 20:41:01 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	animation_coin(t_game *game)
{
	if (game->frame == 1)
		load_mov(game, &game->collectible, PATH_COLL1);
	else if (game->frame == 2)
		load_mov(game, &game->collectible, PATH_COLL2);
	else if (game->frame == 3)
		load_mov(game, &game->collectible, PATH_COLL3);
	else if (game->frame == 4)
		load_mov(game, &game->collectible, PATH_COLL4);
	else if (game->frame == 5)
		load_mov(game, &game->collectible, PATH_COLL5);
	else if (game->frame == 6)
		load_mov(game, &game->collectible, PATH_COLL6);
	else if (game->frame == 7)
		load_mov(game, &game->collectible, PATH_COLL7);
	else if (game->frame == 8)
		load_mov(game, &game->collectible, PATH_COLL);

}

static	void	animation_monster(t_game *game)
{
	if (game->frame == 1)
		load_mov(game, &game->enemy, PATH_ENEM1);
	else if (game->frame == 2)
		load_mov(game, &game->enemy, PATH_ENEM);
	else if (game->frame == 3)
		load_mov(game, &game->enemy, PATH_ENEM1);
	else if (game->frame == 4)
		load_mov(game, &game->enemy, PATH_ENEM);
	else if (game->frame == 5)
		load_mov(game, &game->enemy, PATH_ENEM1);
	else if (game->frame == 6)
		load_mov(game, &game->enemy, PATH_ENEM);
	else if (game->frame == 7)
		load_mov(game, &game->enemy, PATH_ENEM1);
	else if (game->frame == 8)
		load_mov(game, &game->enemy, PATH_ENEM1);
}

static	void	update_frame(t_game *game)
{
	if (game->frame < 9)
		game->frame++;
	else
		game->frame = 1;
}

void	animation(t_game *game)
{
	if (game->time_animation++ < SPEED_ANIMATION)
		return ;
	game->time_animation = 0;
	update_frame(game);
	animation_coin(game);
	animation_monster(game);
	render_map(game);
}
