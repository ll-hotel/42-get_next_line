/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:02:38 by ll-hotel          #+#    #+#             */
/*   Updated: 2023/11/24 20:25:31 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

unsigned long	ft_strlen(char *s)
{
	unsigned long	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l])
		l += 1;
	return (l);
}

unsigned long	ft_strlcpy(char *dest, char *source, unsigned long l)
{
	unsigned long	i;

	i = 0;
	while (i < l && source[i])
	{
		dest[i] = source[i];
		i += 1;
	}
	dest[i] = 0;
	return (i);
}

unsigned long	extend_line(char **line, int sup_size)
{
	const unsigned long	len_old = ft_strlen(*line);
	char				*old;
	unsigned long		i;

	old = *line;
	*line = malloc(sizeof(char) * (len_old + sup_size));
	if (!*line)
	{
		if (old)
			free(old);
		return (0);
	}
	i = 0;
	while (i < len_old + sup_size)
		(*line)[i++] = 0;
	if (old)
	{
		ft_strlcpy(*line, old, -1);
		free(old);
	}
	return (sup_size);
}

unsigned long	next_line(char *str)
{
	const unsigned long	len = ft_strlen(str);
	unsigned long		i;

	if (!str)
		return (-1);
	i = 0;
	while (i < len && str[i] != '\n')
		i += 1;
	return (i + (str[i] == '\n'));
}

unsigned long	readtomemory(int fd, t_memory *memory)
{
	int	r;

	r = read(fd, memory->str, BUFFER_SIZE);
	memory->len = r;
	if (r >= 0)
		memory->str[r] = 0;
	return (r);
}
