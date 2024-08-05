/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:45:06 by belamiqu          #+#    #+#             */
/*   Updated: 2023/11/09 17:06:17 by belamiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnlstrlen(const char *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (0);
	while (str[l])
		l++;
	return (l);
}

char	*ft_gnlstrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{	
		if (str[i] == (unsigned char)c)
			return ((char *) s + i);
	i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *) s + i);
	return (NULL);
}

char	*ft_gnlstrjoin(const char *s1, const char *s2)
{
	int		i;
	char	*result;
	size_t	len;

	len = ft_gnlstrlen(s1) + ft_gnlstrlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = 0;
	return (result);
}

void	*ft_gnlcalloc(size_t nitems, size_t size)
{
	void	*p;
	size_t	i;

	p = malloc(nitems * size);
	if (!p)
		return (0);
	i = 0;
	while (i < nitems * size)
	{
		*((unsigned char *)(p + i)) = (unsigned char)0;
		i++;
	}
	return (p);
}

char	*gnlstrcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
