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
