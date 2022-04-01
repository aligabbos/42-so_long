/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:46:24 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/29 20:06:56 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char			*str;

	str = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		gnl.fd = fd;
		if (!gnl.buf)
		{
			gnl.buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (gnl.buf)
				gnl.buf[BUFFER_SIZE] = '\0';
		}
		gnl_get_str(&gnl);
		if (gnl.str)
		{
			str = gnl_strjoin(str, gnl.str, 0);
			free(gnl.str);
			gnl.str = NULL;
		}
	}
	return (str);
}

int	gnl_set_str(t_gnl *node, ssize_t r, int nl)
{
	char	*tmp;

	tmp = node->str;
	if (r < BUFFER_SIZE && r != 0)
		node->buf[r] = '\0';
	if (nl == -1
		|| *(node->buf + (nl + 1)) == '\0')
	{
		node->str = gnl_strjoin(node->str, node->buf + node->offset, 0);
		node->offset = 0;
	}
	else
	{
		node->str = gnl_strjoin(node->str, node->buf + node->offset, nl + 1);
		node->offset += (nl + 1);
		if (!*(node->buf + node->offset))
			node->offset = 0;
	}
	if (tmp)
		free(tmp);
	if (nl == -1)
		return (1);
	else
		return (0);
}

void	gnl_get_str(t_gnl *node)
{
	ssize_t	r;

	r = 0;
	if (node->buf && !node->offset)
		r = read(node->fd, node->buf, BUFFER_SIZE);
	while ((r > 0 || node->offset) \
		&& gnl_set_str(node, r, gnl_find_nl(node->buf + node->offset, r)))
		r = read(node->fd, node->buf, BUFFER_SIZE);
	if (node->buf && !node->offset)
	{
		free(node->buf);
		node->buf = NULL;
	}
}
