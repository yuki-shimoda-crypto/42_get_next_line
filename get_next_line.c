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
#define BUF_SIZE 3

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s != '\0')
		s++;
	return ((char*)s);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*tmp;
	char	*r_over;	
	ssize_t	check_error;

	if (fd < 0)
		return (NULL);
	read(fd, tmp, BUF_SIZE);
	// if (read(fd, tmp, BUF_SIZE) == -1)
	// ft_strchr(tmp, '\n');
	// line = tmp;
	// printf("%s\n", tmp);
	return(tmp);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*line;

	fd = open("sample01.txt", 0);
	line = get_next_line(fd);
	// read(fd, line, BUF_SIZE);
	printf("%s\n", line);
	close(fd);

	return (0);
}
