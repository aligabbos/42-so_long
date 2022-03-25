/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:05:04 by gsemerar          #+#    #+#             */
/*   Updated: 2022/03/24 21:16:00 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../ft_printf/includes/ft_printf.h"

// TYPES
typedef struct s_map
{
	char			*file;
	char			**map;
	int				fd;
	unsigned int	rows;
	unsigned int	cols;
}	t_map;

// MACRO
# define EXT_BER ".ber"

// ERROR CODES

unsigned int	ft_check_extension(char *file_name, char *ext);
unsigned int	ft_check_size_map(t_map *map, int fd);
void			ft_parse_row(char **row);

// Parse
void			ft_remove_nl(char **row);
char			*ft_ignore_nl(int fd);

// Map
void			ft_init_map(t_map *map, char *file_name);
unsigned int	ft_create_map(t_map *map);
unsigned int	ft_set_rc_map(t_map *map);
unsigned int	ft_open_map(t_map *map);
unsigned int	ft_close_map(t_map *map);

#endif
