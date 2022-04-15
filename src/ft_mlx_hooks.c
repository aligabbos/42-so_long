/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:54:35 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/13 19:02:51 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static int	move(int keycode, t_game *g);

int	ft_mlx_key_hook(int keycode, t_game *g)
{
	if (keycode != KEY_ESC)
		move(keycode, g);
	return (0);
}

int	ft_mlx_close(t_game *g)
{
	ft_free_map(g->map);
	ft_mlx_close_images(g->vars->mlx, g->c);
	mlx_destroy_window(g->vars->mlx, g->vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	move(int keycode, t_game *g)
{
	char	mt;

	ft_find_pos_player(g->map, &g->c->player);
	mt = ft_moving_to(keycode, g->map, &g->c->player);
	if (mt == EMPTY_SPACE || mt == COLLECTIBLE
		|| (mt == EXIT_MAP && !ft_count_collectible(g->map)))
	{
		g->moves += 1;
		ft_printf("%u\n", g->moves);
	}
	if (mt == EMPTY_SPACE || mt == COLLECTIBLE)
	{
		ft_update_map(keycode, g->map, &g->c->player);
		ft_render_map(g->map, g->vars, g->c);
	}
	else if (mt == EXIT_MAP && !ft_count_collectible(g->map))
		exit(0);
	return (0);
}
