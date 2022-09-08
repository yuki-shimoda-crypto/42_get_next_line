/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:41:19 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/08 14:14:20 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define SAFE_FREE(ptr) {free(ptr); ptr = NULL;}

void	ft_free(char *one, char *two, char *three, char *four)
{
	free(one);
	free(two);
	free(three);
	free(four);
	one = NULL;
	two = NULL;
	three = NULL;
	four = NULL;
}

int	ft_find_new_line(char **line, char **buf, char **over)
{
	char	*ptr;
	char	*tmp;
	char	*sub;

	ptr = ft_strchr(*buf, '\n');
	tmp = *line;
	if (ptr == NULL)
	{
		*line = ft_strjoin(tmp, *buf);
		SAFE_FREE(tmp);
		// SAFE_FREE(buf);
		// free(buf);
		// tmp = NULL;*buf = NULL;
		return (0);
	}
	else
	{
		sub = ft_substr(*buf, 0, ptr - *buf + 0);
		*line = ft_strjoin(tmp, sub);
		*over = ft_substr(*buf, ptr - *buf + 2, BUFFER_SIZE);
		SAFE_FREE(tmp);
		// free(buf);
		SAFE_FREE(sub);
		buf = NULL;
		// return (line);
		return(1);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	// char		*tmp;
	// char		*ptr;
	// char		*sub;
	static char	*over;	
	int			over_flag;
	ssize_t		size;

	line = (char *)malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	// if (over != NULL)
	// 	over_flag = 1;
	// else
	// 	over_flag = 0;
	while (1)
	{
		if (over != NULL)
		{
			// over_flag = 0;
			if (ft_find_new_line(&line, &over, &over))
				return (line);
		}
		else
		{
			buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (buf == NULL)
				return (NULL);
			size = read(fd, buf, BUFFER_SIZE);
			if (size < 0)
				return (NULL);
			else if (size < BUFFER_SIZE)
				return (ft_strjoin(line, buf));
			else
			{
				if (ft_find_new_line(&line, &buf, &over))
					return (line);
			}
		}
		// ptr = ft_strchr(buf, '\n');
		// if (ptr == NULL)
		// {
		// 	tmp = line;
		// 	line = ft_strjoin(tmp, buf);
		// 	free(tmp);free(buf);
		// }
		// else
		// {
		// 	sub = ft_substr(buf, 0, ptr - buf);
		// 	tmp = line;
		// 	line = ft_strjoin(tmp, sub);
		// 	over = ft_substr(buf, ptr - buf + 2, BUFFER_SIZE);
		// 	free(tmp);free(buf);free(sub);
		// 	return(line);
		// }
	}
	return(line);
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
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
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