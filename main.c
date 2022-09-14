/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:46:49 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/14 22:18:02 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	#if 1
	fd = open("sample08.txt", 0);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break;
	}
	// for (size_t i = 0; i < 2; i++)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s", line);
	// }
	close(fd);
	#endif
	return (0);
}