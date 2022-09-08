/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:41:19 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/08 19:49:10 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define SAFE_FREE(ptr) {free(ptr); ptr = NULL;}

char	*ft_join_free_a(char *a, char *b)
{
	char	*tmp;

	tmp = ft_strjoin(a, b);
	SAFE_FREE(a);
	return (tmp);
}

char	*ft_read_line(int fd, char *over)
{
	char	*buf;
	ssize_t	size;
	char	*tmp;

	if (!over)
		over = (char *)malloc(sizeof(char) * 1);
	over[0] = '\0';
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL || over == NULL)
	{
		SAFE_FREE(over);
		SAFE_FREE(buf);
		return (NULL);
	}
	buf[0] = '\0';
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			SAFE_FREE(buf);
			return (NULL);
		}
		if (size)
			break;
		tmp = ft_strjoin(over, buf);
		SAFE_FREE(over);
		if (ft_strchr(tmp, '\n'))
			break;
	}
	SAFE_FREE(buf);
	return (over);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*over;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	over = ft_read_line(fd, over);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

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

int main(void)
{
	int		fd;
	char	c;
	char	*line;

	#if 0
	fd = open("sample01.txt", 0);
	// line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	// read(fd, line, BUFFER_SIZE);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	// c = '\n';
	// write(1, &c, 1);
	#endif

	#if 1
	fd = open("sample08.txt", 0);
	// for (int i = 0; i < 5; i++)
	// {
		line = get_next_line(fd);
		printf("%s", line);
	// }
	close(fd);
	#endif

	#if 0
	static char	*ptr;
	printf("%s\n", ptr);
	#endif

	#if 0
	printf("%zu\n", strlen("a\n"));
	printf("%s", ft_substr("a\n", 0, 2));
	#endif
	// line = (char *)malloc(sizeof(char) * 1);
	// *line = '\0';
	// printf("%s\n", line);
	return (0);
}