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
# define MIN_R 3
# define MIN_C 3
# define MIN 5

// Map
# define WALL '1'
# define EMPTY_SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT_MAP 'E'
# define START_POSITION 'P'

// Error codes
# define ERR_EXT 1
# define ERR_COLS 2
# define ERR_SIZE 3
# define ERR_PERIMETER 4

// FUNCTIONS
// Checks
unsigned int	ft_check_extension(char *file_name, char *ext);
unsigned int	ft_check_cols_map(t_map *map);
unsigned int	ft_check_size_map(t_map *map);
unsigned int	ft_check_perimeter_map(t_map *map);
unsigned int	ft_check_element_map(t_map *map, char element, int limit);

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
