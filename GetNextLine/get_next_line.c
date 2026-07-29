/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <diatisin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:14:55 by diatisin          #+#    #+#             */
/*   Updated: 2026/07/29 12:46:19 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static   char *get_line(char **buffer)
{
	char	*line;
    char    *temp;
	int		i;

    if(!(*buffer) || !(**buffer))
        return(NULL);
    while((*buffer)[i] && *buffer != '\n')
        i++;
    if((*buffer)[i] == '\n')
        i++;
    line = ft_strdup(*buffer);
    line[*buffer] = '\0';
    temp = ft_strdup(*buffer + i);
    free(*buffer);
	return (line);
}

static char	*gnl_read_buffer(int fd, char *buffer)
{
	char	*read_buffer;
	size_t	bytes_read;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(read_buffer);
			free(buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(read_buffer, buffer);
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char *buffer;
    char    *line;
    
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    buffer = gnl_read_buffer(fd, buffer);
    line = get_line(&buffer);
    free(buffer);
    return (line);
}