/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:46:19 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/29 11:40:13 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	gnl_find_nl(char *buf, ssize_t r)
{
	ssize_t	i;

	i = 0;
	if (!r)
		r = gnl_strlen(buf);
	while (i < r)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*gnl_strjoin(const char *s1, const char *s2, size_t d2)
{
	size_t	dim;
	char	*str;

	if (!s2)
		return (NULL);
	if (d2)
		dim = gnl_strlen(s1) + d2 + 1;
	else
		dim = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	str = (char *) malloc(sizeof(char) * dim);
	if (!str)
		return (NULL);
	gnl_strlcpy(str, s1, gnl_strlen(s1) + 1);
	gnl_strlcpy(str + gnl_strlen(str), s2, dim - gnl_strlen(str));
	return (str);
}
