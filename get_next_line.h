/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:23:39 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/10 10:22:44 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

// HAVE TO WITHDRAW
# include <stdio.h>

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 15
#endif

size_t	ft_strlen(char *str, char c);
size_t	ft_strrchr(char *str, char c);
size_t	ft_strchr(char *str, char c);
char	*ft_strjoin(char *src, char *c_remaining, char c, size_t *pos);
void	*ft_memmove(void *dest, void *src, size_t n);
void	ft_memcpy(char *dest, char *src, ssize_t n);
char	*get_next_line(int fd);

#endif

