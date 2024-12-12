/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:56:37 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/10 08:56:40 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

void	ft_memcpy(char *dest, char *src, ssize_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (!src)
		return ;
	while (n > 0)
	{
		*p_dest++ = *p_src++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory_block;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	memory_block = malloc(nmemb * size);
	if (!memory_block)
		return (NULL);
	while (i < nmemb * size)
	{
		memory_block[i] = 0;
		i++;
	}
	return ((void *)memory_block);
}

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}


size_t	ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	to_reach;

	i = 0;
	to_reach = ft_strlen(s, '\0');
	while (i <= to_reach)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *src, char *c_remaining, char c, size_t *pos)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = ft_calloc(ft_strlen(src, '\n') + ft_strlen(c_remaining, '\0') + ft_strchr(src, '\n') + 1,  sizeof(char));
	if (!result)
	{
		free(c_remaining);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (c_remaining && c_remaining[i])
	{
		result[i] = c_remaining[i];
		i++;
	}
	while (src[j] && src[j] != c)
	{
		result[i + j] = src[j];
		j++;
	}
	if (src[j] == c)
	{
		result[i + j] = '\n';
		j++;
	}
	*pos = j;
	free(c_remaining);
	return (result);
}

// int	main(void)
// {
// 	char	src[] = "One P\niecee";
// 	char	*dest;
// 	char	c_remaining[] = "";
//
// 	printf("new_src:%s\n", src);
// 	dest = ft_strjoin(src, c_remaining, '\n');
// 	printf("new_src:%s\n", src);
// 	return (0);
// }
