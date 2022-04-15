/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:03:42 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/13 18:31:17 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

char	ft_moving_to(int keycode, t_map *map, t_data *player)
{
	if (keycode == KEY_W)
		return (map->map[player->img_pos_x - 1][player->img_pos_y]);
	else if (keycode == KEY_S)
		return (map->map[player->img_pos_x + 1][player->img_pos_y]);
	else if (keycode == KEY_A)
		return (map->map[player->img_pos_x][player->img_pos_y - 1]);
	else if (keycode == KEY_D)
		return (map->map[player->img_pos_x][player->img_pos_y + 1]);
	return (map->map[player->img_pos_x][player->img_pos_y]);
}

void	ft_find_pos_player(t_map *map, t_data *player)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == PLAYER)
			{
				player->img_pos_x = i;
				player->img_pos_y = j;
				return ;
			}
		}
	}
}

void	ft_update_map(int keycode, t_map *map, t_data *player)
{
	map->map[player->img_pos_x][player->img_pos_y] = EMPTY_SPACE;
	if (keycode == KEY_W)
		map->map[player->img_pos_x - 1][player->img_pos_y] = PLAYER;
	else if (keycode == KEY_S)
		map->map[player->img_pos_x + 1][player->img_pos_y] = PLAYER;
	else if (keycode == KEY_A)
		map->map[player->img_pos_x][player->img_pos_y - 1] = PLAYER;
	else if (keycode == KEY_D)
		map->map[player->img_pos_x][player->img_pos_y + 1] = PLAYER;
}

unsigned int	ft_count_collectible(t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	collectible;

	i = -1;
	collectible = 0;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == COLLECTIBLE)
				collectible += 1;
		}
	}
	return (collectible);
}

void	ft_free_map(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (++i < map->rows)
		free(map->map[i]);
	free(map->map);
}
