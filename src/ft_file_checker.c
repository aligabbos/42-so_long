/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:07:16 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/01 09:35:50 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

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
