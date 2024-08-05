/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:43:15 by belamiqu          #+#    #+#             */
/*   Updated: 2023/11/09 16:53:33 by belamiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_gnlstrlen(const char *str);
char	*ft_gnlstrchr(const char *str, int c);
char	*ft_gnlstrjoin(const char *s1, const char *s2);
void	*ft_gnlcalloc(size_t nitems, size_t size);
char	*gnlstrcpy(char *dest, const char *src);
#endif