/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:20:19 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/16 16:55:36 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	ft_check_map(int err, t_map *map);

void	ft_set_map(t_map **map, char *map_file)
{
	t_map	*m;
	int		err;

	m = *map;
	ft_init_map(m, map_file);
	if (ft_set_rc_map(m))
		ft_create_map(m);
	else
		ft_perror_exit(ERR_MSG_FILE, ERR_FILE);
	err = ft_set_error(m);
	ft_check_map(err, m);
}

static void	ft_check_map(int err, t_map *map)
{
	if (!err)
		return ;
	ft_free_map(map);
	if (err == ERR_EXT)
		ft_perror_exit(ERR_MSG_EXT, err);
	if (err == ERR_COLS)
		ft_perror_exit(ERR_MSG_COLS, err);
	if (err == ERR_SIZE)
		ft_perror_exit(ERR_MSG_SIZE, err);
	if (err == ERR_PERIMETER)
		ft_perror_exit(ERR_MSG_PERIMETER, err);
	if (err == ERR_ELEMENT_TYPE)
		ft_perror_exit(ERR_MSG_ELEMENT_TYPE, err);
	if (err == ERR_ELEMENT_NUM)
		ft_perror_exit(ERR_MSG_ELEMENT_NUM, err);
}
