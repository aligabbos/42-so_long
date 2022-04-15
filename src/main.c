/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:52:02 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/14 17:22:06 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int ac, char **av)
{
	t_game			g;
	t_vars			vars;
	t_map			map;
	t_characters	c;

	if (ac == 2)
	{
		g.map = &map;
		g.vars = &vars;
		ft_set_map(&g.map, av[1]);
		g.vars->mlx = mlx_init();
		c = ft_mlx_load_images(g.vars->mlx);
		g.c = &c;
		g.vars->win = mlx_new_window(
				g.vars->mlx,
				g.map->cols * g.c->empty_space.img_width,
				g.map->rows * g.c->empty_space.img_height,
				GAME_TITLE);
		ft_render_map(g.map, g.vars, g.c);
		mlx_key_hook(g.vars->win, ft_mlx_key_hook, &g);
		mlx_hook(g.vars->win, 17, 1L << 3, ft_mlx_close, &g);
		mlx_loop(g.vars->mlx);
	}
	return (0);
}
