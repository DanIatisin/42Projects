/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 12:06:57 by diatisin          #+#    #+#             */
/*   Updated: 2026/07/30 12:18:23 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char **buffer)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	if (!(*buffer) || !(**buffer))
		return (NULL);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = ft_strdup(*buffer);
	if (!line)
		return (NULL);
	line[i] = '\0';
	temp = ft_strdup(*buffer + i);
	free(*buffer);
	*buffer = temp;
	return (line);
}

static char	*gnl_read_buffer(int fd, char *buffer)
{
	char	*read_buffer;
	char	*tmp;
	int		bytes_read;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(read_buffer);
			free(buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, read_buffer);
		free(tmp);
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = gnl_read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(&buffer[fd]);
	return (line);
}
