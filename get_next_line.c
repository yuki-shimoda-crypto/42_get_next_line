/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 23:41:27 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/14 13:47:57y yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next(char *over)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	while (over[i] && over[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(over) - i + 1));
	if (s == NULL)
		return (NULL);
	i++;
	j = 0;
	while (over[i] != '\0')
		s[j++] = over[i++];
	s[j] = '\0';
	free(over);
	return (s);
}

char	*ft_get_line(char *over)
{
	size_t	i;
	char	*s;

	i = 0;
	while (over[i] && over[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (over[i] && over[i] != '\n')
	{
		s[i] = over[i];
		i++;
	}
	s[i] = '\n';
	s[++i] = '\0';
	return (s);
}

char	*ft_readline(int fd, char *over)
{
	char	*buf;
	char	*tmp;
	ssize_t	size;

	if (!over)
	{
		over = (char *)malloc(sizeof(char) * 1);
		over[0] = '\0';
	}
	if (!over)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = 1;
	while (size > 0 && !ft_strchr(over, '\n'))
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			return (NULL);
		}
		over = ft_strjoin(over, buf);
	}
	free(buf);
	return (over);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	over = ft_readline(fd, over);
	// printf("%s", over);
	if (!over)
		return (NULL);
	line = ft_get_line(over);
	over = ft_get_next(over);
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

	#if 1
	fd = open("sample08.txt", 0);
	for (size_t i = 0; i < 8; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
	#endif

	#if 0
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
