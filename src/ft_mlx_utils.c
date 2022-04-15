/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:08:53 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/13 18:47:33 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

t_data	ft_mlx_load_img(void *mlx, char *file)
{
	t_data	img;

	img.file = file;
	img.img = mlx_xpm_file_to_image(mlx,
			img.file,
			(int *) &img.img_width,
			(int *) &img.img_height);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian);
	return (img);
}

t_characters	ft_mlx_load_images(void *mlx)
{
	t_characters	c;

	c.player = ft_mlx_load_img(mlx, IMG_PLAYER);
	c.wall = ft_mlx_load_img(mlx, IMG_WALL);
	c.empty_space = ft_mlx_load_img(mlx, IMG_EMPTY_SPACE);
	c.collectible = ft_mlx_load_img(mlx, IMG_COLLECTIBLE);
	c.exit_map = ft_mlx_load_img(mlx, IMG_EXIT_MAP);
	return (c);
}

void	ft_mlx_close_images(void *mlx, t_characters *c)
{
	mlx_destroy_image(mlx, c->player.img);
	mlx_destroy_image(mlx, c->wall.img);
	mlx_destroy_image(mlx, c->empty_space.img);
	mlx_destroy_image(mlx, c->collectible.img);
	mlx_destroy_image(mlx, c->exit_map.img);
}
