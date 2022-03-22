/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:42:51 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/31 08:51:55 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl
{
	int				fd;
	char			*buf;
	int				offset;
	char			*str;
}	t_gnl;

char	*get_next_line(int fd);
void	gnl_get_str(t_gnl *node);
int		gnl_set_str(t_gnl *node, ssize_t r, int nl);

//utils
size_t	gnl_strlen(const char *s);
int		gnl_find_nl(char *buf, ssize_t r);
void	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strjoin(const char *s1, const char *s2, size_t d2);

#endif
