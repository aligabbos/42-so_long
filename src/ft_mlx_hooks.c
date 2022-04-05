/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:54:35 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/05 13:12:53 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_mlx_key_hook(int keycode, t_game *game)
{
	if (keycode != KEY_ESC)
	{;}
		// move(keycode, game);
	else
		mlx_loop_end(game->vars->mlx);
	return (0);
}

// int	move(int keycode, t_game *t)
// {
// 	if (keycode == KEY_W ||
// 		keycode == KEY_A ||
// 		keycode == KEY_S ||
// 		keycode == KEY_D)
// 		{;}
	// t->x += 100;
	// t->img->addr = mlx_get_data_addr(t->img->img, &t->img->bits_per_pixel, &t->img->line_length,
	// 							&t->img->endian);
	// mlx_put_image_to_window(t->vars->mlx, t->vars->win, t->img->img, t->x, t->y);
// 	return (0);
// }
