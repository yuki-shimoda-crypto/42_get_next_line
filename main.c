/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/15 11:07:29 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <libc.h>
#include "get_next_line.h"

#if 0
void	*malloc(size_t size)
{
	(void)size;

	return (NULL);
}
#endif

#if 0
ssize_t	read(int fildes, void *buf, size_t nbyte)
{
	(void)fildes;
	(void)buf;
	(void)nbyte;

	return (-1);
}
#endif

int main(void)
{
	int		fd;
	char	*line;

	fd = open("sample0.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break;
		free(line);
	}
	close(fd);
	system("leaks a.out");
	return (0);
}
