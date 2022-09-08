/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/08 17:02:54 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	c;
	char	*line;

	fd = open("sample08.txt", 0);
	for (size_t i = 0; i < 1; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}

// #include <ctype.h>
// #include <limits.h>
// #include <math.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// int main(int argc, char const *argv[], char **envp)
// {
// 	for (size_t i = 0; envp[i] != NULL; i++)
// 		printf("%s\n", envp[i]);
// 	/* code */
// 	return 0;
// }
