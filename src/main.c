/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:52:02 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/05 13:29:37 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

typedef struct s_test {
	t_vars	*vars;
	t_data	*img;
	int x;
	int y;
}	t_test;


int	move(t_test *t)
{
	t->x += 64;
	// t->img->addr = mlx_get_data_addr(t->img->img, &t->img->bits_per_pixel, &t->img->line_length,
	// 							&t->img->endian);
	mlx_put_image_to_window(t->vars->mlx, t->vars->win, t->img->img, t->x, t->y);
	return (0);
}

int	cclose(int keycode, t_test *vars)
{
	if (keycode == KEY_W ||
		keycode == KEY_A ||
		keycode == KEY_S ||
		keycode == KEY_D)
		move(vars);
	else if (keycode == KEY_ESC)
		mlx_loop_end(vars->vars->mlx);
		// mlx_string_put(vars->mlx, vars->win, 200, 200, 0x00FF0000, "FIGA");
	return (0);
}

int	ccclose(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	resize(t_test *t)
{
	mlx_clear_window(t->vars->mlx, t->vars->win);
	t->img->addr = mlx_get_data_addr(t->img->img, &t->img->bits_per_pixel, &t->img->line_length,
								&t->img->endian);
	mlx_put_image_to_window(t->vars->mlx, t->vars->win, t->img->img, t->x, t->y);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_data	img2;
	t_test	t;
	t_map	map;
	t_characters c;

	ft_init_map(&map, av[1]);
	if (ft_set_rc_map(&map));
		ft_create_map(&map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map.cols * 64, map.rows * 64, "Hello world!");
	c = ft_mlx_load_images(vars.mlx);
	ft_render_map(&map, &vars, &c);
	// img = ft_mlx_load_img(vars.mlx, "./img/enemy.xpm");
	// img2 = ft_mlx_load_img(vars.mlx, "./img/Apple.xpm");
	// mlx_put_image_to_window(vars.mlx, vars.win, c.empty_space.img, 100, 200);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	// mlx_put_image_to_window(vars.mlx, vars.win, img2.img, 100, 200);
	t.vars = &vars;
	t.img = &c.player;
	t.x = 64;
	t.y = 3 * 64;
	mlx_key_hook(vars.win, cclose, &t);
	mlx_hook(vars.win, 17, 1L<<3, ccclose, &vars);
	// mlx_hook(vars.win, 25, 1L<<18, resize, &t);
	// mlx_loop_hook(vars.mlx, resize, &t);
	// mlx_loop_hook(vars.mlx, move, &t);
	// mlx_loop_hook(vars.mlx, move, &t2);
	mlx_loop(vars.mlx);
	// mlx_destroy_image(vars.mlx, img.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	// exit(0);
	return (0);
}

// int main(int ac, char **av)
// {
// 	if (ac)
// 		{;}
// 	t_map	map;
// 	ft_init_map(&map, av[1]);
// 	if (ft_set_rc_map(&map));
// 		ft_create_map(&map);
// 	// else error
// 	ft_printf("Ext %d\n", ft_check_extension(map.file, EXT_BER));
// 	ft_printf("Cols %d\n", ft_check_cols_map(&map));
// 	ft_printf("Size %d\n", ft_check_size_map(&map));
// 	ft_printf("Walls %d\n", ft_check_perimeter_map(&map));
// 	ft_printf("Coll %d\n", ft_check_element_map(&map, PLAYER, 1, 1));
// 	for (int i = 0; i < map.rows; i++)
// 		free(map.map[i]);
// 	free(map.map);
// }
