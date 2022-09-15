/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/15 12:57:22 by yshimoda         ###   ########.fr       */
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

#if 0
char	*ft_strjoin(char const *s1, char const *s2)
{
	(void)s1;
	(void)s2;

	return (NULL);
}
#endif

#if 0
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	(void)s;
	(void)start;
	(void)len;

	return (NULL);
}
#endif

#if 0
char	*ft_strdup(const char *s1)
{
	(void)s1;

	return (NULL);
}
#endif

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("sample08.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 		free(line);
// 	}
// 	close(fd);
// 	system("leaks a.out");
// 	return (0);
// }

// ctrl + c or ctrl + d to stop
// int    main(void)
// {
//     char *txt;

//     txt = "1";
//     while(txt)
//     {
//         txt = get_next_line(0);
//         printf("[Return:] Line: %s\n",txt);
//         free(txt);
//     }
//     system("leaks a.out");
//     return (0);
// }
