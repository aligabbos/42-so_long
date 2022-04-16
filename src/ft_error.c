/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:15:40 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/16 16:53:05 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_perror_exit(char *err_msg, int err_code)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(err_code);
}

int	ft_set_error(t_map *map)
{
	if (!ft_check_extension(map->file, EXT_BER))
		return (ERR_EXT);
	if (!ft_check_cols_map(map))
		return (ERR_COLS);
	if (!ft_check_size_map(map))
		return (ERR_SIZE);
	if (!ft_check_perimeter_map(map))
		return (ERR_PERIMETER);
	if (!ft_check_element_type_map(map))
		return (ERR_ELEMENT_TYPE);
	if (!ft_check_n_of_element_map(map, PLAYER, 1, 1)
		|| !ft_check_n_of_element_map(map, COLLECTIBLE, 1, -1)
		|| !ft_check_n_of_element_map(map, EXIT_MAP, 1, -1))
		return (ERR_ELEMENT_NUM);
	return (0);
}
