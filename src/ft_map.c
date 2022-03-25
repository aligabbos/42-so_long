/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:59:07 by gsemerar          #+#    #+#             */
/*   Updated: 2022/03/24 13:18:10 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_map(t_map *map, char *file_name)
{
	map->file = file_name;
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
}

unsigned int	ft_set_rc_map(t_map *map)
{
	char	*row;

	if (ft_open_map(map))
	{
		row = ft_ignore_nl(map->fd);
		map->cols = ft_strlen(row);
		while (row)
		{
			if (ft_strlen(row) > 0)
				map->rows += 1;
			free(row);
			row = get_next_line(map->fd);
			ft_remove_nl(&row);
			if (ft_strlen(row) == 0)
			{
				free(row);
				ft_close_map(map);
				return (1);
			}
		}
		free(row);
	}
	return (0);
}

unsigned int	ft_create_map(t_map *map)
{
	char			*row;
	unsigned int	i;

	map->map = malloc(sizeof(char *) * (map->rows));
	if (!map->map)
		return (0);
	if (ft_open_map(map))
	{
		row = ft_ignore_nl(map->fd);
		i = -1;
		while (++i < map->rows)
		{
			map->map[i] = row;
			row = get_next_line(map->fd);
			ft_remove_nl(&row);
		}
		free(row);
		ft_close_map(map);
		return (1);
	}
	return (0);
}

unsigned int	ft_open_map(t_map *map)
{
	map->fd = open(map->file, O_RDONLY);
	if (map->fd != -1)
		return (1);
	return (0);
}

unsigned int	ft_close_map(t_map *map)
{
	char	*row;

	if (map->fd != -1)
	{
		row = get_next_line(map->fd);
		while (row)
		{
			free(row);
			row = get_next_line(map->fd);
		}
		if (!close(map->fd))
			return (1);
	}
	return (0);
}
