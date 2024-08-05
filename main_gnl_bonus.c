/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:55:16 by belamiqu          #+#    #+#             */
/*   Updated: 2023/11/17 17:49:44 by belamiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*int main(int argc, char **argv)
{
    int             fd[4096];
    char            *line;
    int             i;
    int             j;
    if (argc == 1)
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
