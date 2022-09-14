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
	if (!over[i])
	{
		free(over);
		return (NULL);
	}
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
		if (!over)
			return (NULL);
		over[0] = '\0';
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(over);
		return (NULL);
	}
	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(over, '\n'))
		{
			break;
		}
		if (size <= 0)
		{
			free(over);
			free(buf);
			return (NULL);
		}
		buf[size] = '\0';
		tmp = ft_strjoin(over, buf);
		free(over);
		over = tmp;
	}
	printf("%s\n", over);
	free(buf);
	return (over);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*line;

	// if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	over = ft_readline(fd, over);
	if (!over)
		return (NULL);
	line = ft_get_line(over);
	// printf("%s", line);
	over = ft_get_next(over);
	return (line);
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
// 	fd = open("41_no_nl", 0);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (!line)
// 			break;
// 	}
// 	// for (size_t i = 0; i < 1; i++)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// }
// 	close(fd);
// 	#endif
// 	return (0);
// }


#include "get_next_line.h"
#include <fcntl.h>

int    main(int argc, char **argv)
{
    int fd1;
    char *txt;

    if(argc < 2)
        return (1);
    fd1 = open(argv[1], O_RDONLY);
    txt = get_next_line(fd1); 
    printf("[Return Line:] %s",txt);
    free(txt);
    while (txt)
    {
        txt = get_next_line(fd1);
        if(!txt)
        {
            printf("\n");
            break;
        }
        printf("[Return Line:] %s",txt);
        free(txt);
    }
    close(fd1);
    system("leaks a.out");
    return (0);
}
