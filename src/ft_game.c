/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:20:19 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/15 16:13:39 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	ft_check_map(t_map *map);

void	ft_set_map(t_map **map, char *map_file)
{
	t_map	*m;

	m = *map;
	ft_init_map(m, map_file);
	if (ft_set_rc_map(m))
		ft_create_map(m);
	else
		ft_perror_exit(ERR_MSG_FILE, ERR_FILE);
	ft_check_map(m);
}

static void	ft_check_map(t_map *map)
{
	if (!ft_check_extension(map->file, EXT_BER))
		ft_perror_exit(ERR_MSG_EXT, ERR_EXT);
	if (!ft_check_cols_map(map))
		ft_perror_exit(ERR_MSG_COLS, ERR_COLS);
	if (!ft_check_size_map(map))
		ft_perror_exit(ERR_MSG_SIZE, ERR_SIZE);
	if (!ft_check_perimeter_map(map))
		ft_perror_exit(ERR_MSG_PERIMETER, ERR_PERIMETER);
	if (!ft_check_element_type_map(map))
		ft_perror_exit(ERR_MSG_ELEMENT_TYPE, ERR_ELEMENT_TYPE);
	if (!ft_check_n_of_element_map(map, PLAYER, 1, 1)
		|| !ft_check_n_of_element_map(map, COLLECTIBLE, 1, -1)
		|| !ft_check_n_of_element_map(map, EXIT_MAP, 1, -1))
		ft_perror_exit(ERR_MSG_ELEMENT_NUM, ERR_ELEMENT_NUM);
}
