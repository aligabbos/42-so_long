/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:48:57 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/13 17:22:24 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	ft_render_character_map(t_map *map, char type,
				t_vars *vars, t_data *img);

void	ft_render_map(t_map *map, t_vars *vars, t_characters *c)
{
	ft_render_character_map(map, EMPTY_SPACE,
		vars, &c->empty_space);
	ft_render_character_map(map, WALL,
		vars, &c->wall);
	ft_render_character_map(map, PLAYER,
		vars, &c->player);
	ft_render_character_map(map, COLLECTIBLE,
		vars, &c->collectible);
	ft_render_character_map(map, EXIT_MAP,
		vars, &c->exit_map);
}

static void	ft_render_character_map(t_map *map, char type,
			t_vars *vars, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->map[i][j] == type)
				mlx_put_image_to_window(vars->mlx,
					vars->win,
					img->img,
					img->img_width * j,
					img->img_height * i);
		}
	}
}
