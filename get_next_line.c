/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:53:14 by yshimoda          #+#    #+#             */
/*   Updated: 2022/10/09 23:15:38 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define malloc ft_malloc

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

static char	*ft_readline(int fd, char **over, char **ptr, char **tmp)
{
	ssize_t	size;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1ul);
	if (!buf)
	{
		ft_free(*over);
		return (NULL);
	}
	while (1)
	{
		*ptr = ft_strchr(*over, '\n');
		if (*ptr)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (ft_error(&buf, over));
		buf[size] = 0;
		if (size == 0)
			break ;
		*tmp = ft_strjoin(*over, buf);
		ft_free(over);
		if (!*tmp)
			break ;
		*over = *tmp;
	}
	ft_free(&buf);
	return (*over);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*ret;
	char		*ptr;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!over)
		over = ft_strdup("");
	if (!over)
		return (NULL);
	over = ft_readline(fd, &over, &ptr, &tmp);
	if (!over)
		return (NULL);
	ret = ft_make_ret_over(&ptr, &over, &ret);
	return (ret);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <libc.h>
// #include "get_next_line.h"

// #if 0
// #undef malloc
// void	*ft_malloc(size_t size)
// {
// 	static int i;
	
// 	i++;
// 	if (i % 2 == 0)
// 		return(malloc(size));
// 	(void)size;

// 	return (NULL);
// }
// #endif

// #if 0
// #undef free
// void	ft_free(void *p)
// {
// 	static int i;

// 	i++;
// 	free(p);
// 	printf("%d\n", i);
// }
// #endif

// #if 0
// ssize_t	read(int fildes, void *buf, size_t nbyte)
// {
// 	(void)fildes;
// 	(void)buf;
// 	(void)nbyte;

// 	return (-1);
// }
// #endif

// #if 0
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	(void)s1;
// 	(void)s2;

// 	return (NULL);
// }
// #endif

// #if 0
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	(void)s;
// 	(void)start;
// 	(void)len;

// 	return (NULL);
// }
// #endif

// #if 0
// char	*ft_strdup(const char *s1)
// {
// 	(void)s1;

// 	return (NULL);
// }
// #endif

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("sample0.txt", O_RDONLY);
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
