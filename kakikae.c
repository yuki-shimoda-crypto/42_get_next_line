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

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(over);
		return (NULL);
	}
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			free(over);
			return (NULL);
		}
		if (size == 0)
			break;
		tmp = ft_strjoin(over, buf);
		free(over);
		over = tmp;
	}
	free(buf);
	return (over);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*line;

	if (!over)
	{
		over = (char *)malloc(sizeof(char) * 1);
		if (!over)
			return (NULL);
		over[0] = '\0';
	}
	// if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	over = ft_readline(fd, over);
	if (!over)
		return (NULL);
	line = ft_get_line(over);
	over = ft_get_next(over);
	return (line);
}
