#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include "get_next_line_bonus.h"

static   char *get_line(char **buffer)
{
	char	*line;
    char    *temp;
	int		i;

	i = 0;
    if(!(*buffer) || !(**buffer))
        return(NULL);
    while((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    if((*buffer)[i] == '\n')
        i++;
    line = ft_strdup(*buffer);
	if(!line)
		return(NULL);
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
	static char *buffer;
    char		*line;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buffer = gnl_read_buffer(fd, buffer);
		if (!buffer)
			return (NULL);
    line = get_line(&buffer);
    return (line);
}