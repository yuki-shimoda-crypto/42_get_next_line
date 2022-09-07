/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:53:17 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/05 23:21:47by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	char		*tmp;
	char		*ptr;
	char		*sub;
	static char	*over;	
	int			over_flag;
	ssize_t		size;

	if (over)
	{
		line = over;
		over_flag = 1;
	}
	else
	{
		if(!(line = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		*line = '\0';
		over_flag = 0;
	}
	while (1)
	{
		if (fd < 0)
		{
			free(line);
			return (NULL);
		}
		if (over_flag)
		{
			ptr = ft_strchr(line, '\n');
			tmp = line;
			over_flag = 0;
			if (ptr != NULL)
			{
				line = ft_substr(tmp, 0, ptr - tmp);
				if (ptr - tmp < BUFFER_SIZE)
					over = ft_substr(tmp, ptr - tmp + 1, BUFFER_SIZE);
				else
					over = NULL;
				free(tmp);
				return (line);
			}
			else
				line = ft_strjoin(tmp, buf);
		}
		else
		{
			if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			{
				free(line);
				return (NULL);
			}
			size = read(fd, buf, BUFFER_SIZE);
			if (size < 0)
			{
				free(buf);
				free(line);
				return (NULL);
			}
			if (size < BUFFER_SIZE)
			{
				tmp = line;
				line = ft_strjoin(tmp, buf);
				free(buf);
				free(tmp);
				return (line);
			}
			ptr = ft_strchr(buf, '\n');
			if (ptr != NULL)
			{
				tmp = line;
				sub = ft_substr(buf, 0, ptr - buf);
				line = ft_strjoin(tmp, sub);
				if (ptr - buf < BUFFER_SIZE)
					over = ft_substr(buf, ptr - buf + 1, BUFFER_SIZE);
				else
					over = NULL;
				free(sub);
				free(buf);
				free(tmp);
				return (line);
			}
			else
			{
				tmp = line;
				line = ft_strjoin(tmp, buf);
			}
		}
	}
	return(line);
}

// #include <stdio.h>
// #include <fcntl.h>

// #if 0
// void	*malloc(size_t size)
// {
// 	(void)size;
// 	return (NULL);
// }
// #endif

// # if 0
// ssize_t	read(int fildes, void *buf, size_t nbyte)
// {
// 	return (-1);
// }
// #endif

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	#if 0
// 	fd = open("sample01.txt", 0);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	close(fd);
// 	#endif

// 	#if 1
// 	fd = open("sample08.txt", 0);
// 	for (int i = 0; i < 7; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s\n", line);
// 	}
// 	close(fd);
// 	#endif

// 	#if 0
// 	static char	*ptr;
// 	printf("%s\n", ptr);
// 	#endif

// 	#if 0
// 	printf("%zu\n", strlen("a\n"));
// 	printf("%s", ft_substr("a\n", 0, 2));
// 	#endif
// 	// line = (char *)malloc(sizeof(char) * 1);
// 	// *line = '\0';
// 	// printf("%s\n", line);
// 	return (0);
// }
