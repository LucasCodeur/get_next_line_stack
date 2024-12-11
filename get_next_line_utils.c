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
	*p_dest = '\0';
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	const unsigned char *p_src;
	unsigned char	*p_dest;

	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (!p_src)
		return (NULL);
	if (p_dest <= p_src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	return dest;
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

size_t	ft_strrchr(char *str, char c)
{
	ssize_t	i;

	i = ft_strlen(str, '\0');
	while (i >= 0)
	{
		if (str[i] == c)
			return (1);
		i--;
	}
	return (0);
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
	size_t i;
	size_t j;

	result = ft_calloc(ft_strlen(src, '\n') + ft_strlen(c_remaining, '\0') + ft_strchr(src, '\n') + 1,  sizeof(char));
	i = 0;
	j = 0;
	if (!result)
		return (NULL);
	while (c_remaining && c_remaining[i])
	{
		result[i] = c_remaining[i];
		i++;
	}
	while (src[j] != c && src[j])
	{
		result[i + j] = src[j];
		src[j] = '\0';
		j++;
	}
	if (src[j] == c)
	{
		src[j] = '\0';
		result[i + j] = '\n';
		j++;
	}
	*pos = j;
	// i = 0;
	// j++;
	// printf("j before:%zu\n", j);
	// while (src[j])
	// {
	// 	j++;
	// 	i++;
	// }
	// printf("j after:%zu\n", j);
	// printf("i:%zu\n", i);
	// ft_memmove(&src[j - i], src, i);
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
