/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:01:32 by belamiqu          #+#    #+#             */
/*   Updated: 2023/11/17 17:44:13 by belamiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int main (void)
{
int fd;
//char *line;
int byte;
char buf[BUFFER_SIZE + 1];

fd = open ("1char.txt", O_RDONLY);
if (fd < 0)
	{
		perror("Error al  abrir el archivo");
		return (1);
	}

byte = 1;
while (1)
{
byte = read(fd, buf, BUFFER_SIZE);
		if (byte <= 0)
			return (0);
		buf[byte] = '\0';
		printf ("%s", &buf[0]);
	}
    close(fd);
    return (0);
}*/

/*int main (void)

{
	int fd;
	char *line;
	int count;

	count = 0;
	fd = open("parejas.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	//while(1)
	//{
	//line = get_next_line(fd);
	line = read_first_line_from_file(fd);
	if(line == NULL)
		return(1);
	count++;
	printf("line[%d]:%s\n",count, line);
	free(line);
	line = NULL;
	//}
	close(fd);
	// system ("leaks a.out");
	return(0);
}*/
/*int main(int argc, char **argv)
{
	int fd;
	char *line;
	
	fd = 0;

	if (argc > 1)
	{
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
          	perror("Error al abrir el archivo");
           	return (1);
        }
    }
    else
    {
		printf("No se proporcionó un archivo.\n");
       	return (2); 
    }
	(void) argc;
	(void) argv;
    int i = 0;
	line = get_next_line(fd);
	while (line)
	//while (i < 10)
    {
	    printf("MAIN: %d|%s", i, line);
		//ft_free(&line);
		line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (0);
}*/
/*
int main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	fd1 = open("parejas.txt", O_RDONLY);
	fd2 = open("primavera.txt", O_RDONLY);
	fd3 = open ("multiple_nl.txt", O_RDONLY);
	fd4 = open ("read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while(1)
	{
	line = get_next_line(fd1);
	if(line == NULL)
		break;
	count++;
	printf("line[%d]:%s\n",count, line);
	free(line);
	line = NULL;
	}
	close(fd);
	printf("line[%d]:%s\n",count, line);
//	system ("leaks a.out");
	return(0);
}*/