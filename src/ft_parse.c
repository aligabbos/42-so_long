/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:55:41 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/01 09:35:50 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_remove_nl(char **row)
{
	char			*r;
	unsigned int	length;

	r = *row;
	length = ft_strlen(r);
	if (length > 0 && *(r + length - 1) == '\n')
		*(r + length - 1) = '\0';
}

char	*ft_ignore_nl(int fd)
{
	char	*row;

	row = get_next_line(fd);
	if (!row)
		return (NULL);
	ft_remove_nl(&row);
	while (row && !ft_strlen(row))
	{
		free(row);
		row = get_next_line(fd);
		ft_remove_nl(&row);
	}
	return (row);
}
