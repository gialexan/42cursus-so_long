/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_destroy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:58:51 by gialexan          #+#    #+#             */
/*   Updated: 2022/10/01 00:30:38 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	die(t_game *game, char *errmsg, int errnum, char *ptr)
{
	ft_putendl_fd(errmsg, 0);
	if (errnum == 1)
		return (1);
	else if (errnum == 2)
	{
		free_map(game->map);
		exit (1);
	}
	else if (errnum == 3)
	{
		ft_free((void *)&ptr);
		exit (1);
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->enemy.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->collectible.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->window.win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
