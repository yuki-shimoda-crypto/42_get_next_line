/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:53:14 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/15 06:11:40 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*ft_error(char **buf, char **over)
{
	ft_free(buf);
	ft_free(over);
	return (NULL);
}

static char	*ft_make_ret_over(char **ptr, char **over, char **ret)
{
	char	*tmp;

	*ptr = ft_strchr(*over, '\n');
	if (!*ptr)
	{
		if (!ft_strlen(*over))
		{
			ft_free(over);
			return (NULL);
		}
		*ret = ft_strdup(*over);
		ft_free(over);
		*over = NULL;
	}
	else
	{
		*ret = ft_substr(*over, 0, *ptr - *over + 1);
		tmp = ft_strdup(*over + (*ptr - *over + 1));
		ft_free(over);
		*over = tmp;
	}
	return (*ret);
}

static char	*ft_readline(int fd, char **over, char **ptr)
{
	ssize_t	size;
	char	*tmp;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1ul);
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		*ptr = ft_strchr(*over, '\n');
		if (*ptr)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (ft_error(&buf, over));
		buf[size] = '\0';
		if (size == 0)
			break ;
		tmp = ft_strjoin(*over, buf);
		ft_free(over);
		*over = tmp;
	}
	ft_free(&buf);
	return (*over);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*ret;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!over)
		over = ft_strdup("");
	if (!over)
		return (NULL);
	over = ft_readline(fd, &over, &ptr);
	if (!over)
		return (NULL);
	ret = ft_make_ret_over(&ptr, &over, &ret);
	return (ret);
}
