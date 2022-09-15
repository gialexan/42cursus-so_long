/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:20:32 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/14 17:06:22 by gialexan         ###   ########.fr       */
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
		ft_free_ptr((void *)&tmp);
	}
	map = ft_split(aux, '\n');
	ft_free_ptr((void *)&aux);
	return (map);
}
