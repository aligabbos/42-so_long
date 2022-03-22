/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:19:54 by gsemerar          #+#    #+#             */
/*   Updated: 2022/03/22 11:00:56 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

unsigned int	ft_check_extension(char *file_name, char *ext)
{
	char	*check;
	int		dim_file_name;
	int		dim_ext;

	dim_file_name = ft_strlen(file_name);
	dim_ext = ft_strlen(EXT_BER);
	if (dim_file_name < dim_ext)
		return (0);
	check = ft_strnstr(file_name + (dim_file_name - dim_ext), ext, dim_ext);
	if (!check)
		return (0);
	return (1);
}

unsigned int	ft_check_size_map(t_map *map, int fd)
{
	char	*row;
	int		length_cols;

	row = get_next_line(fd);
	if (!row)
		return (0);
	ft_parse_row(&row);
	length_cols = ft_strlen(row);
	map->rows = 1;
	map->cols = length_cols;
	while (row)
	{
		free(row);
		row = get_next_line(fd);
		if (row)
		{
			map->rows += 1;
			length_cols = ft_strlen(row);
			if ((row[length_cols - 1] == '\n' && length_cols - 1 != map->cols) || \
				(row[length_cols - 1] != '\n' && length_cols != map->cols))
				return (0);
		}
	}
	return (1);
}

void	ft_parse_row(char **row)
{
	char			*r;
	unsigned int	length;

	r = *row;
	length = ft_strlen(r);
	if (length > 0 && *(r + length - 1) == '\n')
		*(r + length - 1) = '\0';
}
