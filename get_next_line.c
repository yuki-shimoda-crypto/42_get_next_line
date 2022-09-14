/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:53:14 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/15 05:15:17 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ft_make_ret_over(char **ptr, char **over, char **ret)
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

char	*ft_readline(int fd, char **over, char **ptr)
{
	ssize_t		size;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1ul];

	while (1)
	{
		*ptr = ft_strchr(*over, '\n');
		if (*ptr)
			break;
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			ft_free(over);
			return (NULL);
		}
		buf[size] = '\0';
		if (size == 0)
			break;
		tmp = ft_strjoin(*over, buf);
		ft_free(over);
		*over = tmp;
	}
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
	{
		over = (char *)malloc(sizeof(char) * 1);
		if (!over)
			return (NULL);
		over[0] = '\0';
	}
	over = ft_readline(fd, &over, &ptr);
	if (!over)
		return (NULL);
	ret = ft_make_ret_over(&ptr, &over, &ret);
	return (ret);
}

#if 0
void	*malloc(size_t size)
{
	(void)size;
	return (NULL);
}
#endif

# if 0
ssize_t	read(int fildes, void *buf, size_t nbyte)
{
	return (-1);
}
#endif

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	#if 1
// 	fd = open("sample08.txt", 0);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 	}
// 	close(fd);
// 	#endif
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*over;
// 	char		*ret;
// 	char		*ptr;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!over)
// 	{
// 		over = (char *)malloc(sizeof(char) * 1);
// 		if (!over)
// 			return (NULL);
// 		over[0] = '\0';
// 	}
// 	over = ft_readline(fd, &over, &ptr);
// 	if (!over)
// 		return (NULL);
// 	// while (1)
// 	// {
// 	// 	ptr = ft_strchr(over, '\n');
// 	// 	if (ptr)
// 	// 		break;
// 	// 	size = read(fd, buf, BUFFER_SIZE);
// 	// 	if (size < 0)
// 	// 	{
// 	// 		ft_free(&over);
// 	// 		return (NULL);
// 	// 	}
// 	// 	buf[size] = '\0';
// 	// 	if (size == 0)
// 	// 		break;
// 	// 	tmp = ft_strjoin(over, buf);
// 	// 	ft_free(&over);
// 	// 	over = tmp;
// 	// }

// 	ret = ft_make_ret_over(&ptr, &over, &ret);
// 	// ptr = ft_strchr(over, '\n');	
// 	// if (!ptr)
// 	// {
// 	// 	if (!ft_strlen(over))
// 	// 	{
// 	// 		ft_free(&over);
// 	// 		return (NULL);
// 	// 	}
// 	// 	ret = ft_strdup(over);
// 	// 	ft_free(&over);
// 	// 	over = NULL;
// 	// }
// 	// else
// 	// {
// 	// 	ret = ft_substr(over, 0, ptr - over + 1);
// 	// 	// ret = ft_strndup(over, ptr - over + 1);
// 	// 	tmp = ft_strdup(over + (ptr - over + 1));
// 	// 	ft_free(&over);
// 	// 	over = tmp;
// 	// }
// 	return (ret);
// }