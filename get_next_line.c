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


char	*build_line(int fd, char *buffer)
{

}
char	*get_the_line(int fd, char *buffer)
{
	char	*result;
	int		nb_read;
	size_t	i;

	nb_read = -1;
	result = NULL;
	i = 0;
	if (buffer[0] != '\0')
	{
		result = ft_strjoin(buffer, NULL, '\n', &i);
		if (!result)
		{
			free(result);
			return (NULL);
		}
		ft_memcpy(buffer, &buffer[i], ft_strlen(buffer + i, '\0') + 1);
		if (result && ft_strchr(result, '\n') == 1)
			return (result);
	}
	while (nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(result);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		if (result && ft_strchr(result, '\n') == 1)
			return (result);
		if (buffer[0] != '\0')
		{
			result = ft_strjoin(buffer, result, '\n', &i);
			if (!result)
				return (NULL);
		}
		ft_memcpy(buffer, &buffer[i], ft_strlen(buffer + i, '\0') + 1);
		if (result && ft_strchr(result, '\n') == 1)
			return (result);
		if (buffer[0] == '\0' && !result)
			return (NULL);
	}
	return (result);
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
	line = read_file(fd, buffer);
	if (line == NULL)
		return (NULL);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char	*result;
//
// 	fd = open("test.txt", O_RDONLY);
// 	for (size_t i = 0; i < 4; i++)
// 	{
// 		result = get_next_line(fd);
// 		printf("Final result :%s\n", result);
// 		free(result);
// 	}
// 	close(fd);
// 	return (0);
// }
