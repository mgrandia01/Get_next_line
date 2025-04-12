/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 08:44:05 by mgrandia          #+#    #+#             */
/*   Updated: 2025/02/19 18:02:50 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

//ft_memcpy: copia n bytes de memoria desde la fuente al destino
//ft_index_memchar: retorna el indice donde se encuentra \n
//ft_strlen: retorna la longitud d'un string
//ft_strjoin: concatena dos strings
char	*ft_memcpy(char *src, size_t n)
{
	size_t			i;
	char			*ptr;

	i = 0;
	if (src == NULL && n != 0)
		return (NULL);
	ptr = (char *) malloc((n + 1) * (sizeof(char)));
	if (!ptr)
		return (NULL);
	while (i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_index_memchar(char *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	else
	{
		while (i < ft_strlen(s1))
		{
			ptr[i] = s1[i];
			i ++;
		}
		while ((i + j) < (ft_strlen(s1) + ft_strlen(s2)))
		{
			ptr[i + j] = s2[j];
			j ++;
		}
		ptr[i + j] = '\0';
	}
	free(s1);
	return (ptr);
}

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*ptr;

	if (!s)
	{
		ptr = (char *) malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	len = ft_strlen(s);
	ptr = (char *) malloc((len + 1) * (sizeof(char)));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}
