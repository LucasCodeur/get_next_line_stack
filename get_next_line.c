/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:10:42 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/11 18:36:17 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*build_line(int fd, char *buffer, size_t *pos)
{
	char	*line;
	int		nb_read;

	nb_read = -1;
	line = NULL;
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			// free(line);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		if (line && ft_strchr(line, '\n') == 1)
			return (line);
		if (buffer[0] != '\0')
		{
			line = ft_strjoin(buffer, line, '\n', pos);
			if (!line)
				return (NULL);
		}
		ft_memcpy(buffer, &buffer[*pos], ft_strlen(buffer + *pos, '\0') + 1);
		if (line && ft_strchr(line, '\n') == 1)
			return (line);
		if (buffer[0] == '\0' && !line)
			return (NULL);
	}
	return (line);
}

char	*get_the_line(int fd, char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	line = NULL;
	if (buffer[0] != '\0')
	{
		line = build_line(fd, buffer, &i);
		if (!line)
		{
			free(line);
			return (NULL);
		}
		ft_memcpy(buffer, &buffer[i], ft_strlen(buffer + i, '\0') + 1);
		if (line && ft_strchr(line, '\n') == 1)
			return (line);
	}
	line = build_line(fd, buffer, &i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (line)
	{
		free(line);
		line = NULL;
	}
	line = get_the_line(fd, buffer);
	if (line == NULL)
		return (NULL);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*line;
//
// 	fd = open("test.txt", O_RDONLY);
// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("Final line :%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
