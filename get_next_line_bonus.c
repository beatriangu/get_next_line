/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:51:32 by belamiqu          #+#    #+#             */
/*   Updated: 2023/11/17 17:48:59 by belamiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_gnlstrjoin(basin_buffer, read_buffer);
	if (basin_buffer)
	{
		free(basin_buffer);
	}
	return (temp);
}

char	*read_from_file(char *basin_buffer, int fd)
{
	char	*cup_buffer;
	int		bytes_read;

	cup_buffer = ft_gnlcalloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			free(basin_buffer);
			basin_buffer = NULL;
			return (NULL);
		}
			cup_buffer[bytes_read] = '\0';
			basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_gnlstrchr(basin_buffer, '\n'))
			break ;
	}
	free (cup_buffer);
	return (basin_buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*obtain_remaining(char *buffer)
{
	char	*end_of_line;
	size_t	remaining_length;
	char	*remaining;

	if (buffer == NULL)
		return (NULL);
	end_of_line = ft_gnlstrchr(buffer, '\n');
	if (end_of_line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	remaining_length = ft_gnlstrlen(end_of_line + 1);
	remaining = malloc(remaining_length + 1);
	if (remaining == NULL)
	{
		free (buffer);
		return (NULL);
	}
	gnlstrcpy(remaining, end_of_line + 1);
	free(buffer);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer[4096];
	char		*line;

	if (fd < 0 && read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer[fd])
	basin_buffer[fd] = ft_gnlcalloc(1, sizeof (char));
	if (!ft_gnlstrchr(basin_buffer[fd], '\n'))
	basin_buffer[fd] = read_from_file(basin_buffer[fd], fd);
	if (!basin_buffer[fd])
	{
		free(basin_buffer[fd]);
		basin_buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(basin_buffer[fd]);
	basin_buffer[fd] = obtain_remaining(basin_buffer[fd]);
	return (line);
}

/*int main(int argc, char **argv)
{
    int		fd[4096];
    char	*line;
    int		i;
    int		j;
    if	(argc == 1)
        fd[0] = 0;
	else
	{
        i = 1;
		while (i < argc)
		{
            fd[i - 1] = open(argv[i], O_RDONLY);
			if (fd[i - 1] == -1)
		{
			write (2, "Error: File not open.\n", 23);
			return (-1);
		}
			i++;
		}
	}
    j = 0;
	while (j < argc - 1)
	{
        line = get_next_line(fd[j]);
		if (line)
		printf("*line: %s\n", line);
		free (line);
		while (line)
		{
            line = get_next_line(fd[j]);
			if (line)
			printf("*line: %s\n", line);
			free (line);
		}
		close (fd[j]);
        j++;
	}
	//system("leaks a.out");
	return (0);
}*/
