/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:53:14 by yshimoda          #+#    #+#             */
/*   Updated: 2022/09/08 17:30:41 by yshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s + 1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			ptr[i] = s1[i];
		else
			ptr[i] = s2[i - len_s1];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ptr;

	len_s = ft_strlen(s);
	if (len_s > len)
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len_s + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && i + start < len_s)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	tmp;

	ptr = (unsigned char *)b;
	tmp = (unsigned char)c;
	i = 0;
	while (i < len)
		ptr[i++] = tmp;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (SIZE_MAX / count < size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}