/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:05:04 by gsemerar          #+#    #+#             */
/*   Updated: 2022/04/14 23:03:12 by gsemerar         ###   ########.fr       */
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
# include <mlx.h>
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

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*file;
	int		img_width;
	int		img_height;
	int		img_pos_x;
	int		img_pos_y;
}	t_data;

typedef struct s_characters {
	t_data	player;
	t_data	empty_space;
	t_data	wall;
	t_data	collectible;
	t_data	exit_map;
}	t_characters;

typedef struct s_game {
	t_vars			*vars;
	t_characters	*c;
	t_map			*map;
	unsigned int	moves;
}	t_game;

// MACRO
# define GAME_TITLE "so_long"
# define EXT_BER ".ber"
# define MIN_R 3
# define MIN_C 3
# define MIN 5

// Keys
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// Map
# define PLAYER 'P'
# define WALL '1'
# define EMPTY_SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT_MAP 'E'

// Images
# define IMG_PLAYER "./img/player.xpm"
# define IMG_WALL "./img/wall.xpm"
# define IMG_EMPTY_SPACE "./img/empty_space.xpm"
# define IMG_COLLECTIBLE "./img/collectible.xpm"
# define IMG_EXIT_MAP "./img/exit_map.xpm"

// Error codes
# define ERR_FILE 1
# define ERR_EXT 2
# define ERR_COLS 3
# define ERR_SIZE 4
# define ERR_PERIMETER 5
# define ERR_ELEMENT_TYPE 6
# define ERR_ELEMENT_NUM 7

// Error msg
# define ERR_MSG_FILE "Map error: unable to open the map."
# define ERR_MSG_EXT "Map error: wrong map extension."
# define ERR_MSG_COLS "Map error: map must be rectangular."
# define ERR_MSG_SIZE "Map error: map too small."
# define ERR_MSG_PERIMETER "Map error: map must be surrounded by walls."
# define ERR_MSG_ELEMENT_TYPE "Map error: unrecognized element in map."
# define ERR_MSG_ELEMENT_NUM "Map error: wrong number element 'E','C' or 'P'."

// FUNCTIONS
// Checks
unsigned int	ft_check_extension(char *file_name, char *ext);
unsigned int	ft_check_cols_map(t_map *map);
unsigned int	ft_check_size_map(t_map *map);
unsigned int	ft_check_perimeter_map(t_map *map);
unsigned int	ft_check_element_map(t_map *map, char element, int min, int max);

// Parse
void			ft_remove_nl(char **row);
char			*ft_ignore_nl(int fd);

// Map
void			ft_init_map(t_map *map, char *file_name);
unsigned int	ft_create_map(t_map *map);
unsigned int	ft_set_rc_map(t_map *map);
unsigned int	ft_open_map(t_map *map);
unsigned int	ft_close_map(t_map *map);
void			ft_render_map(t_map *map, t_vars *vars, t_characters *c);

// MLX Utils
void			ft_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data			ft_mlx_load_img(void *mlx, char *file);
t_characters	ft_mlx_load_images(void *mlx);

#endif
