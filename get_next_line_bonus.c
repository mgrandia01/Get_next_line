/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 08:43:54 by mgrandia          #+#    #+#             */
/*   Updated: 2025/02/19 18:08:11 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_buffer(int fd, char *left, int flag)
{
	int		n_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(left);
		return (NULL);
	}
	n_read = read(fd, buffer, BUFFER_SIZE);
	if (n_read <= 0)
	{
		free(buffer);
		if (n_read == 0 && left != NULL && flag == 0)
			return (left);
		free(left);
		return (NULL);
	}
	buffer[n_read] = '\0';
	if (left != NULL)
		left = ft_strjoin(left, buffer);
	else
		left = ft_strdup(buffer);
	free(buffer);
	return (left);
}

int	ft_process_no_newline(char **left, char **line, int fd, int flag)
{
	*left = ft_buffer(fd, *left, flag);
	if (*left)
	{
		if (*line)
			free(*line);
		*line = ft_strdup(*left);
		return (1);
	}
	if (!*left)
		return (-1);
	return (0);
}

void	ft_process_with_newline(char **left, int i)
{
	char	*tmp;

	tmp = ft_strdup(*left);
	free(*left);
	*left = ft_memcpy(tmp + i + 1, ft_strlen(tmp) - i);
	if (*left && (*left)[0] == '\0')
	{
		free(*left);
		*left = NULL;
	}
	free(tmp);
}

static int	process_buffer(char **left, char **line, int fd, int flag)
{
	int	i;

	i = -1;
	if (*left != NULL)
	{
		i = ft_index_memchar(*left, '\n', ft_strlen(*left));
		if (i == -1 && flag == 0)
		{
			ft_process_no_newline(left, line, fd, flag);
			i = ft_index_memchar(*left, '\n', ft_strlen(*left));
		}
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*left[1024];
	char		*line;
	int			i;
	int			flag;

	line = NULL;
	flag = 0;
	while (1)
	{
		i = process_buffer(&left[fd], &line, fd, flag);
		if (i < 0)
		{
			flag = 1;
			if (ft_process_no_newline(&left[fd], &line, fd, flag) == -1)
				return (line);
		}
		else
		{
			if (line)
				free(line);
			line = ft_memcpy(left[fd], i + 1);
			ft_process_with_newline(&left[fd], i);
			return (line);
		}
	}
}
