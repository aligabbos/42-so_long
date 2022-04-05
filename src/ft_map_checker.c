/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:19:54 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/05 00:15:31 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

unsigned int	ft_check_cols_map(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (++i < map->rows)
	{
		if (ft_strlen(map->map[i]) != map->cols)
			return (0);
	}
	return (1);
}

unsigned int	ft_check_size_map(t_map *map)
{
	if (map->rows < MIN_R || map->cols < MIN_C)
		return (0);
	if (map->rows == MIN_R && map->cols < MIN)
		return (0);
	if (map->cols == MIN_C && map->rows < MIN)
		return (0);
	return (1);
}

unsigned int	ft_check_perimeter_map(t_map *map)
{
	unsigned int	i;
	unsigned int	rows;
	unsigned int	cols;

	i = -1;
	rows = map->rows;
	cols = map->cols;
	while (++i < rows)
	{
		if (map->map[i][0] != WALL || map->map[i][cols - 1] != WALL)
			return (0);
	}
	i = -1;
	while (++i < cols)
	{
		if (map->map[0][i] != WALL || map->map[rows - 1][i] != WALL)
			return (0);
	}
	return (1);
}

unsigned int	ft_check_element_map(t_map *map, char element, int min, int max)
{
	unsigned int	i;
	unsigned int	j;
	int				l;

	i = -1;
	l = 0;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == element)
				l++;
		}
	}
	if (max < 0)
		return (l >= min);
	return (l >= min && l <= max);
}
