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

char	*get_line(int fd, char *buffer)
{
	char	*line;
	char	*result;
	int		nb_read;
	size_t	size;
	size_t	i;

	nb_read = -1;
	result = NULL;
	printf("BUFFER:%s\n", buffer);
	i = 0;
	if (buffer[0] != '\0')
	{
		// printf("size of i:%zu", i);
		// size = ft_strlen(&buffer[*i], '\n') + 1;
		result = ft_strjoin(buffer, "", '\n', &i);
		ft_memcpy(buffer, &buffer[i], ft_strlen(&buffer[i], '\0'));
		// printf("result after one while: %s\n", result);
		if (result && ft_strchr(result, '\n') == 1)
			return (result);
	}
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			return (NULL);
		}
		buffer[nb_read] = '\0';
		if (result && ft_strchr(result, '\n') == 1)
			return (result);
		result = ft_strjoin(buffer, result, '\n', &i);
		 // if (ft_strchr(buffer, '\n') == 1)
			ft_memcpy(buffer, &buffer[i], ft_strlen(buffer + i, '\0'));
		if (result && ft_strchr(result, '\n') == 1)
			return (result);
		// if (result)
		// 	continue;
		if (!result)
			return (NULL);
		if (buffer[0] == '\0')
			return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, buffer);
	if (line == NULL)
		return (NULL);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*result;

	fd = open("test.txt", O_RDONLY);
	for (size_t i = 0; i < 4; i++)
	{
		result = get_next_line(fd);
		printf("Final result :%s\n", result);
		free(result);
	}
	close(fd);
	return (0);
}
