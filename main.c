/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/15 06:06:16 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
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
	return (-1);
}
#endif

int main(void)
{
	int		fd;
	char	*line;
	char	test[BUFFER_SIZE];

	*test = 0;
	// #if 1
	// fd = open("sample08.txt", 0);
	// // fd = open("a", O_RDONLY);
	// // fd = open("41_no_nl", 0);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s", line);
	// 	if (!line)
	// 		break;
	// 	free(line);
	// }
	// // for (size_t i = 0; i < 2; i++)
	// // {
	// // 	line = get_next_line(fd);
	// // 	printf("%s", line);
	// // }
	// // close(fd);
	// #endif
	return (0);
}


// int main(void)
// {
// 	char	ptr[] = "";
	
// 	ft_strdup("\0");
// 	return (0);
// }
// #include "get_next_line.h"
// #include <fcntl.h>

// int    main(int argc, char **argv)
// {
//     int fd1;
//     char *txt;

//     if(argc < 2)
//         return (1);
//     fd1 = open(argv[1], O_RDONLY);
//     txt = get_next_line(fd1); 
//     printf("[Return Line:] %s",txt);
//     free(txt);
//     while (txt)
//     {
//         txt = get_next_line(fd1);
//         if(!txt)
//         {
//             printf("\n");
//             break;
//         }
//         printf("[Return Line:] %s",txt);
//         free(txt);
//     }
//     close(fd1);
//     system("leaks a.out");
//     return (0);
// }