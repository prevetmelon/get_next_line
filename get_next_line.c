/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 23:06:45 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/23 05:36:54 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_check_remain(char *kek, char **remain)
{
	if (kek || *remain)
		return (1);
	else
	{
		free(*remain);
		*remain = NULL;
		return (0);
	}
}

static void		*read_remain(char **line, char **remain)
{
	char		*ptr_remain;
	char		*tmp;

	ptr_remain = NULL;
	*line = ft_strdup("");
	if (*remain != NULL)
	{
		if ((ptr_remain = ft_strchr(*remain, '\n')) != NULL)
		{
			*ptr_remain = '\0';
			tmp = *line;
			*line = ft_strjoin(*line, *remain);
			free(tmp);
			tmp = *remain;
			*remain = ft_strdup(++ptr_remain);
			free(tmp);
			return (ptr_remain);
		}
		tmp = *line;
		*line = ft_strdup(*remain);
		free(tmp);
		free(*remain);
		*remain = NULL;
	}
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	int			read_val;
	static char	*remain;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	char		*kek;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) == -1)
		return (-1);
	kek = NULL;
	kek = read_remain(line, &remain);
	while (!kek && (read_val = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_val] = '\0';
		if ((kek = ft_strchr(buf, '\n')))
		{
			*kek = '\0';
			kek++;
			remain = ft_strdup(kek);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (ft_check_remain(kek, &remain));
}
